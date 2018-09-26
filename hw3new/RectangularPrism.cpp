//
// Created by marcus on 9/25/18.
//

#include "RectangularPrism.h"
#include "CSCIx229.h"
#include <stdexcept>

RectangularPrism::RectangularPrism(double width, double length, double height):
    width(width), length(length), height(height), angle_az(0.0), angle_alt(0.0),
    face_colors{1.0, 0.0, 1.0,
                 1.0, 0.0, 0.0,
                 0.0, 1.0, 0.0,
                 0.0, 0.0, 1.0,
                 1.0, 1.0, 0.0,
                 0.0, 1.0, 1.0} {

}

RectangularPrism::RectangularPrism(double width, double length, double height,
        double angle_az, double angle_alt):
        width(width), length(length), height(height), angle_az(angle_az), angle_alt(angle_alt),
        face_colors{1.0, 0.0, 1.0,
                     1.0, 0.0, 0.0,
                     0.0, 1.0, 0.0,
                     0.0, 0.0, 1.0,
                     1.0, 1.0, 0.0,
                     0.0, 1.0, 1.0} {
}

RectangularPrism::RectangularPrism(double width, double length, double height,
        double angle_az, double angle_alt,
        double face_colors[16]):
        width(width), length(length), height(height), angle_az(angle_az), angle_alt(angle_alt) {
    for(int i = 0; i < 16; ++i) {
        face_colors[i] = face_colors[i];
    }
}

void RectangularPrism::draw() {
    glPushMatrix();
    glScaled(width, length, height);
    glRotated(angle_az,1,0,0);
    glRotated(angle_alt,0,1,0);
    glBegin(GL_QUADS);
    for (int i = 0; i < 6; ++i) {
        glColor3d(face_colors[i*3], face_colors[i*3+1], face_colors[i*3+2]);
        switch(i) {
            case 0: // bottom
                glVertex3d(0, 0, 0);
                glVertex3d(1, 0, 0);
                glVertex3d(1, 0, 1);
                glVertex3d(0, 0, 1);
                break;
            case 1: // front
                glVertex3d(0, 0, 1);
                glVertex3d(0, 1, 1);
                glVertex3d(1, 1, 1);
                glVertex3d(1, 0, 1);
                break;
            case 2: // right side
                glVertex3d(1, 0, 0);
                glVertex3d(1, 1, 0);
                glVertex3d(1, 1, 1);
                glVertex3d(1, 0, 1);
                break;
            case 3: // back side
                glVertex3d(1, 1, 0);
                glVertex3d(0, 1, 0);
                glVertex3d(0, 0, 0);
                glVertex3d(1, 0, 0);
                break;
            case 4: // left side
                glVertex3d(0, 1, 0);
                glVertex3d(0, 1, 1);
                glVertex3d(0, 0, 1);
                glVertex3d(0, 0, 0);
                break;
            case 5: // top side
                glVertex3d(1, 1, 0);
                glVertex3d(0, 1, 0);
                glVertex3d(0, 1, 1);
                glVertex3d(1, 1, 1);
                break;
            default:
                throw std::out_of_range("Too many faces specified in RectangularPrism draw.");
        }
    }
    glEnd();
    glPopMatrix();
}