//
// Created by marcus on 9/25/18.
//

#ifndef HW3NEW_HOUSE_H
#define HW3NEW_HOUSE_H


class House {
private:
    double width;
    double height;

public:
    House(double width, double height);
    void draw();
    double get_width();
    double get_height();

};


#endif //HW3NEW_HOUSE_H
