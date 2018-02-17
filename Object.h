#ifndef OBJECT_H 
#define OBJECT_H 

#include "math.h"
#include "Ray.h"
#include "Vect.h"
#include "Color.h"

class Object 
{
  Color m_color;
public:
  Object();
  Object(const Color &);
  const Color & GetObjectColor() const;
  void SetColor(const Color &);

  virtual float FindIntersection(const Ray &) const = 0;

};
Object::Object() : m_color(.5,.5,.5,0) {}
Object::Object(const Color & color) : m_color(color) {}
const Color & Object::GetObjectColor() const
{
  return m_color;
}
void Object::SetColor(const Color & color)
{
  m_color = color;
}

#endif
