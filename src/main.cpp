#include "../include/glad/glad.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include "../include/Game.hpp"
#include "../include/ResourceManager.hpp"

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void key_callback(GLFWwindow *window, int key, int scancode, int action,
                  int mode);

const unsigned int WIDTH = 600;
const unsigned int HEIGHT = 600;

Game breakout(WIDTH, HEIGHT);
int main() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, false);

  GLFWwindow *window =
      glfwCreateWindow(WIDTH, HEIGHT, "Breakout", nullptr, nullptr);
  glfwMakeContextCurrent(window);

  if (!(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  glfwSetKeyCallback(window, key_callback);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  glViewport(0, 0, WIDTH, HEIGHT);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  breakout.Init();

  float deltaTime = 0.0f;
  float lastFrame = 0.0f;

  while (!glfwWindowShouldClose(window)) {
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    breakout.ProcessInput(deltaTime);

    breakout.Update(deltaTime);

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    breakout.Render();
    glfwSwapBuffers(window);
  }
  ResourceManager::Clear();

  glfwTerminate();

  return 0;
}

void key_callback(GLFWwindow *window, int key, int scancode, int action,
                  int mode) {
  // when a user presses the escape key, we set the WindowShouldClose property
  // to true, closing the application
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
  if (key >= 0 && key < 1024) {
    if (action == GLFW_PRESS)
      breakout.Keys[key] = true;
    else if (action == GLFW_RELEASE)
      breakout.Keys[key] = false;
  }
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  // make sure the viewport matches the new window dimensions; note that width
  // and height will be significantly larger than specified on retina displays.
  glViewport(0, 0, width, height);
}
