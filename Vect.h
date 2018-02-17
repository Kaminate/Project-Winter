#ifndef VECT_H
#define VECT_H

#include "math.h"

class Vect
{
public:
  float m_x,m_y,m_z;
  Vect();
  Vect(float,float,float);
  Vect(const Vect &);
  Vect normalize();
  float magnitude() const;
  Vect operator - (const Vect &) const;
  float dot(const Vect &) const;
  Vect cross(const Vect &) const;
  Vect operator + (const Vect &) const;
  Vect operator * (float) const;
};

Vect::Vect() : m_x(0),m_y(0),m_z(0){}
Vect::Vect(float x, float y, float z)
{
  m_x = x; m_y = y; m_z = z;
}
Vect::Vect(const Vect & v) : m_x(v.m_x), m_y(v.m_y), m_z(v.m_z){}
Vect Vect::normalize()
{
  float length = magnitude();
  // todo: sometihng if length == 0
  return Vect(m_x/length, m_y/length, m_z/length);
}
float Vect::magnitude() const
{
  return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}
Vect Vect::operator - (const Vect & v) const
{
  return Vect(-v.m_x, -v.m_y, -v.m_z);
}
float Vect::dot(const Vect & v) const
{
  return m_x * v.m_x + m_y * v.m_y + m_z * v.m_z;
}
Vect Vect::cross(const Vect & v) const
{
  return Vect(
    m_y*v.m_z - m_z * v.m_y,
    -m_x*v.m_z + m_z * v.m_x,
    m_x * v.m_y - m_y * v.m_x);
}
Vect Vect::operator +(const Vect & v) const
{
  return Vect(m_x + v.m_x, m_y + v.m_y, m_z + v.m_z);
}
Vect Vect::operator * (float scale) const
{
  return Vect(m_x * scale, m_y * scale, m_z * scale);
}
#endif
