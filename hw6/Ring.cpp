//
// Created by marcus on 9/26/18.
//

#include "Ring.h"
#include "Definitions.h"
#include <cmath>

extern unsigned texture[];

Ring::Ring(double cx, double cy, double cz, double radius, double thickness):
    cx(cx), cy(cy), cz(cz), radius(radius), thickness(thickness) {}

void Ring::draw() {
    float yellow[] = {1,1,0,1};
    float black[] = {0,0,0,1};
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,16);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,yellow);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);

    const int num_sections = 100;
    const double angle_step = 2 * M_PI / num_sections;

    glBindTexture(GL_TEXTURE_2D, texture[9]); // bind tie dy texture
    glPushMatrix();
    glTranslated(cx, cy, cz);
    for (int i=0; i <= num_sections; i+=1) {
        double angle = i * angle_step;
        glBegin(GL_QUAD_STRIP);

        // front face
        glColor3d(0.3, 0.49, 0.71);
        glNormal3d(0, 0, -1);
        glTexCoord2f(radius * cos(angle),
                   radius * sin(angle));
        glVertex3d(radius * cos(angle),
                radius * sin(angle),
                0.0);

        glNormal3d(0, 0, -1);
        glTexCoord2f(radius * cos(angle + angle_step),
                   radius * sin(angle + angle_step));
        glVertex3d(radius * cos(angle + angle_step),
                radius * sin(angle + angle_step),
                0.0);

        glNormal3d(0, 0, -1);
        glTexCoord2f((radius + thickness) * cos(angle),
                   (radius + thickness) * sin(angle));
        glVertex3d((radius + thickness) * cos(angle),
                (radius + thickness) * sin(angle),
                0.0);

        glNormal3d(0, 0, -1);
        glTexCoord2f((radius + thickness) * cos(angle + angle_step),
                   (radius + thickness) * sin(angle + angle_step));
        glVertex3d((radius + thickness) * cos(angle + angle_step),
                (radius + thickness) * sin(angle + angle_step),
                0.0);

        // top face
        glNormal3d((radius + thickness) * cos(angle),
                   (radius + thickness) * sin(angle),
                   0);
        glTexCoord2f((radius + thickness) * cos(angle), 0);
        glVertex3d((radius + thickness) * cos(angle),
                   (radius + thickness) * sin(angle),
                   0.0);

        glNormal3d((radius + thickness) * cos(angle + angle_step),
                   (radius + thickness) * sin(angle + angle_step),
                   0);
        glTexCoord2f((radius + thickness) * cos(angle + angle_step), 0);
        glVertex3d((radius + thickness) * cos(angle + angle_step),
                   (radius + thickness) * sin(angle + angle_step),
                   0.0);

        glNormal3d((radius + thickness) * cos(angle),
                (radius + thickness) * sin(angle),
                0);
        glTexCoord2f((radius + thickness) * cos(angle), thickness);
        glVertex3d((radius + thickness) * cos(angle),
                (radius + thickness) * sin(angle),
                thickness);


        glNormal3d((radius + thickness) * cos(angle + angle_step),
                (radius + thickness) * sin(angle + angle_step),
                0);
        glTexCoord2f((radius + thickness) * cos(angle + angle_step),
                   thickness);
        glVertex3d((radius + thickness) * cos(angle + angle_step),
                (radius + thickness) * sin(angle + angle_step),
                thickness);

        // back face
        glNormal3d(0, 0, 1);

        glTexCoord2f((radius + thickness) * cos(angle),
                   (radius + thickness) * sin(angle));
        glVertex3d((radius + thickness) * cos(angle),
                   (radius + thickness) * sin(angle),
                   thickness);

        glNormal3d(0, 0, 1);
        glTexCoord2f((radius + thickness) * cos(angle + angle_step),
                   (radius + thickness) * sin(angle + angle_step));

        glVertex3d((radius + thickness) * cos(angle + angle_step),
                   (radius + thickness) * sin(angle + angle_step),
                   thickness);

        glNormal3d(0, 0, 1);
        glTexCoord2f(radius * cos(angle),
                   radius * sin(angle));
        glVertex3d(radius * cos(angle),
                   radius * sin(angle),
                   thickness);

        glNormal3d(0, 0, 1);
        glTexCoord2f(radius * cos(angle + angle_step),
                   radius * sin(angle + angle_step));
        glVertex3d(radius * cos(angle + angle_step),
                   radius * sin(angle + angle_step),
                   thickness);

        // bottom face
        glNormal3d(-radius * cos(angle),
                   -radius * sin(angle),
                   0);
        glTexCoord2f(radius * cos(angle),
                   thickness);
        glVertex3d(radius * cos(angle),
                   radius * sin(angle),
                   thickness);


        glNormal3d(-radius * cos(angle + angle_step),
                   -radius * sin(angle + angle_step),
                   0.0);
        glTexCoord2f(radius * cos(angle + angle_step),
                   thickness);
        glVertex3d(radius * cos(angle + angle_step),
                   radius * sin(angle + angle_step),
                   thickness);

        glNormal3d(-radius * cos(angle),
                   -radius * sin(angle),
                   0);
        glTexCoord2f(radius * cos(angle),
                   0.0);
        glVertex3d(radius * cos(angle),
                   radius * sin(angle),
                   0.0);


        glNormal3d(-radius * cos(angle + angle_step),
                   -radius * sin(angle + angle_step),
                   0.0);
        glTexCoord2f(radius * cos(angle + angle_step),
                   0.0);
        glVertex3d(radius * cos(angle + angle_step),
                   radius * sin(angle + angle_step),
                   0.0);
        glEnd();
    }
    glPopMatrix();
}