/*************************
 * Header File: ACCELERATION
 * Author: Jessen
 * Summary: The acceleration attribute of a planet, star, or element on screen.
 *************************/
#ifndef ACCELERATION_H
#define ACCELERATION_H

class Acceleration
{
public:
    // Constructors
    Acceleration() : ddx(0.0), ddy(0.0) { }
    Acceleration(double ddx, double ddy) : ddx(ddx), ddy(ddy) { }

    // Getters
    double getDDX() const { return ddx; }
    double getDDY() const { return ddy; }

    // Setters
    void setDDX(double ddx) { this->ddx = ddx; }
    void setDDY(double ddy) { this->ddy = ddy; }

    // Add
    void addDDX(double ddx) { this->ddx += ddx; }
    void addDDY(double ddy) { this->ddy += ddy; }
    void add(const Acceleration& rhs);

private:
    double ddx; // Horizontal acceleration
    double ddy; // Vertical accerlation
};
#endif