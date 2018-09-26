//
// Created by marcus on 9/25/18.
//

#include "Matrix3D.h"
#include <stdexcept>

Matrix3D::Matrix3D(double elements[9]) {
    // initialize the elements
    for(int i = 0; i < 9; ++i) {
        elements[i] = elements[i];
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
            throw std::out_of_range("Too many faces specified in RectangularPrism draw.");
    }
}