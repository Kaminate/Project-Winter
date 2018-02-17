#ifndef CAMERA_H
#define CAMERA_H

#include "Vect.h"

class Camera
{
  Vect m_pos;
  Vect m_dir;
  Vect m_right;
  Vect m_down;
public:
  Camera();
  Camera(const Vect &, const Vect &, const Vect &, const Vect &);
  const Vect & GetPos() const {return m_pos;}
};

Camera::Camera()
: m_pos(0,0,0)
, m_dir(0,0,1)
, m_right(0,0,0) // wtf
, m_down(0,0,0)
{}
Camera::Camera(
  const Vect & pos, 
  const Vect & dir,
  const Vect & right, 
  const Vect & down)
: m_pos(pos), m_dir(dir), m_right(right), m_down(down)
{
}

#endif
