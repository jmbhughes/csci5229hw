//
// Created by marcus on 9/25/18.
//

#ifndef HW3NEW_BRUSH_H
#define HW3NEW_BRUSH_H
#include "Vector3D.h"


class Brush {
private:
    Vector3D forward_vector;
    Vector3D left_vector;
    Vector3D up_vector;
public:
    Brush();
    Brush(Vector3D forward_vector, Vector3D left_vector, Vector3D up_vector);
    void turn_left(double angle);
    void turn_right(double angle);
    void pitch_down(double angle);
    void pitch_up(double angle);
    void roll_left(double angle);
    void roll_right(double angle);
    void turn_around();
};


#endif //HW3NEW_BRUSH_H
