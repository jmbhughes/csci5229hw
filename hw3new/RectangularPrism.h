//
// Created by marcus on 9/25/18.
//

#ifndef HW3NEW_RECTANGULARPRISM_H
#define HW3NEW_RECTANGULARPRISM_H


class RectangularPrism {
private:
    double width;
    double length;
    double height;
    double angle_az;
    double angle_alt;
    double face_colors[3*6];
public:
    RectangularPrism(double width, double length, double height);
    RectangularPrism(double width, double length, double height, double angle_az, double angle_alt);
    RectangularPrism(double width, double length, double height,
            double angle_az, double angle_alt,
            double face_colors[3*6]);
    void draw();
};


#endif //HW3NEW_RECTANGULARPRISM_H
