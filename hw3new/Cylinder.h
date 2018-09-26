    //
// Created by marcus on 9/25/18.
//

#ifndef HW3NEW_CYLINDER_H
#define HW3NEW_CYLINDER_H


class Cylinder {
private:
    float radius;
    float height;
public:
    Cylinder(float radius, float height);
    void draw();
    float get_radius();
    float get_height();
};


#endif //HW3NEW_CYLINDER_H
