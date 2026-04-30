/*************************
 * Header File: VELOCITY
 * Author: Jessen
 * Summary: The velocity of an object on screen such as a planet, star, satellite, etc.
 *************************/
#ifndef VELOCITY_H
#define VELOCITY_H

class Velocity
{
public:
    Velocity() : dx(0.0), dy(0.0) { }
    Velocity(double dx, double dy) : dx(dx), dy(dy) { }

    // Getters
    double getDx()    const { return dx; }
    double getDy()    const { return dy; }
    double getSpeed() const;

    // Setters
    void setDx(double dx) { this->dx = dx; }
    void setDy(double dy) { this->dy = dy; }
    void set(double dx, double dy) { this->dx = dx; this->dy = dy; }
    void addDx(double dx) {this->dx += dx; }
    void addDy(double dy) {this->dy += dy; }

private:
    double dx; // Horizontal Velocity
    double dy; // Vertical Velocity

};
#endif
