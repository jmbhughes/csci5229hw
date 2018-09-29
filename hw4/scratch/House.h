/*
 * A simple and beautiful house
 */

#ifndef HW3NEW_HOUSE_H
#define HW3NEW_HOUSE_H


class House {
private:
    // position
    double x;
    double y;
    double z;

    // size
    double width;
    double length;
    double height;

public:
    House(double x, double y, double z,
            double width, double length, double height);
    void draw();

};


#endif //HW3NEW_HOUSE_H
