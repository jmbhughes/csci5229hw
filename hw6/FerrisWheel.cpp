#include "Definitions.h"
#include "FerrisWheel.h"
#include "Ring.h"
#include "Cylinder.h"
#include "RectangularPrism.h"

extern unsigned texture[];

FerrisWheel::FerrisWheel(double cx, double cy, double cz, double scale):
    cx(cx), cy(cy), cz(cz), scale(scale){}

void FerrisWheel::draw_support() {
    const double hub_radius = 0.1;
    const double hub_height = 0.05;

    double colors[18] = {0.362, 0.452, 0.554,
                         0.362, 0.452, 0.554,
                         0.362, 0.452, 0.554,
                         0.362, 0.452, 0.554,
                         0.362, 0.452, 0.554,
                         0.362, 0.452, 0.554};
    RectangularPrism r = RectangularPrism(-1.5, -1.2, -0.25, 3, 0.5, 0.1, 90, 0, 0, colors);
    r.draw();

    r = RectangularPrism(-1.5, -1.2, -0.25, 2.0, 0.09, 0.1, 90, 40, 0, colors);
    r.draw();

    r = RectangularPrism(-1.5, -1.2, 0.15, 2.0, 0.09, 0.1, 90, 40, 0, colors);
    r.draw();

    glPushMatrix();
    glRotated(100, 0, 0, 1);
    r = RectangularPrism(-1.5, -1.2, -0.25, 2.0, 0.08, 0.1, 90, 40, 0, colors);
    r.draw();

    r = RectangularPrism(-1.5, -1.2, 0.15, 2.0, 0.08, 0.1, 90, 40, 0, colors);
    r.draw();
    glPopMatrix();

}

void FerrisWheel::draw_chairs(double phase) {
    glPushMatrix();
    const int num_chairs = 20;
    for (int i = 0; i < num_chairs; i++) {
        double fraction = (i + 0.0) / num_chairs;
        double x = cos(fraction * 2 * M_PI + phase*M_PI/180);
        double y = sin(fraction * 2 * M_PI + phase*M_PI/180);
        FerrisWheelChair chair = FerrisWheelChair(x, y, 0, 90, 180, 90, 0.1);
        chair.draw();
    }
    // draw rings the chairs attach to
    glRotated(phase, 0, 0, 1);
    Ring r = Ring(0.0, 0, 0.1, 0.97, 0.05);
    r.draw();
    r = Ring(0.0, 0, -0.15, 0.97, 0.05);
    r.draw();

    // draw central hub
    double hub_color[3] = {1, 1, 1};
    glBindTexture(GL_TEXTURE_2D, texture[1]); // bind wood texture
    Cylinder c = Cylinder(0, 0, 0, 0.04, 0.4, 0, 0, hub_color, hub_color, hub_color);
    c.draw();

    // draw connections to central hub
    double support_colors[3] = {1, 1, 1};
    const int num_supports = 10;
    glBindTexture(GL_TEXTURE_2D, texture[1]); // bind wood texture

    for (int support = 0; support < num_supports; support++) {
        glPushMatrix();
        glRotated(360/num_supports * support, 0, 0, 1);
        c = Cylinder(0, 0, 0, 0.01, 1.99, 82.6, 0, support_colors, support_colors, support_colors);
        c.draw();
        glPopMatrix();
    }

    glPopMatrix();
}

void FerrisWheel::draw(double phase) {
    // put the chairs in!
    float white[] = {1,1,1,1};
    float black[] = {0,0,0,1};
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,0);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);

    glPushMatrix();
    glTranslated(cx, cy, cz);
    glScaled(scale, scale, scale);
    draw_chairs(phase);
    draw_support();
    glPopMatrix();
}

FerrisWheelChair::FerrisWheelChair(double cx, double cy, double cz,
        double rx, double ry, double rz, double scale):
    cx(cx), cy(cy), cz(cz), rx(rx), ry(ry), rz(rz), scale(scale), width(1.0) {}

