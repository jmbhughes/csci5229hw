/*
 * Simple 3x3 matrix class
 */

#ifndef HW3NEW_MATRIX3D_H
#define HW3NEW_MATRIX3D_H
#include "Vector3D.h"
#include <iostream>

class Matrix3D {
private:
    double elements[9]; // row major order such that elements[0:2] (inclusive) are the first row vector
    friend std::ostream& operator<<(std::ostream&, const Matrix3D&);

public:
    // create a zero matrix
    Matrix3D();

    // create a customized matrix from an array, elements are in row major order
    explicit Matrix3D(double elements[9]);

    /*
     * Create a customized matrix from vectors, if axis=0 then row vectors and axis=1 then column vectors
     */
    Matrix3D(Vector3D vectors[3], int axis);

    /*
     * Multiply two matrices and return the product
     */
    Matrix3D multiply(Matrix3D other);

    /*
     * If axis=0 then gets the 'entry' row, entry=1 then returns first row
     * If axis=1 then gets the 'entry' column, entry=1 then returns index first column
     * NOTE: uses matrix coordinates instead of array so it is one-indexed
     */
    Vector3D get(int entry, int axis);
};
#endif //HW3NEW_MATRIX3D_H