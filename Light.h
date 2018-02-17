#ifndef LIGHT_H
#define LIGHT_H

#include "Vect.h"
#include "Color.h"

class Light
{
  Vect m_pos;
  Vect m_dir;
  Color m_color;

public:
  Light();
  Light(
  const Vect &, 
  //const Vect &,
  const Color &);
  virtual const Vect & GetPos() const {return m_pos;}
  virtual const Vect & GetDir() const {return m_dir;}
  virtual const Color & GetColor() const {return m_color;}
};

Light::Light() : m_pos(0,0,0), m_dir(0,0,1), m_color(1,1,1){}
Light::Light(
const Vect & pos, 
//const Vect & dir,
const Color & color)
: m_pos(pos)
//, m_dir(dir)
, m_color(color)
{
}

#endif
