#include "Mug.h"
#include "Definitions.h"
#include "Cylinder.h"

Mug::Mug(double cx, double cy, double cz, double height, double radius,
        double rx, double ry, double rz): cx(cx), cy(cy), cz(cz), height(height),
        radius(radius), rx(rx), ry(ry), rz(rz) {}

Mug::Mug(double cx, double cy, double cz, double height, double radius,
         double rx, double ry, double rz,
         double base_color[3], double side_color[3], double inside_color[3],
         double top_color[3], double handle_color[3]): cx(cx), cy(cy), cz(cz), height(height),
                                           radius(radius), rx(rx), ry(ry), rz(rz) {
    for (int i = 0; i < 3; i++) {
        this->base_color[i] = base_color[i];
        this->side_color[i] = side_color[i];
        this->inside_color[i] = inside_color[i];
        this->top_color[i] = top_color[i];
        this->handle_color[i] = handle_color[i];
    }
}

void Mug::draw() {
    float white[] = {1,1,1,1};
    float black[] = {0,0,0,1};
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,64);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);

    glPushMatrix();
    glTranslated(cx, cy, cz);
    glRotated(rx,1,0,0);
    glRotated(ry,0,1,0);
    glRotated(rz,0,0,1);
    glScaled(radius, radius, height);

   const int num_sections = 100;

    // draw base
    Cylinder c = Cylinder(0, 0, 0, 1, 0.1, 0, 0, base_color, base_color, side_color);
    c.draw();


    // draw outside
    glColor3dv(side_color);
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= num_sections; i++) {
        glNormal3d(cos((i+0.0)/num_sections * 2 * M_PI),
                   sin((i+0.0)/num_sections * 2 * M_PI),
                   0);
        glVertex3d(cos((i+0.0)/num_sections * 2 * M_PI),
                   sin((i+0.0)/num_sections * 2 * M_PI),
                   0);
        glNormal3d(cos((i+0.0)/num_sections * 2 * M_PI),
                   sin((i+0.0)/num_sections * 2 * M_PI),
                   1.0);
        glVertex3d(cos((i+0.0)/num_sections * 2 * M_PI),
                   sin((i+0.0)/num_sections * 2 * M_PI),
                   1.0);
    }
    glEnd();

    // draw inside
    glColor3dv(inside_color);
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= num_sections; i++) {
        glNormal3d(-0.9*cos((i+0.0)/num_sections * 2 * M_PI),
                   -0.9*sin((i+0.0)/num_sections * 2 * M_PI),
                   0);
        glVertex3d(0.9*cos((i+0.0)/num_sections * 2 * M_PI),
                   0.9*sin((i+0.0)/num_sections * 2 * M_PI),
                   0);
        glNormal3d(-0.9*cos((i+0.0)/num_sections * 2 * M_PI),
                   -0.9*sin((i+0.0)/num_sections * 2 * M_PI),
                   -1.0);
        glVertex3d(0.9*cos((i+0.0)/num_sections * 2 * M_PI),
                   0.9*sin((i+0.0)/num_sections * 2 * M_PI),
                   1.0);
    }
    glEnd();

    // draw top
    glColor3dv(top_color);
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= num_sections; i++) {
        glNormal3d(0, 0, 1);
        glVertex3d(cos((i+0.0)/num_sections * 2 * M_PI),
                   sin((i+0.0)/num_sections * 2 * M_PI),
                   1.0);
        glNormal3d(0, 1, 0);
        glVertex3d(0.9*cos((i+0.0)/num_sections * 2 * M_PI),
                   0.9*sin((i+0.0)/num_sections * 2 * M_PI),
                   1.0);
    }
    glEnd();

    // draw handle in four parts
    glColor3dv(handle_color);
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= num_sections; i++) {
        glNormal3d(-1, 0, 0);
        glVertex3d(0.0,
                   0.5*sin((i+0.0)/num_sections * M_PI) + 1,
                   0.5*cos((i+0.0)/num_sections * M_PI) + 0.5);
        glNormal3d(-1, 0, 0);
        glVertex3d(0.0,
                   0.5*0.9*sin((i+0.0)/num_sections * M_PI) + 1,
                   0.5*0.9*cos((i+0.0)/num_sections * M_PI) + 0.5);
    }
    glEnd();

    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= num_sections; i++) {
        glNormal3d(1, 0, 0);
        glVertex3d(0.1,
                   0.5*sin((i+0.0)/num_sections * M_PI) + 1,
                   0.5*cos((i+0.0)/num_sections * M_PI) + 0.5);
        glNormal3d(1, 0, 0);
        glVertex3d(0.1,
                   0.5*0.9*sin((i+0.0)/num_sections * M_PI) + 1,
                   0.5*0.9*cos((i+0.0)/num_sections * M_PI) + 0.5);
    }
    glEnd();

    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= num_sections; i++) {
        glNormal3d(0,
                   0.5*sin((i+0.0)/num_sections * M_PI),
                   0.5*cos((i+0.0)/num_sections * M_PI));
        glVertex3d(0.1,
                   0.5*sin((i+0.0)/num_sections * M_PI) + 1,
                   0.5*cos((i+0.0)/num_sections * M_PI) + 0.5);
        glNormal3d(0.0,
                   0.5*sin((i+0.0)/num_sections * M_PI),
                   0.5*cos((i+0.0)/num_sections * M_PI));
        glVertex3d(0.0,
                   0.5*sin((i+0.0)/num_sections * M_PI) + 1,
                   0.5*cos((i+0.0)/num_sections * M_PI) + 0.5);
    }
    glEnd();

    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= num_sections; i++) {
        glNormal3d(0,
                   -0.5*0.9*sin((i+0.0)/num_sections * M_PI),
                   -0.5*0.9*cos((i+0.0)/num_sections * M_PI));
        glVertex3d(0.1,
                   0.5*0.9*sin((i+0.0)/num_sections * M_PI) + 1,
                   0.5*0.9*cos((i+0.0)/num_sections * M_PI) + 0.5);
        glNormal3d(0.0,
                   -0.5*0.9*sin((i+0.0)/num_sections * M_PI),
                   -0.5*0.9*cos((i+0.0)/num_sections * M_PI));
        glVertex3d(0.0,
                   0.5*0.9*sin((i+0.0)/num_sections * M_PI) + 1,
                   0.5*0.9*cos((i+0.0)/num_sections * M_PI) + 0.5);
    }
    glEnd();
    glPopMatrix();
}
