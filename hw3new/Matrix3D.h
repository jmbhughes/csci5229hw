//
// Created by marcus on 9/25/18.
//

#ifndef HW3NEW_MATRIX3D_H
#define HW3NEW_MATRIX3D_H
#include "Vector3D.h"

class Matrix3D {
private:
    double elements[9]; // row major order such that elements[0:2] (inclusive) are the first row vector
public:
    Matrix3D(double elements[9]);
    Matrix3D(Vector3D vectors[3], int axis);
};


#endif //HW3NEW_MATRIX3D_H
