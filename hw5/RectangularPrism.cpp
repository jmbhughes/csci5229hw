#include "RectangularPrism.h"
#include "Definitions.h"
#include <stdexcept>

RectangularPrism::RectangularPrism(double x, double y, double z,
        double sx, double sy, double sz):
    x(x), y(y), z(z),
    sx(sx), sy(sy), sz(sz),
    rx(0.0), ry(0.0), rz(0.0),
    face_colors{ 0.02, 0.32, 0.07,
                 0.12, 0.42, 0.17,
                 0.02, 0.32, 0.07,
                 0.12, 0.42, 0.17,
                 0.59, 0.37, 0.58,
                 1.0, 0.0, 0.0} // cyan top
                 {}

RectangularPrism::RectangularPrism(double x, double y, double z,
        double sx, double sy, double sz,
        double rx, double ry, double rz):
        x(x), y(y), z(z),
        sx(sx), sy(sy), sz(sz),
        rx(rx), ry(ry), rz(rz),
        face_colors{  0.02, 0.32, 0.07,
                      0.12, 0.42, 0.17,
                      0.02, 0.32, 0.07,
                      0.12, 0.42, 0.17,
                      0.59, 0.37, 0.58,
                      1.0, 0.0, 0.0} // cyan top
                     {}

RectangularPrism::RectangularPrism(double x, double y, double z,
        double sx, double sy, double sz,
        double rx, double ry, double rz,
        double face_colors[18]):
        x(x), y(y), z(z),
        sx(sx), sy(sy), sz(sz),
        rx(rx), ry(ry), rz(rz) {
    for(int i = 0; i < 18; i++) {
        this->face_colors[i] = face_colors[i];
    }
}

void RectangularPrism::draw() {
    float white[] = {1,1,1,1};
    float black[] = {0,0,0,1};
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,8);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);

    glPushMatrix();
    glTranslated(x, y, z);
    glRotated(rx,1,0,0);
    glRotated(ry,0,1,0);
    glRotated(rz,0,0,1);
    glScaled(sx, sy, sz);
    glBegin(GL_QUADS);
    for (int i = 0; i < 6; ++i) {
        glColor3d(face_colors[i*3], face_colors[i*3+1], face_colors[i*3+2]);
        switch(i) {
            case 0: // bottom
                glNormal3d(0, -1, 0);
                glVertex3d(0, 0, 0);
                glVertex3d(1, 0, 0);
                glVertex3d(1, 0, 1);
                glVertex3d(0, 0, 1);
                break;
            case 1: // front
                glNormal3d(0, 0, 1);
                glVertex3d(0, 0, 1);
                glVertex3d(0, 1, 1);
                glVertex3d(1, 1, 1);
                glVertex3d(1, 0, 1);
                break;
            case 2: // right side
                glNormal3d(1, 0, 0);
                glVertex3d(1, 0, 0);
                glVertex3d(1, 1, 0);
                glVertex3d(1, 1, 1);
                glVertex3d(1, 0, 1);
                break;
            case 3: // back side
                glNormal3d(0, 0, -1);
                glVertex3d(1, 1, 0);
                glVertex3d(0, 1, 0);
                glVertex3d(0, 0, 0);
                glVertex3d(1, 0, 0);
                break;
            case 4: // left side
                glNormal3d(-1, 0, 0);
                glVertex3d(0, 1, 0);
                glVertex3d(0, 1, 1);
                glVertex3d(0, 0, 1);
                glVertex3d(0, 0, 0);
                break;
            case 5: // top side
                glNormal3d(0, 1, 0);
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