#include "Ball.h"
#include "Definitions.h"

Ball::Ball(double cx, double cy, double cz, double r): cx(cx), cy(cy), cz(cz), r(r) {}

// Draw vertex in polar coordinates with normal
void Ball::vertex(double th, double ph) {
    double x = Sin(th)*Cos(ph);
    double y = Cos(th)*Cos(ph);
    double z =         Sin(ph);
    //  For a sphere at the origin, the position
    //  and normal vectors are the same
    glNormal3d(x,y,z);
    glVertex3d(x,y,z);
}

void Ball::draw(int emission, float shiny) {
    // code borrowed from Schreuder  example 13
    const int inc = 10; // ball increment
    int th,ph;
    float yellow[] = {1.0,1.0,0.0,1.0};
    float Emission[]  = {0.0,0.0,0.01*emission,1.0};
    //  Save transformation
    glPushMatrix();

    //  Offset, scale and rotate
    glTranslated(cx,cy,cz);
    glScaled(r,r,r);

    //  White ball
    glColor3f(1,1,1);
    glMaterialf(GL_FRONT,GL_SHININESS,shiny);
    glMaterialfv(GL_FRONT,GL_SPECULAR,yellow);
    glMaterialfv(GL_FRONT,GL_EMISSION,Emission);
    //  Bands of latitude
    for (ph=-90;ph<90;ph+=inc)
    {
        glBegin(GL_QUAD_STRIP);
        for (th=0;th<=360;th+=2*inc)
        {
            vertex(th,ph);
            vertex(th,ph+inc);
        }
        glEnd();
    }

    //  Undo transformations
    glPopMatrix();
}