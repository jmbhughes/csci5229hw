#include "RectangularPrism.h"
#include "CSCIx229.h"
#include <stdexcept>

RectangularPrism::RectangularPrism(double x, double y, double z,
        double width, double length, double height):
    x(x), y(y), z(z), width(width), length(length), height(height), angle_az(0.0), angle_alt(0.0),
    face_colors{ 1.0, 0.0, 1.0, // magenta bottom
                 1.0, 0.0, 0.0, // red front
                 0.0, 1.0, 0.0, // green right
                 0.0, 0.0, 1.0, // blue back
                 1.0, 1.0, 0.0, // yellow left
                 0.0, 1.0, 1.0} // cyan top
                 {}

RectangularPrism::RectangularPrism(double x, double y, double z,
        double width, double length, double height,
        double angle_az, double angle_alt):
        x(x), y(y), z(z), width(width), length(length), height(height),
        angle_az(angle_az), angle_alt(angle_alt),
        face_colors{ 1.0, 0.0, 1.0, // magenta bottom
                     1.0, 0.0, 0.0, // red front
                     0.0, 1.0, 0.0, // green right
                     0.0, 0.0, 1.0, // blue back
                     1.0, 1.0, 0.0, // yellow left
                     0.0, 1.0, 1.0} // cyan top
                     {}

RectangularPrism::RectangularPrism(double x, double y, double z,
        double width, double length, double height,
        double angle_az, double angle_alt,
        double face_colors[16]):
        x(x), y(y), z(z), width(width), length(length), height(height),
        angle_az(angle_az), angle_alt(angle_alt) {
    for(int i = 0; i < 16; ++i) {
        face_colors[i] = face_colors[i];
    }
}

void RectangularPrism::draw() {
    glPushMatrix();
    glTranslated(x, y, z);
    glRotated(angle_az,1,0,0);
    glRotated(angle_alt,0,1,0);
    glScaled(width, length, height);
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