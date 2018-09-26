//
// Created by marcus on 9/25/18.
//

#include "Brush.h"

Brush::Brush(): forward_vector{1.0, 0.0, 0.0}, left_vector{0.0, 1.0, 0.0}, up_vector{0.0, 0.0, 1.0} {}

Brush::Brush(Vector3D forward_vector, Vector3D left_vector, Vector3D up_vector):
forward_vector(forward_vector), left_vector(left_vector), up_vector(up_vector) {}

void Brush::turn_around() {

}