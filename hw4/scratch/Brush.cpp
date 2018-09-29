#include "Brush.h"
#include "Matrix3D.h"
#include <cmath>

Brush::Brush(): forward_vector{1.0, 0.0, 0.0}, left_vector{0.0, 1.0, 0.0}, up_vector{0.0, 0.0, 1.0} {}

Brush::Brush(Vector3D forward_vector, Vector3D left_vector, Vector3D up_vector):
    forward_vector(forward_vector), left_vector(left_vector), up_vector(up_vector) {}

Matrix3D Brush::current_matrix() {
    Vector3D elements[3] = {forward_vector, left_vector, up_vector};
    return {elements, 1};
}

void Brush::turn_around() {
    // define transform
    double transform_elements[9] = {-1.0, 0.0, 0.0,
                                    0.0, -1.0, 0.0,
                                    0.0, 0.0, 1.0};
    Matrix3D transform = Matrix3D(transform_elements);

    //apply transform
    Matrix3D new_matrix = current_matrix().multiply(transform);

    // extract new heading
    forward_vector = new_matrix.get(1, 1);
    left_vector = new_matrix.get(2, 1);
    up_vector = new_matrix.get(3, 1);
}

void Brush::turn_left(double angle) {
    // define transform
    double transform_elements[9] = {cos(angle), sin(angle), 0.0,
                                    -sin(angle), cos(angle), 0.0,
                                    0.0, 0.0, 1.0};
    Matrix3D transform = Matrix3D(transform_elements);

    // apply transform
    Matrix3D new_matrix = current_matrix().multiply(transform);

    // extract new heading
    forward_vector = new_matrix.get(1, 1);
    left_vector = new_matrix.get(2, 1);
    up_vector = new_matrix.get(3, 1);
}

void Brush::turn_right(double angle) {
    turn_left(-angle);
}

void Brush::pitch_down(double angle) {
    // define transform
    double transform_elements[9] = {cos(angle), 0.0, -sin(angle),
                                    0.0, 1.0, 0.0,
                                    sin(angle), 0.0, cos(angle)};
    Matrix3D transform = Matrix3D(transform_elements);

    // apply transform
    Matrix3D new_matrix = current_matrix().multiply(transform);

    // extract new heading
    forward_vector = new_matrix.get(1, 1);
    left_vector = new_matrix.get(2, 1);
    up_vector = new_matrix.get(3, 1);
}

void Brush::pitch_up(double angle) {
    pitch_down(-angle);
}

void Brush::roll_left(double angle) {
    // define transform
    double transform_elements[9] = {1.0, 0.0, 0.0,
                                    0.0, cos(angle), -sin(angle),
                                    0.0, sin(angle), cos(angle)};
    Matrix3D transform = Matrix3D(transform_elements);

    // apply tranform
    Matrix3D new_matrix = current_matrix().multiply(transform);

    // extract new heading
    forward_vector = new_matrix.get(1, 1);
    left_vector = new_matrix.get(2, 1);
    up_vector = new_matrix.get(3, 1);
}

void Brush::roll_right(double angle) {
    roll_left(-angle);
}
