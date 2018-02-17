#ifndef COLOR_H
#define COLOR_H

class Color
{
public:
  union
  {
    struct
    {
      float r,g,b,a;
    };
    float v[4];
  };

  Color();
  Color(float,float,float,float);
};

Color::Color() : r(0),g(0), b(0), a(1) {}
Color::Color(float red, float green, float blue, float alpha = 1)
: r(red), g(green), b(blue), a(alpha)
{
}

#endif
