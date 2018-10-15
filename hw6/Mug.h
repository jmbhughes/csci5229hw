/*
 * Draw a mug (and have some tea!)
 */

#ifndef HW3_MUG_H
#define HW3_MUG_H

class Mug {
private:
    double cx, cy, cz, height, radius, rx, ry, rz;
    double base_color[3] = {0.25,0.25,0.25};
    double side_color[3] = {0.03,0.16,0.40};
    double inside_color[3] = {0.3, 0.3, 0.4};
    double top_color[3] = {1, 1, 0};
    double handle_color[3] = {1, 1, 0};
public:
    // create a mug where the center of the bottom is at (cx, cy, cz) with a cup height and a circle of specified radius
    // rotate the mug by (rx, ry, rz) in degrees
    Mug(double cx, double cy, double cz, double height, double radius, double rx, double ry, double rz);

    Mug(double cx, double cy, double cz, double height, double radius, double rx, double ry, double rz,
            double base_color[3], double side_color[3], double inside_color[3],
            double top_color[3], double handle_color[3]);
    // draw a mug
    void draw();
};


#endif //HW3_MUG_H
