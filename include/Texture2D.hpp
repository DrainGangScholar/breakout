#ifndef TEXTURE2D_HPP
#define TEXTURE2D_HPP
#include "../include/glad/glad.h"
#include "AUtility.hpp"

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
  void Generate(unsigned int width, unsigned int height, unsigned char *data);
  void Bind() const;
};
#endif
