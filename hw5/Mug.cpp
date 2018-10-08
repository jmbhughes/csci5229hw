#include "Mug.h"
#include "Definitions.h"

Mug::Mug(double cx, double cy, double cz, double height, double radius,
        double rx, double ry, double rz): cx(cx), cy(cy), cz(cz), height(height),
        radius(radius), rx(rx), ry(ry), rz(rz) {}

void Mug::draw() {
    // convert so bottom center of mug is at origin
    glPushMatrix();
    glTranslated(cx, cy, cz);
    glRotated(rx,1,0,0);
    glRotated(ry,0,1,0);
    glRotated(rz,0,0,1);
    glScaled(radius, radius, height);

    // draw base
    glColor3d(0.1,0.1,0.8);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3d(0, 0, 0);
    const int num_sections = 100;
    for (int i = 0; i <= num_sections; i++) {
        glVertex3d(cos((i+0.0)/num_sections * 2 * M_PI),
                   sin((i+0.0)/num_sections * 2 * M_PI),
                   0);
    }
    glEnd();

    // draw outside
    glColor3d(0.03,0.16,0.40);
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= num_sections; i++) {
        glVertex3d(cos((i+0.0)/num_sections * 2 * M_PI),
                   sin((i+0.0)/num_sections * 2 * M_PI),
                   0);
        glVertex3d(cos((i+0.0)/num_sections * 2 * M_PI),
                   sin((i+0.0)/num_sections * 2 * M_PI),
                   1.0);
    }
    glEnd();

    // draw inside
    glColor3d(0.1,0.1,0.1);
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= num_sections; i++) {
        glVertex3d(0.9*cos((i+0.0)/num_sections * 2 * M_PI),
                   0.9*sin((i+0.0)/num_sections * 2 * M_PI),
                   0);
        glVertex3d(0.9*cos((i+0.0)/num_sections * 2 * M_PI),
                   0.9*sin((i+0.0)/num_sections * 2 * M_PI),
                   1.0);
    }
    glEnd();

    // draw top
    glColor3d(0,1,1);
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= num_sections; i++) {
        glVertex3d(cos((i+0.0)/num_sections * 2 * M_PI),
                   sin((i+0.0)/num_sections * 2 * M_PI),
                   1.0);
        glVertex3d(0.9*cos((i+0.0)/num_sections * 2 * M_PI),
                   0.9*sin((i+0.0)/num_sections * 2 * M_PI),
                   1.0);
    }
    glEnd();

    // draw handle in four parts
    glColor3d(1,1,0);
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= num_sections; i++) {
        glVertex3d(0.0,
                   0.5*sin((i+0.0)/num_sections * M_PI) + 1,
                   0.5*cos((i+0.0)/num_sections * M_PI) + 0.5);
        glVertex3d(0.0,
                   0.5*0.9*sin((i+0.0)/num_sections * M_PI) + 1,
                   0.5*0.9*cos((i+0.0)/num_sections * M_PI) + 0.5);
    }
    glEnd();

    glColor3d(1,1,0);
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= num_sections; i++) {
        glVertex3d(0.1,
                   0.5*sin((i+0.0)/num_sections * M_PI) + 1,
                   0.5*cos((i+0.0)/num_sections * M_PI) + 0.5);
        glVertex3d(0.1,
                   0.5*0.9*sin((i+0.0)/num_sections * M_PI) + 1,
                   0.5*0.9*cos((i+0.0)/num_sections * M_PI) + 0.5);
    }
    glEnd();

    glColor3d(1,1,0);
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= num_sections; i++) {
        glVertex3d(0.1,
                   0.5*sin((i+0.0)/num_sections * M_PI) + 1,
                   0.5*cos((i+0.0)/num_sections * M_PI) + 0.5);
        glVertex3d(0.0,
                   0.5*sin((i+0.0)/num_sections * M_PI) + 1,
                   0.5*cos((i+0.0)/num_sections * M_PI) + 0.5);
    }
    glEnd();

    glColor3d(1,1,0);
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= num_sections; i++) {
        glVertex3d(0.1,
                   0.5*0.9*sin((i+0.0)/num_sections * M_PI) + 1,
                   0.5*0.9*cos((i+0.0)/num_sections * M_PI) + 0.5);
        glVertex3d(0.0,
                   0.5*0.9*sin((i+0.0)/num_sections * M_PI) + 1,
                   0.5*0.9*cos((i+0.0)/num_sections * M_PI) + 0.5);
    }
    glEnd();
    glPopMatrix();
}
