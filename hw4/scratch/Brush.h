/*
 * A "brush" object that behaves as the Turtle in Turtle graphics.
 */
#ifndef HW3NEW_BRUSH_H
#define HW3NEW_BRUSH_H
#include "Vector3D.h"
#include "Matrix3D.h"

class Brush {
private:
    Vector3D forward_vector; // direction forward
    Vector3D left_vector; // direction to left
    Vector3D up_vector; // direction to up

    // what the current matrix is with [forward_vector, left_vector, up_vector] as columns
    Matrix3D current_matrix();

public:
    // create a default brush going toward x-axis
    Brush();

    // create a customized brush
    Brush(Vector3D forward_vector, Vector3D left_vector, Vector3D up_vector);

    // turn left by angle, in radians
    void turn_left(double angle);

    // turn right by angle, in radians
    void turn_right(double angle);

    // pitch down by angle, in radians
    void pitch_down(double angle);

    // pitch up by angle, in radians
    void pitch_up(double angle);

    // roll left by angle, in radians
    void roll_left(double angle);

    // roll right by angle, in radians
    void roll_right(double angle);

    // turn around 180 degrees
    void turn_around();
};
#endif //HW3NEW_BRUSH_H