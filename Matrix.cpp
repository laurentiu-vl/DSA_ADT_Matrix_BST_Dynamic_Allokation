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

    while (current != nullptr) { //exceptie pt e = 0 este mai sus

        parent = current;
        if (current->row == i && current->col == j) {
            oldInfo = current->info;
            //found = true;
            current->info = e;
            //return oldInfo;
            return oldInfo;
        }
        // if (found == true) {
        //     return oldInfo;
        // }
        if (i < current->row) { //check first the line
            current = current->leftC;
        }
        else if (i == current->row && j < current->col) { //if line=i, check the column for traver to leftC
            current = current->leftC;
        }
        else current = current->rightC; //if i/j bigger
    }

        BSTNode* newNode = new BSTNode();
        newNode->info = e;
        newNode->row = i;
        newNode->col = j;
        newNode->leftC = nullptr;
        newNode->rightC = nullptr;
        newNode->parent = parent;

        if (parent == nullptr) {
            root = newNode;
        } else if (i < parent->row || (i == parent->row && j < parent->col)) {
            parent->leftC = newNode;
        } else {
            parent->rightC = newNode;
        }
    return NULL_TELEM;
}

Matrix::~Matrix() {
    destroyRecursive(root);
}

void Matrix::destroyRecursive(BSTNode *node) {
    if (node) {
        destroyRecursive(node->leftC);
        destroyRecursive(node->rightC);
        delete node;
    }
}


