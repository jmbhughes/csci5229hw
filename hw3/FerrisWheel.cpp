#include "CSCIx229.h"
#include "FerrisWheel.h"
#include "Ring.h"
#include "Cylinder.h"
#include "RectangularPrism.h"

FerrisWheel::FerrisWheel(double cx, double cy, double cz, double height, double chair_width):
    cx(cx), cy(cy), cz(cz), height(height), chair_width(chair_width){}

void FerrisWheel::draw_support() {
    const double hub_radius = 0.1;
    const double hub_height = 0.05;
    Cylinder hub = Cylinder(cx, cy + 0.5 * height, cz + 0.5 * 0.15 * chair_width, hub_radius, hub_height);
    hub.draw();

    // add struct to hold
    RectangularPrism r = RectangularPrism(cx, cy + height, cz,
            0.01, height, 0.01, 180, 0.1);
    r.draw();
}

void FerrisWheel::draw() {
    const double radius = height/2.0;
    const double thickness = 0.01;

    // draw outer supports
    Ring r1 = Ring(cx, cy + radius, cz, radius, thickness);
    Ring r2 = Ring(cx, cy + radius, cz + 0.2 * chair_width, radius, thickness);
    r1.draw();
    r2.draw();

    // draw hub
    draw_support();

    // put the chairs in!
    const int num_chairs = 30;
    for (int i = 0; i < num_chairs; i++) {
        double fraction = (i + 0.0) / num_chairs;
        double x = radius * cos(fraction * 2 * M_PI) + cx;
        double y = radius * sin(fraction * 2 * M_PI) + cy + height/2.1;
        FerrisWheelChair chair = FerrisWheelChair(x, y, cz, chair_width, 0, 0, 0.15);
        chair.draw();
    }
}

FerrisWheelChair::FerrisWheelChair(double cx, double cy, double cz, double width,
        double angle_alt, double angle_az, double scale):
    cx(cx), cy(cy), cz(cz), width(width), angle_alt(angle_alt), angle_az(angle_az), scale(scale) {}

void FerrisWheelChair::draw() {
    glPushMatrix();
    //
    glTranslated(cx, cy, cz);

    glScaled(scale, scale, scale);
    glRotated(angle_alt,0,1,0);
    glRotated(angle_az,1,0,0);


    const int num_sections = 100;
    glBegin(GL_QUAD_STRIP);
    double x_start = 0.005;
    double x_end = 0.4;
    double x_step = (x_end - x_start) / num_sections;
    double x_curr = 0 * x_step + x_start;

    // draw top smooth surface of the seat
    for (int i = 0; i < num_sections; i++) {
        glColor3d((i + 0.0)/num_sections, 0, 1.0 - (i + 0.0)/num_sections);
        glVertex3d(x_curr, -0.3 * log10(x_curr) + 0.4 * x_curr - 0.25, 0);
        glVertex3d(x_curr, -0.3 * log10(x_curr) + 0.4 * x_curr - 0.25, width);
        x_curr = i * x_step + x_start;
    }

    // connect top surface of the seat to chair
    glColor3d(1, 1, 1);
    glVertex3d(x_curr, 0, 0);
    glVertex3d(x_curr, 0, width);
    glVertex3d(0, 0, 0);
    glVertex3d(0, 0, width);
    x_curr = 1 * x_step + x_start;
    glVertex3d(x_curr, -0.3 * log10(x_curr) + 0.4 * x_curr - 0.25, 0);
    glVertex3d(x_curr, -0.3 * log10(x_curr) + 0.4 * x_curr - 0.25, width);
    glEnd();

    // draw sides of the seat
    auto side = RectangularPrism(0, 0, 0, 0.4, 0.2, 0.05);
    side.draw();
    side = RectangularPrism(0, 0.2, 0, 0.1, 0.25, 0.05);
    side.draw();

    side = RectangularPrism(0, 0, width, 0.4, 0.2, 0.05);
    side.draw();
    side = RectangularPrism(0, 0.2, width, 0.1, 0.25, 0.05);
    side.draw();

    // draw back of the seat
    auto back = RectangularPrism(-0.01, 0, width + 0.05 , width + 0.05, 0.5, 0.02, 0, 90);
    back.draw();

    // draw restraining bar
    auto bar = Cylinder(0.3, 0.2, width/2 + 0.025, 0.01, width + 0.05);
    bar.draw();

    glPopMatrix();
}