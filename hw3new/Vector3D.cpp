/*
 * A very simple three dimensional vector designating a direction in (x,y,z) space.
 * Provides support for creation and accessing components, essentially just a storage structure.
 */

#include "Vector3D.h"
#include <stdexcept>

// Create a zero vector
Vector3D::Vector3D(): x(0.0), y(0.0), z(0.0) {}

// Create a customized vector (x,y,z)
Vector3D::Vector3D(double x, double y, double z): x(x), y(y), z(z) {}

/*
 * Get the i'th component:
 * i=0: x
 * i=1: y
 * i=2: z
 */
double Vector3D::get(int i) {
    if (i==0)
        return x;
    else if (i==1)
        return y;
    else if (i==2)
        return z;
    else
        throw std::out_of_range("Too many faces specified in RectangularPrism draw.");
}
