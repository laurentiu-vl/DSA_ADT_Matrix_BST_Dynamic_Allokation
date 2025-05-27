#include <assert.h>
#include <iostream>
#include <ostream>

#include "Matrix.h"

using namespace std;

void testAll() {
    Matrix m(4, 4);
    assert(m.nrLines() == 4);
    assert(m.nrColumns() == 4);
    m.modify(1, 1, 5);
    assert(m.element(1, 1) == 5);
    m.modify(1, 1, 6);
    assert(m.element(1, 2) == NULL_TELEM);
}

void testAllLaurentiu() {
    Matrix m(4, 4);
    assert(m.nrLines() == 4);
    assert(m.nrColumns() == 4);

    assert(m.element(1, 2) == NULL_TELEM);

    m.modify(1, 1, 4);
    assert(m.element(1, 1) == 4);

    m.modify(1, 2, 7);
    assert(m.element(1, 2) == 7);

    m.modify(2, 2, 10);
    assert(m.element(2, 2) == 10);

    m.modify(1, 1, 0);

    m.modify(1, 2, 0);

    m.modify(2, 2, 231);
}