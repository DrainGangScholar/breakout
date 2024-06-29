#ifndef TEXTURE2D_H
#define TEXTURE2D_H
#include "glad/glad.h"
class Texture2D {
public:
  unsigned int ID;
  unsigned int Width, Height;
  unsigned int Internal_Format; // format of texture object
  unsigned int Image_Format;
  unsigned int Wrap_S;
  unsigned int Wrap_T;
  unsigned int Filter_Min;
  unsigned int Filter_Max;

public:
  Texture2D();

public:
  void Generate(unsigned int width, unsigned int height, char *data);
  void Bind() const;
};
#endif