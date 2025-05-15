#pragma once

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM 0

class Matrix {

struct BSTNode {
    TElem info;
    BSTNode *leftC;
    BSTNode *rightC;
    BSTNode *parent;
    int row;
    int col;
};

private:
    //ADT Matrix – repräsentiert als schwachbesetzte Matrix (sparse) mit Tupeln der Form
    //(Zeile, Spalte, Wert) (Wert ≠ 0), wobei die Tupel in lexikographischen Reihenfolge nach
    //(Zeile, Spalte) in einem BST mit einer verketteten Repräsentierung mit dynamischer
    //Allokation gespeichert werden.

    //TODO - Representation
    int nrOfRow;
    int nrOfCol;
    BSTNode *root;

public:
    //constructor
    Matrix(int nrLines, int nrCols);

    //returns the number of lines
    int nrLines() const;

    //returns the number of columns
    int nrColumns() const;

    //returns the element from line i and column j (indexing starts from 0)
    //throws exception if (i,j) is not a valid position in the Matrix
    TElem element(int i, int j) const;

    //modifies the value from line i and column j
    //returns the previous value from the position
    //throws exception if (i,j) is not a valid position in the Matrix
    TElem modify(int i, int j, TElem e);

    // destructor
    ~Matrix();

};
