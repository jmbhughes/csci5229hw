/*
 * draws a hula-hoop object
 */

#ifndef HW3NEW_RING_H
#define HW3NEW_RING_H

class Ring {
private:
    double cx, cy, cz, radius, thickness;
public:
    // create ring where inside is at (cx, cy, cz) and specified radius, thickness is how thick the hula-hoop ring is
    Ring(double cx, double cy, double cz, double radius, double thickness);
    void draw();
};

#endif //HW3NEW_RING_H