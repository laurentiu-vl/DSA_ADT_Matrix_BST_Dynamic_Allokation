#include "Matrix.h"
#include <exception>
#include <stdexcept>
using namespace std;

Matrix::Matrix(int nrLines, int nrCols) {
    //TODO - Implementation

    if (nrLines <= 0 || nrCols <= 0) {
        throw runtime_error("Matrix::Matrix(): Invalid input");
    }

    nrOfCols = nrCols;
    nrOfRows = nrLines;
    root = nullptr;
}


int Matrix::nrLines() const {
    //TODO - Implementation
    //return 0;

    return nrOfRows;
}


int Matrix::nrColumns() const {
    //TODO - Implementation
    //return 0;

    return nrOfCols;
}


TElem Matrix::element(int i, int j) const {
    //TODO - Implementation

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
        if (i == current->row && j < current->col) { //if line=i, check the column for traver to leftC
            current = current->leftC;
        }
        else current = current->rightC; //if i/j bigger
    }
    return NULL_TELEM;
}

TElem Matrix::modify(int i, int j, TElem e) {
    //TODO - Implementation
    return NULL_TELEM;
}

Matrix::~Matrix() {
    //TODO - Implementation
}


