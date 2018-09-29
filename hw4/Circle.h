/*
 * A 2d circle
 */

#ifndef HW3NEW_CIRCLE_H
#define HW3NEW_CIRCLE_H

class Circle {
private:
    double cx, cy, cz, radius, angle_alt, angle_az;
    double color[3];
public:
    // creates a circle at the origin in (x,y) plane with specified radius
    explicit Circle(double radius);

    // creates a circle at (cx, cy, cz) of specified radius parallel to (x,y) plane
    Circle(double cx, double cy, double cz, double radius);

    // creates a circle at (cx, cy, cz) of specified radius rotates in altitude and azimuth by specified angles
    Circle(double cx, double cy, double cz, double radius, double angle_alt, double angle_az);

    // creates a colored circle at (cx, cy, cz) of specified radius rotates in altitude and azimuth by specified angles
    Circle(double cx, double cy, double cz, double radius,
            double angle_alt, double angle_az, double color[3]);

    // actually draw the object
    void draw();
};


#endif //HW3NEW_CIRCLE_H
