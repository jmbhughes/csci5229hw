//
// Created by marcus on 9/25/18.
//

#include "Cylinder.h"
#include "Circle.h"
#include <cmath>
#include "Definitions.h"

Cylinder::Cylinder(double radius, double height) :
    cx(0), cy(0), cz(0), radius(radius), height(height), angle_alt(0.0), angle_az(0.0),
    top_color{0.0, 0.0, 1.0}, bottom_color{1.0, 0.0, 0.0}, column_color{0.0, 1.0, 0.0} {}

Cylinder::Cylinder(double cx, double cy, double cz, double radius, double height) :
    cx(cx), cy(cy), cz(cz), radius(radius), height(height), angle_alt(0.0), angle_az(0.0),
    top_color{0.0, 0.0, 1.0}, bottom_color{1.0, 0.0, 0.0}, column_color{0.0, 1.0, 0.0} {}

Cylinder::Cylinder(double cx, double cy, double cz, double radius, double height,
        double angle_alt, double angle_az) :
    cx(cx), cy(cy), cz(cz), radius(radius), height(height), angle_alt(angle_alt), angle_az(angle_az),
    top_color{0.0, 0.0, 1.0}, bottom_color{1.0, 0.0, 0.0}, column_color{0.0, 1.0, 0.0} {}

Cylinder::Cylinder(double cx, double cy, double cz, double radius, double height,
                   double angle_alt, double angle_az,
                   double top_color[3], double bottom_color[3], double column_color[3]) :
        cx(cx), cy(cy), cz(cz), radius(radius), height(height), angle_alt(angle_alt), angle_az(angle_az) {
    for(int i = 0; i < 3; i++) {
        this->top_color[i] = top_color[i];
        this->bottom_color[i] = bottom_color[i];
        this->column_color[i] = column_color[i];
    }
}

void Cylinder::draw() {
    // adjust so coordinates are at center of cylinder
    const double half_height = height / 2.0;
    glPushMatrix();
    glTranslated(cx, cy, cz);
    glRotated(angle_alt,0,1,0);
    glRotated(angle_az,1,0,0);

    // draw the bottom circle
    Circle bottom = Circle(0.0, 0.0, -half_height, radius, 0.0, 180.0, bottom_color);
    bottom.draw();

    // draw the columns by rectangles connecting top and bottom
    int numSections = 300;
    double thetaStep = 2 * M_PI / numSections;
    glColor3dv(column_color);
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= numSections; i++) {
        glNormal3d(radius * cos(i * thetaStep), radius * sin(i * thetaStep), 0);
        glVertex3d(radius * cos(i * thetaStep), radius * sin(i * thetaStep), -half_height);
        glNormal3d(radius * cos(i * thetaStep), radius * sin(i * thetaStep), 0);
        glVertex3d(radius * cos(i * thetaStep), radius * sin(i * thetaStep), half_height);
    }
    glEnd();

    // draw top surface
    Circle top = Circle(0.0, 0.0, half_height, radius, 0.0, 0.0, top_color);
    top.draw();

    glPopMatrix();
}