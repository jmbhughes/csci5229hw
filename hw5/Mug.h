/*
 * Draw a mug (and have some tea!)
 */

#ifndef HW3_MUG_H
#define HW3_MUG_H

class Mug {
private:
    double cx, cy, cz, height, radius, rx, ry, rz;
public:
    // create a mug where the center of the bottom is at (cx, cy, cz) with a cup height and a circle of specified radius
    // rotate the mug by (rx, ry, rz) in degrees
    Mug(double cx, double cy, double cz, double height, double radius, double rx, double ry, double rz);

    // draw a mug
    void draw();
};


#endif //HW3_MUG_H