void FerrisWheelChair::draw_supports() {
    const int num_supports = 20;
    const double angle_step = 160.0 / num_supports;
    const double location = 1.05;

    // connection between seat and back
    double color[3] = {1,1,1};
    for(int i = 0; i <= num_supports; i++) {
        double x = Cos(i*angle_step + 10);
        double y = Sin(i*angle_step + 10);
        glBindTexture(GL_TEXTURE_2D, texture[3]); // bind cork texture
        Cylinder c = Cylinder(location*x, location*y, -0.3, 0.01, 0.3, 0 ,0,
                color, color, color);
        c.draw();
    }

    // lock bar
    double lock_color[3] = {1., 1., 1.};
    glBindTexture(GL_TEXTURE_2D, texture[8]); // bind stripes texture
    Cylinder c = Cylinder(0, 0.05, 0, 0.02, 2.1, 90, 0, lock_color, lock_color, lock_color);
    c.draw();
}

void FerrisWheelChair::draw_foot_area() {
    double color[18] = {1, 1, 1,
                        1, 1, 1,
                        1, 1, 1,
                        1, 1, 1,
                        1, 1, 1,
                        1, 1, 1};
    RectangularPrism r = RectangularPrism(-1.1, 0.01, -1.0, 2.2, 0.5, 0.01, 90, 0, 0, color);
    r.draw();
    r = RectangularPrism(-1.1, -0.3, -1.0, 0.3, 0.2, 0.01, 0, 90, 90, color);
    r.draw();
    r = RectangularPrism(1.09, -0.3, -1.0, 0.3, 0.2, 0.01, 0, 90, 90, color);
    r.draw();
    r = RectangularPrism(-1.1, -0.3, -1.0, 2.2, 0.2, 0.01, 90, 0, 0, color);
    r.draw();
    r = RectangularPrism(-1.1, -0.3, -1.0, 2.2, 0.3, 0.01, 180, 180, 180, color);
    r.draw();
    // bottom
    const int num_sections = 100;

    // bottom
    glBindTexture(GL_TEXTURE_2D, texture[1]); // bind wood texture
    glColor3d(0.3, 0.3, 0.35);
    glBegin(GL_TRIANGLE_STRIP);
    glNormal3d(0, 0, -1);
    double angle_step_big = 180.0 / num_sections;
    for (int i = 0; i <= num_sections; i++) {
        double x = 1.1*Cos(i * angle_step_big);
        double y = 1.1*Sin(i * angle_step_big);
        glTexCoord2f(0,0); glVertex3d(0, 0, -1.0);
        glTexCoord2f(x, y); glVertex3d(x, y, -1.0);
        glTexCoord2f(x, y); glVertex3d(x, y, -1.0);
    }
    glEnd();

    const double angle_step = 180.0 / num_sections;
    glBegin(GL_QUAD_STRIP);
    for(int i = 0; i <= num_sections; i++) {
        double x = Cos(i*angle_step);
        double y = Sin(i*angle_step);
        glNormal3d(1.1*x, 1.1*y, 0);
        glTexCoord2f(i, 0); glVertex3d(1.1*x, 1.1*y, -0.5);
        glTexCoord2f(i, 1); glVertex3d(1.1*x, 1.1*y, -1.0);
    }
    glEnd();

}

