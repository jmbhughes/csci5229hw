//
// Created by marcus on 9/25/18.
//

#include "Circle.h"
#include <math.h>
#include "CSCIx229.h"
#include <iostream>

Circle::Circle(double radius):
    cx(0.0), cy(0.0), cz(0.0), radius(radius), angle_alt(0.0), angle_az(0.0), color{0.0, 0.0, 1.0} {}

Circle::Circle(double cx, double cy, double cz, double radius):
    cx(cx), cy(cy), cz(cz), radius(radius), angle_alt(0.0), angle_az(0.0), color{0.0, 0.0, 1.0} {}

Circle::Circle(double cx, double cy, double cz, double radius, double angle_alt, double angle_az):
    cx(cx), cy(cy), cz(cz), radius(radius),
    angle_alt(angle_alt), angle_az(angle_az), color{0.0, 0.0, 1.0} {}

Circle::Circle(double cx, double cy, double cz, double radius,
        double angle_alt, double angle_az, double color[3]):
    cx(cx), cy(cy), cz(cz), radius(radius),
    angle_alt(angle_alt), angle_az(angle_az) {
    for (int i = 0; i < 3; i++)
        this->color[i] = color[i];
}

void Circle::draw() {
    // discretize the circle into chunks
    const int num_sections = 100;
    double angle_step = 2 * M_PI / num_sections;

    // adjust world
    glPushMatrix();
    glTranslated(cx, cy, cz);
    glRotated(angle_az,1,0,0);
    glRotated(angle_alt,0,1,0);

    glBegin(GL_TRIANGLE_FAN);
    glColor3dv(color);
    // draw center
    glVertex2f(0,0);

    // establish circle perimeter points
    for (int section = 0; section <= num_sections; ++section) {
        glColor3d(color[0], color[1], color[2]);
        glVertex2d(radius * cos(section * angle_step), radius * sin(section * angle_step));
    }
    glEnd();
    glPopMatrix();
}