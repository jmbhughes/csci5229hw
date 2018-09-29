/*
 * A very simple three dimensional vector designating a direction in (x,y,z) space.
 * Provides support for creation and accessing components, essentially just a storage structure.
 */

#ifndef HW3NEW_VECTOR3D_H
#define HW3NEW_VECTOR3D_H


class Vector3D {
    // state is simply (x,y,z)
private:
    double x;
    double y;
    double z;
public:
    // construct ao zero vector
    Vector3D();

    // construct a customized vector
    Vector3D(double x, double y, double z);

    /*
     * Get the i'th component:
     * i=0: x
     * i=1: y
     * i=2: z
     */
    double get(int i);
};

#endif //HW3NEW_VECTOR3D_H
