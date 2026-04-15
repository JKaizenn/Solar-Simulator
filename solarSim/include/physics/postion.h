/*************************
 * Header File: POSITION
 * Author: Jessen
 * Summary:
 * The position of a planet, star, or element on screen.
 *************************/
#ifndef POSITION_H
#define POSITION_H

#include "acceleration.h"
#include "velocity.h"
#include <iostream>
#include <cmath>

class Position
{
public:
    Position() : x(0.0), y(0.0) {}
    Position(double x, double y);
    Position(const Position& pt) : x(pt.x), y(pt.y) {}
    Position& operator = (const Position& pt);

    // Getters
    double getMetersX() const { return x; }
    double getMetersY() const { return y; }    
    double getPixelsX() const { return x / metersFromPixels; }
    double getPixelsY() const { return y / metersFromPixels; }

    // Setters
    void setMeters(double xMeters, double yMeters) {x = xMeters; y = yMeters; }
    void setMetersX(double xMeters) { x = xMeters; }
    void setMetersY(double yMeters) { y = yMeters; }
    void setPixelsX(double xPixels) { x = xPixels * metersFromPixels; }
    void setPixelsY(double yPixels) { y = yPixels * metersFromPixels; }

    // Add
    void addMetersX(double dxMeters) {setMetersX(getMetersX() + dxMeters); }
    void addMetersX(double dyMeters) {setMetersY(getMetersY() + dyMeters); }
    void addPixelsX(double dxPixels) {setPixelsX(getPixelsX() + dxPixels); }
    void addPixelsY(double dyPixels) {setPixelsY(getPixelsY() + dyPixels); }
    void add(const Acceleration& a, const Velocity& v, double t);

    // Deal with ratio between pixels and meters
    void setZoom(double metersFromPixels) { 
        this->metersFromPixels = metersFromPixels; }

    double getZoom() const { return metersFromPixels; }

private:
    double x; // horizontal position
    double y; // vertical position
    static double metersFromPixels;
};

#endif