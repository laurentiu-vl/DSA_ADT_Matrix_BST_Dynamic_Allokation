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
    return NULL_TELEM;
}

TElem Matrix::modify(int i, int j, TElem e) {
    //TODO - Implementation
    return NULL_TELEM;
}

Matrix::~Matrix() {
    //TODO - Implementation
}


