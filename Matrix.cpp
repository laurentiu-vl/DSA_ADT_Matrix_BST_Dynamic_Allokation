#include "Matrix.h"
#include <exception>
#include <iostream>
#include <ostream>
#include <stdexcept>
using namespace std;

Matrix::Matrix(int nrLines, int nrCols) {
    if (nrLines <= 0 || nrCols <= 0) {
        throw runtime_error("Matrix::Matrix(): Invalid input");
    }

    nrOfCols = nrCols;
    nrOfRows = nrLines;
    root = nullptr;
    //parent  = nullptr;
}

int Matrix::nrLines() const {
    return nrOfRows;
}

int Matrix::nrColumns() const {
    return nrOfCols;
}

TElem Matrix::element(int i, int j) const {
    if (i < 0 || j < 0 || i >= nrOfRows || j >= nrOfCols) {
        throw runtime_error("Matrix::element(): Invalid input");
    }

    if (nrOfRows <= 0 || nrOfCols <= 0) {
        throw runtime_error("Matrix::element(): Invalid input");
    }

    BSTNode *parent = nullptr;
    BSTNode *current = root;

    while (current != nullptr) {
        if (current->row == i && current->col == j) { //if elem found
            return current->info;
        }
        if (i < current->row) { //check first the line
            current = current->leftC;
        }
        else if (i == current->row && j < current->col) { //if line=i, check the column for traver to leftC
            current = current->leftC;
        }
        else current = current->rightC; //if i/j bigger
    }
    return NULL_TELEM;
}

TElem Matrix::modify(int i, int j, TElem e) {
    if (i < 0 || j < 0 || i >= nrOfRows || j >= nrOfCols) {
        throw runtime_error("Matrix::modify(): Invalid input");
    }

    if (nrOfRows <= 0 || nrOfCols <= 0) {
        throw runtime_error("Matrix::modify(): Invalid input");
    }

    // if (e == NULL_TELEM) {
    //     std::cerr << "Matrix::modify(): Invalid input" << std::endl;
    //     return e;
    // }

    BSTNode *parent = nullptr;
    BSTNode *current = root;
    TElem oldInfo;
    bool found = false;

    while (current != nullptr) { //while for searching the elem to be modified

        parent = current;
        if (current->row == i && current->col == j) { //if elem i, j found
            oldInfo = current->info;

            if (e == NULL_TELEM) { //condition for e NULL
                root = deleteNode(root, i, j); //call for delete and return oldInfo
                return oldInfo;
            }

            //found = true;
            current->info = e; //if e not NULL, modify the elem in bst
            //return oldInfo;
            return oldInfo;
        }
        // if (found == true) {
        //     return oldInfo;
        // }

        //iteration through bst to find the elem i, j
        if (i < current->row) { //check first the line
            current = current->leftC;
        }
        else if (i == current->row && j < current->col) { //if line=i, check the column for traver to leftC
            current = current->leftC;
        }
        else current = current->rightC; //if i/j bigger
    }

    // if (e == NULL_TELEM) {
    //     return NULL_TELEM;
    // }

        //if elem i, j not found in the iteration -> create a node
        BSTNode* newNode = new BSTNode();
        newNode->info = e;
        newNode->row = i;
        newNode->col = j;
        newNode->leftC = nullptr;
        newNode->rightC = nullptr;
        newNode->parent = parent;

        //asign the new node to the correct parent in bst
        if (parent == nullptr) {
            root = newNode;
        } else if (i < parent->row || (i == parent->row && j < parent->col)) { //parent on left side ->
            parent->leftC = newNode;
        } else {
            parent->rightC = newNode; //parent on right side ->
        }
    return NULL_TELEM;
}

Matrix::~Matrix() {
    destroyRecursive(root); //call
}

void Matrix::destroyRecursive(BSTNode *node) {
    if (node) { //if node not null ptr, call again the function
        //and iterate left or right until the last node
        destroyRecursive(node->leftC);
        destroyRecursive(node->rightC);
        delete node;
    }
}

Matrix::BSTNode *Matrix::getSuccessor(BSTNode *node) {
    while (node->leftC != nullptr) {
        node = node->leftC;
    }
    return node;
}

Matrix::BSTNode *Matrix::deleteNode(BSTNode *node, int i, int j) {
    if (node == nullptr) {
        return nullptr;
    }
    if (i < node->row || (i == node->row && j < node->col)) { //check on which side to iterate
        node->leftC = deleteNode(node->leftC, i, j); //call delete()
    }
    else if (i > node->row || (i == node->row && j > node->col)) { //check on which side to iterate
        node->rightC = deleteNode(node->rightC, i, j); //call delete()
    }
    else { //if i, j found
        //case1
        //the found elem i, j has no children
        if (node->leftC == nullptr && node->rightC == nullptr) {
            if (node->parent != nullptr) {
                if (node->parent->leftC == node) { //parent found and check if the node is on left
                    node->parent->leftC = nullptr;
                }
                else {
                    node->parent->rightC = nullptr; //parent found and check if the node is on right
                }
            }
            delete node;
            return nullptr;
        }
        //case2
        //elem i, j has a child -> check if left or right
        if (node->leftC == nullptr) { //-> child on right
            BSTNode *temp = node->rightC;
            temp->parent = node->parent; //new node points at the parent of the deleted node node
            delete node;
            return temp;
        } else if (node->rightC == nullptr) { //-> child on left
            BSTNode *temp = node->leftC;
            temp->parent = node->parent; //new node points at the parent of the deleted node node
            delete node;
            return temp;
        }
        // if (node->rightC == nullptr) {
        //     return node;
        // }
        //case3
        //two children
        BSTNode* successor = getSuccessor(node->rightC);
        node->info = successor->info;
        node->row = successor->row;
        node->col = successor->col;
        node->rightC = deleteNode(node->rightC, successor->row, successor->col);

        // BSTNode* successor = getSuccessor(node->rightC);
        //
        // node->info = successor->info;
        // node->row = successor->row;
        // node->col = successor->col;
        //
        // if (successor->parent->leftC == successor) {
        //     successor->parent->leftC = successor->rightC;
        // } else {
        //     successor->parent->rightC = successor->rightC;
        // }
        // if (successor->rightC != nullptr) {
        //     successor->rightC->parent = successor->parent;
        // }
        // delete successor;
    }
    return node;
}






