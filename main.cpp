// includ all the things
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "Vect.h"
#include "Ray.h"
#include "Camera.h"
#include "Color.h"
#include "Light.h"
#include "Plane.h"
#include "Sphere.h"
#include "Object.h"

using namespace std;

struct RGBType
{
  float r;
  float g;
  float b;
  void Set(float R, float G, float B)
  {
    r = R; g = G; b = B;
  }
};

void savebmp(
  const char * filename, 
  int w, 
  int h, 
  int dpi, 
  const RGBType * data)
{
  FILE * f;
  int k = w * h;
  int s = 4 * k;
  int filesize = 54 + s;

  double factor = 39.375;
  int m = factor;

  int ppm = dpi * m;

  unsigned char bmpfileheader[14] = 
  {
    'B', 'M', 0,0,0,0, 0,0,0,0, 54,0,0,0
  };
  unsigned char bmpinfoheader[40] = 
  {
    40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,24,0
  };

  // file header
  bmpfileheader[2 ] = (unsigned char) (filesize);   
  bmpfileheader[3 ] = (unsigned char) (filesize>>8);
  bmpfileheader[4 ] = (unsigned char) (filesize>>16);
  bmpfileheader[5 ] = (unsigned char) (filesize>>24);

  // info header
  bmpinfoheader[4 ] = (unsigned char) (w);
  bmpinfoheader[5 ] = (unsigned char) (w>>8);
  bmpinfoheader[6 ] = (unsigned char) (w>>16);
  bmpinfoheader[7 ] = (unsigned char) (w>>24);

  bmpinfoheader[8 ] = (unsigned char) (h);
  bmpinfoheader[9 ] = (unsigned char) (h>>8);
  bmpinfoheader[10] = (unsigned char) (h>>16);
  bmpinfoheader[11] = (unsigned char) (h>>24);

  bmpinfoheader[21] = (unsigned char) (s);
  bmpinfoheader[22] = (unsigned char) (s>>8);
  bmpinfoheader[23] = (unsigned char) (s>>16);
  bmpinfoheader[24] = (unsigned char) (s>>24);

  bmpinfoheader[25] = (unsigned char) (ppm);
  bmpinfoheader[26] = (unsigned char) (ppm>>8);
  bmpinfoheader[27] = (unsigned char) (ppm>>16);
  bmpinfoheader[28] = (unsigned char) (ppm>>24);

  bmpinfoheader[29] = (unsigned char) (ppm);
  bmpinfoheader[30] = (unsigned char) (ppm>>8);
  bmpinfoheader[31] = (unsigned char) (ppm>>16);
  bmpinfoheader[32] = (unsigned char) (ppm>>24);

  f = fopen(filename, "wb");
  fwrite(bmpfileheader, 1, 14, f);
  fwrite(bmpinfoheader, 1, 40, f);

  for (int i = 0; i < k; ++i)
  {
    RGBType rgb = data[i];
    float r = rgb.r * 255;
    float g = rgb.g * 255;
    float b = rgb.b * 255;

    unsigned char color[3] = {b,g,r};
    fwrite(color, 1, 3, f);
  }
  fclose(f);
}

int main(int argc, char * argv[])
{
  cout << "Hello World... " << endl;

  int dpi = 72;
  int width = 640;
  int height = 480;
  int n = width * height;
  float aspectRatio = (float)width / height;

  RGBType * pixels = new RGBType[n];

  
  Vect xAxis (1,0,0);
  Vect yAxis (0,1,0);
  Vect zAxis (0,0,1);
  Vect origin(0,0,0);

  // camera
  Vect campos(3, 1, 0);
  Vect looktarget(0,0,0);
  Vect lookatvec = looktarget - campos;
  Vect camdir = lookatvec.normalize();
  Vect camright = camdir.cross(yAxis);
  Vect camdown = camdir.cross(camright);
  Camera camera(campos, camdir, camright, camdown);
  Color white_light(1,1,1,0);
  Color pretty_green(0.5,1,.5,.3);
  Color gray (.5,.5,.5,0);
  Color black(0,0,0,0);

  Vect lightPos(-7,10,-10);
  Light sceneLight(lightPos, white_light);
  
  // scene objects
  Sphere scene_sphere(origin, 1);
  Plane scene_plane(yAxis, -1);

  float x_amt, y_amt;

  // origin is top left
  for (int x = 0; x < width; ++x)
  {
    for (int y = 0; y < height; ++y)
    {
      int index = y * width + x;

      // start w/o anti-aliasing
       
      // image is wider than tall
      if (width > height) 
      {
        x_amt = ((x + .5f) / width) * aspectRatio
              - (width - height) / (float)height / 2.0f;
        y_amt = ((height - y) + .5f) / height;
      }
      else if (height > width) // taller than wide
      {
        x_amt = (x + .5f) / width;
        y_amt = (((height - y) + .5f) / height)/aspectRatio
              - ((height - width) / (float)width / 2.0f);
      }
      else // square image
      {
        x_amt = (x + .5f) / width;
        y_amt = ((height - y) + 0.5f) / height;
      }

      Vect rayDir = 
      Ray ray(camera.GetPos(), )

      pixels[index].r = 0;
      pixels[index].g = 0;
      pixels[index].b = 1;
    }
  }

  savebmp("scene.bmp", width, height, dpi, pixels);

  delete pixels;

  return 0;
}