void FerrisWheelChair::draw_back() {
    const int num_sections = 100;
    const double angle_step = 180.0 / num_sections;
    const double thickness = 1.1;


    // draw front surface
    glColor3d(1,1,1);
    glBindTexture(GL_TEXTURE_2D, texture[0]); // bind leather texture
    glBegin(GL_QUAD_STRIP);
    for(int i = 0; i <= num_sections; i++) {
        double x = Cos(i*angle_step);
        double y = Sin(i*angle_step);
        glNormal3d(-x, -y, 0);
        glTexCoord2f(i/10., 0.);
        glVertex3d(x, y, -0.25);

        glNormal3d(-x, -y, 0);
        glTexCoord2f(i/10., 1.);
        glVertex3d(x, y, 0.25);
    }
    glEnd();

    // draw back surface
    glColor3d(1,1,1);
    glBindTexture(GL_TEXTURE_2D, texture[1]); // bind wood texture

    glBegin(GL_QUAD_STRIP);
    for(int i = 0; i <= num_sections; i++) {
        double x = Cos(i*angle_step);
        double y = Sin(i*angle_step);
        glNormal3d(thickness*x, thickness*y, 0);
        glTexCoord2f(i/2., 0);
        glVertex3d(thickness*x, thickness*y, -0.25);

        glNormal3d(thickness*x, thickness*y, 0);
        glTexCoord2f(i/2., 1);
        glVertex3d(thickness*x, thickness*y, 0.25);
    }
    glEnd();


    // draw bottom surface
    glColor3d(0.75, 0.75, 1.0);
    glBindTexture(GL_TEXTURE_2D, texture[4]); // bind rough metal texture
    glBegin(GL_QUAD_STRIP);
    for(int i = 0; i <= num_sections; i++) {
        double x = Cos(i*angle_step);
        double y = Sin(i*angle_step);
        glTexCoord2f(x/2., y/2.); glNormal3d(0, 0, -1); glVertex3d(x, y, -0.25);
        glTexCoord2f(thickness*x/2., thickness*y/2.); glNormal3d(0, 0, -1); glVertex3d(thickness*x, thickness*y, -0.25);
    }
    glEnd();

    // draw top surface
    glColor3d(0.75, 0.75, 1.0);
    glBegin(GL_QUAD_STRIP);
    for(int i = 0; i <= num_sections; i++) {
        double x = Cos(i*angle_step);
        double y = Sin(i*angle_step);
        glTexCoord2f(x/2., y/2.); glNormal3d(0, 0, 1); glVertex3d(x, y, 0.25);
        glTexCoord2f(thickness*x/2., thickness*y/2.); glNormal3d(0, 0, 1); glVertex3d(thickness*x, thickness*y, 0.25);
    }
    glEnd();

    // draw front closure
    glColor3d(0.75, 0.75, 1.0);
    glBegin(GL_TRIANGLE_STRIP);
    glNormal3d(0, -1, 0);
    glTexCoord2f(0, 0); glVertex3d(1, 0, -0.25);
    glTexCoord2f(1, 0); glVertex3d(thickness, 0, -0.25);
    glTexCoord2f(1, 1); glVertex3d(thickness, 0, 0.25);
    glTexCoord2f(1, 1); glVertex3d(thickness, 0, 0.25);
    glTexCoord2f(0, 1); glVertex3d(1, 0, 0.25);
    glTexCoord2f(0, 0); glVertex3d(1, 0, -0.25);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glNormal3d(0, -1, 0);
    glTexCoord2f(0, 0); glVertex3d(-1, 0, -0.25);
    glTexCoord2f(1, 0); glVertex3d(-thickness, 0, -0.25);
    glTexCoord2f(1, 1); glVertex3d(-thickness, 0, 0.25);
    glTexCoord2f(1, 1); glVertex3d(-thickness, 0, 0.25);
    glTexCoord2f(0, 1); glVertex3d(-1, 0, 0.25);
    glTexCoord2f(0, 0); glVertex3d(-1, 0, -0.25);
    glEnd();

    // filler to flatten back
    glColor3d(1,1,1);
    const double length_offset = 0.7;
    const double angle_offset = 90.0 - ACos(length_offset);
    glBindTexture(GL_TEXTURE_2D, texture[0]); // bind leather texture
    double angle_step_small = (180.0 - 2.0 * angle_offset) / num_sections;
    // bottom surface
    glNormal3d(0, 0, -1);
    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= num_sections; i++) {
        double x = Cos(i * angle_step_small + angle_offset);
        double y = Sin(i * angle_step_small + angle_offset);
        glTexCoord2f(0, length_offset);  glVertex3d(0, length_offset, -0.25);
        glTexCoord2f(x, y); glVertex3d(x, y, -0.25);
        glTexCoord2f(x, y); glVertex3d(x, y, -0.25);
    }
    glEnd();

    // top surface
    glColor3d(1,1,1);
    glNormal3d(0, 0, 1);
    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= num_sections; i++) {
        double x = Cos(i * angle_step_small + angle_offset);
        double y = Sin(i * angle_step_small + angle_offset);
        glTexCoord2f(0, length_offset*3.); glVertex3d(0, length_offset, 0.25);
        glTexCoord2f(x*3., y*3.); glVertex3d(x, y, 0.25);
        glTexCoord2f(x*3., y*3.); glVertex3d(x, y, 0.25);
    }
    glEnd();

    //front surface
    glColor3d(1,1,1);
    glNormal3d(0, -1, 0);
    glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2f(0, 0); glVertex3d(Cos(angle_offset), Sin(angle_offset), -0.25);
    glTexCoord2f(0, 1); glVertex3d(Cos(angle_offset), Sin(angle_offset), 0.25);
    glTexCoord2f(4, 1);
    glVertex3d(Cos(num_sections *angle_step_small + angle_offset),
            Sin(num_sections *angle_step_small + angle_offset), 0.25);

    glTexCoord2f(4, 1);
    glVertex3d(Cos(num_sections *angle_step_small + angle_offset),
               Sin(num_sections *angle_step_small + angle_offset), 0.25);
    glTexCoord2f(4, 0);
    glVertex3d(Cos(num_sections *angle_step_small + angle_offset),
            Sin(num_sections *angle_step_small + angle_offset), -0.25);
    glTexCoord2f(0, 0); glVertex3d(Cos(angle_offset), Sin(angle_offset), -0.25);
    glEnd();

}

