//
// Created by marcus on 9/25/18.
//

#include "Matrix3D.h"
#include <stdexcept>

Matrix3D::Matrix3D(): elements{0.0, 0.0, 0.0,
                               0.0, 0.0, 0.0,
                               0.0, 0.0, 0.0} {}

Matrix3D::Matrix3D(double elements[9]) {
    // initialize the elements
    for(int i = 0; i < 9; ++i) {
        this->elements[i] = elements[i];
    }
}

Matrix3D::Matrix3D(Vector3D vectors[3], int axis) {
    switch(axis) {
        case 0: // row vectors
            for(int i = 0; i < 3; ++i) {
                for(int j = 0; j < 3; ++j){
                    elements[i*3+j] = vectors[i].get(j);
                }
            }
            break;
        case 1: // column vectors
            for(int i = 0; i < 3; ++i) {
                for(int j = 0; j < 3; ++j){
                    elements[i*3+j] = vectors[j].get(i);
                }
            }
            break;
        default:
            throw std::out_of_range("axis can only be 0 for row vectors or 1 for column vectors");
    }
}

Vector3D Matrix3D::get(int entry,  int axis) {
    entry -= 1; // convert from matrix (one-indexed) coordinates to array (zero-indexed) coordinates
    double out[3]; // temporarily store contents

    if (axis == 0) { // row
        for (int i=0; i<3; ++i){
            out[i] = elements[entry*3 + i];
        }
    } else if (axis == 1) { // column
        for (int i = 0; i<3; i++) {
            out[i] = elements[entry + i*3];
        }
    } else { // axis != 0 and axis != 1
        throw std::out_of_range("Too many faces specified in RectangularPrism draw.");
    }
    return {out[0], out[1], out[2]};
}

Matrix3D Matrix3D::multiply(Matrix3D other) {
    Matrix3D out = Matrix3D();
    // perform simple O(n^3) product
    for(int i=0; i<3; ++i) {
        for(int j=0; j<3; ++j) {
            double sum = 0.0;
            for (int k=0; k<3; ++k) {
                sum += elements[i*3+k] * other.elements[k*3+j];
            }
            out.elements[i*3+j]=sum;
        }
    }
    return out;
}

std::ostream& operator<<(std::ostream &strm, const Matrix3D &matrix) {
    strm << "Matrix3D(";
    for (int i=0; i<9; ++i) {
        if (i != 8)
            strm << matrix.elements[i] << ",";
        else
            strm << matrix.elements[i];
    }
    strm << ")";
    return strm;
}