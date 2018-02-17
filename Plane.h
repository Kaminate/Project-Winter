#ifndef PLANE_H
#define PLANE_H

#include "math.h"
#include "Vect.h"
#include "Object.h"

class Plane : public Object
{
  Vect m_normal;
  float m_distance;
public:
  Plane();
  Plane(const Vect &, float);
  // todo: getters

  Vect GetNormalAt(const Vect & point) const;
  virtual float FindIntersection(const Ray &) const;
};

Plane::Plane()
: m_normal(1,0,0)
, m_distance(0)
{}
Plane::Plane(const Vect & normal, float distance)
: m_normal(normal)
, m_distance(distance)
{
}
Vect Plane::GetNormalAt(const Vect & point) const
{
  return m_normal;
}

// did this by hand, probably correct, but may be fuxed up
float Plane::FindIntersection(const Ray & ray) const
{
  Vect rayDir = ray.m_direction;
  float a = rayDir.dot(m_normal);
  if (a == 0) return -1; // ray is parallel to plane
  
  return (-m_distance - m_normal.dot(ray.m_origin)) / a;
}

#endif
