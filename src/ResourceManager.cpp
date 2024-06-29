#include "../include/ResourceManager.h"
#include "../include/stb_image/stb_image.h"
#include <exception>
#include <fstream>
#include <sstream>

std::map<std::string, Shader> ResourceManager::Shaders;
std::map<std::string, Texture2D> ResourceManager::Textures;

Shader ResourceManager::LoadShader(const char *vShaderFile,
                                   const char *fShaderFile,
                                   const char *gShaderFile, std::string name) {
  Shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
  return Shaders[name];
}
Shader ResourceManager::GetShader(std::string name) { return Shaders[name]; }
Texture2D ResourceManager::LoadTexture(const char *file, bool alpha,
                                       std::string name) {
  Textures[name] = loadTextureFromFile(file, alpha);
  return Textures[name];
}
Texture2D ResourceManager::GetTexture(std::string name) {
  return Textures[name];
}
void ResourceManager::Clear() {
  for (auto iter : Shaders) {
    glDeleteProgram(iter.second.ID);
  }
  for (auto iter : Textures) {
    glDeleteTextures(1, &iter.second.ID);
  }
}

Shader loadShaderFromFile(const char *vShaderFile, const char *fShaderFile,
                          const char *gShaderFile) {
  std::string vertexCode;
  std::string fragmentCode;
  std::string geometryCode;
  try {
    std::ifstream vertexShaderFile = std::ifstream(vShaderFile);
    std::ifstream fragmentShaderFile = std::ifstream(fShaderFile);
    std::stringstream vShaderStream, fShaderStream;

    vShaderStream << vertexShaderFile.rdbuf();
    fShaderStream << fragmentShaderFile.rdbuf();

    vertexShaderFile.close();
    fragmentShaderFile.close();

    vertexCode = vShaderStream.str();
    fragmentCode = fShaderStream.str();

    if (gShaderFile != nullptr) {
      std::ifstream geomertyShaderFile = std::ifstream(vShaderFile);
      std::stringstream gShaderStream;

      gShaderStream << geomertyShaderFile.rdbuf();

      geomertyShaderFile.close();

      geometryCode = gShaderStream.str();
    }
  } catch (std::exception e) {
    std::cout << "ERROR::SHADER: Failed to read shader files" << std::endl;
  }
  const char *vShaderCode = vertexCode.c_str();
  const char *fShaderCode = fragmentCode.c_str();
  const char *gShaderCode = geometryCode.c_str();
  Shader shader;
  shader.Compile(vShaderCode, fShaderCode, gShaderCode);
  return shader;
}

Texture2D ResourceManager::loadTextureFromFile(const char *file, bool alpha) {
  Texture2D texture;
  if (alpha) {
    texture.Internal_Format = GL_RGBA;
    texture.Image_Format = GL_RGBA;
  }
  int width, height, nChannels;
  unsigned char *data = stbi_load(file, &width, &height, &nChannels, 0);

  texture.Generate(width, height, data);
  stbi_image_free(data);
  return texture;
}
