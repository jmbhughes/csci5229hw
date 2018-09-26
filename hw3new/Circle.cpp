//
// Created by marcus on 9/25/18.
//

#include "Circle.h"
#include <math.h>
#include "CSCIx229.h"
#include <iostream>

Circle::Circle(float radius): radius(radius) {}

float Circle::get_radius() {
    return radius;
}

void Circle::draw() {
    const int num_sections = 100;
    double angle_step = 2 * M_PI / num_sections;
    glBegin(GL_TRIANGLE_FAN);
    //glColor3f(0.0, 1.0, 1.0);
    glVertex2f(0,0);
    for (int section = 0; section <= num_sections; ++section) {
        glVertex2d(radius * cos(section * angle_step),
                radius * sin(section * angle_step));
    }
    glEnd();
}