void FerrisWheelChair::draw_seat() {
    const double length_offset = 0.1;
    const double thickness = 0.05;
    const double angle_offset = 90.0 - ACos(length_offset);
    const int num_sections = 100;
    const double outer_radius = 1.1;

    glPushMatrix();
    glTranslated(0, 0, -0.5);
    glScaled(outer_radius, outer_radius, outer_radius);
    // bottom
    glColor3d(0.4, 0.4, 1);
    glBegin(GL_TRIANGLE_STRIP);
    glNormal3d(0, 0, -1);
    double angle_step_big = 180.0 / num_sections;
    for (int i = 0; i <= num_sections; i++) {
        double x = Cos(i * angle_step_big);
        double y = Sin(i * angle_step_big);
        glVertex3d(0, 0, 0);
        glVertex3d(x, y, 0);
        glVertex3d(x, y, 0);
    }
    glEnd();

    // top
    glColor3d(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, texture[0]); // bind leather texture
    glNormal3d(0, 0, 1);
    double angle_step_small = (180.0 - 2.0 * angle_offset) / num_sections;
    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= num_sections; i++) {
        double x = Cos(i * angle_step_small + angle_offset);
        double y = Sin(i * angle_step_small + angle_offset);
        glTexCoord2f(0, 0); glVertex3d(0, length_offset, thickness);
        glTexCoord2f(x*2., y*2.); glVertex3d(x, y, thickness);
        glVertex3d(x, y, thickness);
    }
    glEnd();

    // front
    glColor3d(0.75, 0.75, 1.0);
    glBindTexture(GL_TEXTURE_2D, texture[4]); // bind rough metal texture
    glBegin(GL_TRIANGLE_STRIP);
    glTexCoord2f(0, 0);
    glVertex3d(1, 0, 0);
    glTexCoord2f(0, 0.5);
    glVertex3d(Cos(angle_offset), +Sin(angle_offset), thickness);
    glTexCoord2f(3, 0.5);
    glVertex3d(Cos(num_sections * angle_step_small + angle_offset),
               Sin(num_sections * angle_step_small + angle_offset),
               thickness);

    glTexCoord2f(3, 0.5);
    glVertex3d(Cos(num_sections * angle_step_small + angle_offset),
               Sin(num_sections * angle_step_small + angle_offset),
               thickness);
    glTexCoord2f(3, 0);
    glVertex3d(-1, 0, 0);
    glTexCoord2f(0, 0);
    glVertex3d(1, 0, 0);
    glEnd();

    // back
    glColor3d(0.75, 0.75, 1.0);
    glBindTexture(GL_TEXTURE_2D, texture[4]); // bind rough metal texture
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= num_sections; i++) {
        glTexCoord2f(Cos(i * angle_step_small + angle_offset),
                     Sin(i * angle_step_small + angle_offset));
        glNormal3d(Cos(i * angle_step_small + angle_offset),
                Sin(i * angle_step_small + angle_offset),
                0);
        glVertex3d(Cos(i * angle_step_small + angle_offset),
                   Sin(i * angle_step_small + angle_offset),
                   thickness);

        glTexCoord2f(Cos(i * angle_step_big), Sin(i * angle_step_big));
        glNormal3d(Cos(i * angle_step_big), Sin(i * angle_step_big),
                   0);
        glVertex3d(Cos(i * angle_step_big), Sin(i * angle_step_big), 0);
    }
    glEnd();
    glPopMatrix();
}


void FerrisWheelChair::draw() {
    float white[] = {1,1,1,1};
    float black[] = {0,0,0,1};
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,8);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);

    glPushMatrix();
    glTranslated(cx, cy, cz);
    glScaled(scale, scale, scale);
    glRotated(rx,1,0,0);
    glRotated(ry,0,1,0);
    glRotated(rz,0,0,1);
    draw_back();
    draw_seat();
    draw_supports();
    draw_foot_area();
    glPopMatrix();
}