#ifndef RAY_H
#define RAY_H

#include "Vect.h"

class Ray
{
public:
  Vect m_origin;
  Vect m_direction;
  Ray();
  Ray(const Vect &, const Vect&);
};

Ray::Ray() : m_origin(0,0,0), m_direction(1,0,0){}
Ray::Ray(const Vect & origin, const Vect & direction)
: m_origin(origin) , m_direction(direction)
{
}

#endif
