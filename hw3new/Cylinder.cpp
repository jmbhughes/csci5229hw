//
// Created by marcus on 9/25/18.
//

#include "Cylinder.h"
#include "Circle.h"
#include <math.h>
#include "CSCIx229.h"

Cylinder::Cylinder(float radius, float height) : radius(radius), height(height) {}

float Cylinder::get_radius(){return radius;}
float Cylinder::get_height(){return height;}

void Cylinder::draw() {
    glPushMatrix();
    Circle base = Circle(radius);
    glColor3d(0, 0, 1);
    base.draw();

    int numSections = 100;
    double thetaStep = 2 * M_PI / numSections;
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= numSections; i++) {
        glColor3d(0, (i+0.0)/numSections, 1.0-(i+0.0)/numSections);
        glVertex3d(radius * cos(i * thetaStep), radius * sin(i * thetaStep), 0);
        glVertex3d(radius * cos(i * thetaStep), radius * sin(i * thetaStep), height);
    }
    glEnd();
    glTranslatef(0, 0, height);
    glColor3d(1, 0, 0);
    base.draw();
    glPopMatrix();
}