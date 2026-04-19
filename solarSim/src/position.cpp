/*************************
 * Soruce File: POSITION
 * Author: Jessen
 * Summary:
 * The position of a planet, star, or element on screen.
 *************************/
#include "physics/position.h"
#include "physics/velocity.h"
#include "physics/acceleration.h"


// Constructors
Position::Position(float x, float y) : x(0.0), y(0.0)
{
    setMetersX(x);
    setMetersY(y);
}

// Assignment Operator
Position& Position::operator = (const Position& pt)
{
    x = pt.x;
    y = pt.y;
    return *this;
}

// Insertion / Extraction



/*************************
 * ADD
 * Update the current position based on velocity 
 *************************/
void Position::add(const Acceleration& a, const Velocity& v, float t)
{
    // Use acceleration methods to get access to acceleration values
    float ddx = a.getDDX();
    float ddy = a.getDDY();

    this->x += v.getDx() * t + 0.5 * ddx * t * t;
    this->y += v.getDy() * t + 0.5 * ddy * t * t;
}



