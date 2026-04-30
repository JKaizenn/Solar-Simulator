/*************************
 * Header File: ANGLE
 * Author: Jessen
 * Summary: The angle of a planet, star, or element on screen.
 *************************/
#include <cmath>

#ifndef ANGLE_H
#define ANGLE_H

class Angle
{
public:
    Angle() : radians(0.0) { }
    Angle(const Angle& rhs) : radians(rhs.radians) { }
    Angle(double degrees) : radians(0.0) { setDegrees(degrees); }

    // Getters
    double getDegrees() const { return convertToDegrees(radians); }
    double getRadians() const { return radians;                   }

    // Setters
    void setDegrees(double degrees)
    {
        radians = normalize(convertToRadians(degrees)); 
    }

    void setRadians(double radians)
    {
        this->radians = normalize(radians);
    }

    // Set directions
    void setUp()    { radians = 0.0;        } 
    void setDown()  { radians = M_PI;       }
    void setRight() { radians = M_PI * .5;  }
    void setLeft()  { radians = M_PI * 1.5; }
    void reverse()  { radians = normalize(radians + M_PI); }

    Angle& add(double delta)
    {
        radians = normalize(radians + delta);
        return *this;
    }

private:
    double radians; // Metric for angle

    // Convert Functions
    double convertToDegrees(double radians) const {
        return radians * (180.0 / M_PI);
    }

    double convertToRadians(double degrees) const {
        return degrees* (M_PI / 180.0);
    }

    // Normalize
    double normalize(double radians) const;
    
};
#endif