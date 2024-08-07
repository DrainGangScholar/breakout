#include "../include/Texture2D.hpp"

Texture2D::Texture2D() {
  this->Width = 0;
  this->Height = 0;
  this->Internal_Format = GL_RGB;
  this->Image_Format = GL_RGB;
  this->Wrap_S = GL_REPEAT;
  this->Wrap_T = GL_REPEAT;
  this->Filter_Min = GL_LINEAR;
  this->Filter_Max = GL_LINEAR;
  glGenTextures(1, &this->ID);
}
void Texture2D::Generate(unsigned int width, unsigned int height,
                         unsigned char *data) {
  this->Width = width;
  this->Height = height;

  // creation
  glBindTexture(GL_TEXTURE_2D, this->ID);
  glTexImage2D(GL_TEXTURE_2D, 0, this->Internal_Format, width, height, 0,
               this->Image_Format, GL_UNSIGNED_BYTE, data);

  // texture modes
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->Wrap_S);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->Wrap_T);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->Filter_Min);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->Filter_Max);

  // unbind texture
  glBindTexture(GL_TEXTURE_2D, 0);
}
void Texture2D::Bind() const { glBindTexture(GL_TEXTURE_2D, this->ID); }
