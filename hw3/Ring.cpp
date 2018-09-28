//
// Created by marcus on 9/26/18.
//

#include "Ring.h"
#include "CSCIx229.h"
#include <cmath>

Ring::Ring(double cx, double cy, double cz, double radius, double thickness):
    cx(cx), cy(cy), cz(cz), radius(radius), thickness(thickness) {}

void Ring::draw() {
    const int num_sections = 100;
    const double angle_step = 2 * M_PI / num_sections;

    glPushMatrix();
    glTranslated(cx, cy, cz);
    for (int i=0; i <= num_sections; i+=1) {
        double angle = i * angle_step;
        glBegin(GL_QUAD_STRIP);

        // front face
        glColor3d(1.0, 0.0, 0.0);
        glVertex3d(radius * cos(angle),
                radius * sin(angle),
                0.0);
        glVertex3d(radius * cos(angle + angle_step),
                radius * sin(angle + angle_step),
                0.0);
        glVertex3d((radius + thickness) * cos(angle),
                (radius + thickness) * sin(angle),
                0.0);
        glVertex3d((radius + thickness) * cos(angle + angle_step),
                (radius + thickness) * sin(angle + angle_step),
                0.0);

        // top face
        glColor3d(0.0, 1.0, 0.0);
        glVertex3d((radius + thickness) * cos(angle),
                (radius + thickness) * sin(angle),
                thickness);
        glVertex3d((radius + thickness) * cos(angle + angle_step),
                (radius + thickness) * sin(angle + angle_step),
                thickness);

        // back face
        glColor3d(0.0, 0.0, 1.0);
        glVertex3d(radius * cos(angle),
                   radius * sin(angle),
                   thickness);
        glVertex3d(radius * cos(angle + angle_step),
                   radius * sin(angle + angle_step),
                   thickness);

        // bottom face
        glColor3d(1.0, 1.0, 1.0);
        glVertex3d(radius * cos(angle),
                   radius * sin(angle),
                   0.0);
        glVertex3d(radius * cos(angle + angle_step),
                   radius * sin(angle + angle_step),
                   0.0);
        glEnd();
    }
    glPopMatrix();
}