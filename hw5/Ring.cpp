//
// Created by marcus on 9/26/18.
//

#include "Ring.h"
#include "Definitions.h"
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
        glColor3d(0.047, 0.458, 0.494);
        glNormal3d(0, 0, -1);
        glVertex3d(radius * cos(angle),
                radius * sin(angle),
                0.0);
        glNormal3d(0, 0, -1);

        glVertex3d(radius * cos(angle + angle_step),
                radius * sin(angle + angle_step),
                0.0);
        glNormal3d(0, 0, -1);

        glVertex3d((radius + thickness) * cos(angle),
                (radius + thickness) * sin(angle),
                0.0);
        glNormal3d(0, 0, -1);

        glVertex3d((radius + thickness) * cos(angle + angle_step),
                (radius + thickness) * sin(angle + angle_step),
                0.0);

        // top face
        glNormal3d((radius + thickness) * cos(angle),
                   (radius + thickness) * sin(angle),
                   0);
        glVertex3d((radius + thickness) * cos(angle),
                   (radius + thickness) * sin(angle),
                   0.0);

        glNormal3d((radius + thickness) * cos(angle + angle_step),
                   (radius + thickness) * sin(angle + angle_step),
                   0);

        glVertex3d((radius + thickness) * cos(angle + angle_step),
                   (radius + thickness) * sin(angle + angle_step),
                   0.0);

        glNormal3d((radius + thickness) * cos(angle),
                (radius + thickness) * sin(angle),
                0);
        glVertex3d((radius + thickness) * cos(angle),
                (radius + thickness) * sin(angle),
                thickness);
        glNormal3d((radius + thickness) * cos(angle + angle_step),
                (radius + thickness) * sin(angle + angle_step),
                   0);

        glVertex3d((radius + thickness) * cos(angle + angle_step),
                (radius + thickness) * sin(angle + angle_step),
                thickness);

        // back face
        glNormal3d(0, 0, 1);

        glVertex3d((radius + thickness) * cos(angle),
                   (radius + thickness) * sin(angle),
                   thickness);
        glNormal3d(0, 0, 1);

        glVertex3d((radius + thickness) * cos(angle + angle_step),
                   (radius + thickness) * sin(angle + angle_step),
                   thickness);

        glNormal3d(0, 0, 1);
        glVertex3d(radius * cos(angle),
                   radius * sin(angle),
                   thickness);
        glNormal3d(0, 0, 1);
        glVertex3d(radius * cos(angle + angle_step),
                   radius * sin(angle + angle_step),
                   thickness);

        // bottom face
        glNormal3d(-radius * cos(angle),
                   -radius * sin(angle),
                   0);        glVertex3d(radius * cos(angle),
                   radius * sin(angle),
                   thickness);
        glNormal3d(-radius * cos(angle + angle_step),
                   -radius * sin(angle + angle_step),
                   0.0);
        glVertex3d(radius * cos(angle + angle_step),
                   radius * sin(angle + angle_step),
                   thickness);

        glNormal3d(-radius * cos(angle),
                   -radius * sin(angle),
                   0);
        glVertex3d(radius * cos(angle),
                   radius * sin(angle),
                   0.0);
        glNormal3d(-radius * cos(angle + angle_step),
                   -radius * sin(angle + angle_step),
                   0.0);
        glVertex3d(radius * cos(angle + angle_step),
                   radius * sin(angle + angle_step),
                   0.0);
        glEnd();
    }
    glPopMatrix();
}