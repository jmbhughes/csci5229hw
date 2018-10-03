/*
 * Draw a three dimensional cylinder
 */

#ifndef HW3NEW_CYLINDER_H
#define HW3NEW_CYLINDER_H


class Cylinder {
private:
    double cx, cy, cz, radius, height, angle_alt, angle_az;
    double top_color[3]; // rgb color of top circle
    double bottom_color[3]; // rgb color ofo bottom circle
    double column_color[3]; // rgb color of outside of cylinder
public:
    // create radius at origin with specified face radius of height, projects into z
    Cylinder(double radius, double height);

    // create cylinder at (cx, cy, cz) or specified radius and height, projects into z
    Cylinder(double cx, double cy, double cz, double radius, double height);

    // create cylinder at (cx, cy, cz) of specified radius adn height and rotated
    Cylinder(double cx, double cy, double cz, double radius, double height,
            double angle_alt, double angle_az);

    // create cylinder at (cx, cy, cz) of specified radius and height and rotated with requested colors
    Cylinder(double cx, double cy, double cz, double radius, double height,
             double angle_alt, double angle_az,
             double top_color[3], double bottom_color[3], double column_color[3]);

    // draw cylinder
    void draw();
};


#endif //HW3NEW_CYLINDER_H
