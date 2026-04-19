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
    Position(float x, float y);
    Position(const Position& pt) : x(pt.x), y(pt.y) {}
    Position& operator = (const Position& pt);

    // Getters
    float getMetersX() const { return x; }
    float getMetersY() const { return y; }    
    float getPixelsX() const { return x / metersFromPixels; }
    float getPixelsY() const { return y / metersFromPixels; }

    // Setters
    void setMeters(float xMeters, float yMeters) {x = xMeters; y = yMeters; }
    void setMetersX(float xMeters) { x = xMeters; }
    void setMetersY(float yMeters) { y = yMeters; }
    void setPixelsX(float xPixels) { x = xPixels * metersFromPixels; }
    void setPixelsY(float yPixels) { y = yPixels * metersFromPixels; }

    // Add
    void addMetersX(float dxMeters) {setMetersX(getMetersX() + dxMeters); }
    void addMetersY(float dyMeters) {setMetersY(getMetersY() + dyMeters); }
    void addPixelsX(float dxPixels) {setPixelsX(getPixelsX() + dxPixels); }
    void addPixelsY(float dyPixels) {setPixelsY(getPixelsY() + dyPixels); }
    void add(const Acceleration& a, const Velocity& v, float t);

    // Deal with ratio between pixels and meters
    void setZoom(float metersFromPixels) { 
        this->metersFromPixels = metersFromPixels; }

    float getZoom() const { return metersFromPixels; }

private:
    float x; // horizontal position
    float y; // vertical position
    static float metersFromPixels;
};

#endif