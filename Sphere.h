#ifndef SPHERE_H
#define SPHERE_H

#include "math.h"
#include "Vect.h"
#include "Object.h"

class Sphere : public Object
{
  float m_radius;
  Vect m_pos;
public:
  Sphere();
  Sphere(const Vect &, float);
  // todo: getters
  // 
  // 
  virtual float FindIntersection(const Ray &) const;
};

Sphere::Sphere()
: m_radius(1)
, m_pos(0,0,0)
{}
Sphere::Sphere(const Vect & pos, float radius)
: m_radius(radius)
, m_pos(pos)
{
}
float Sphere::FindIntersection(const Ray & ray) const
{
  //todo
  return -1;
}
#endif
