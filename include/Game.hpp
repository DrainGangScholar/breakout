#ifndef GAME_HPP
#define GAME_HPP
#include "GLFW/glfw3.h"

enum GameState { GAME_ACTIVE, GAME_MENU, GAME_WIN };
class Game {
public:
  GameState State;
  bool Keys[1024];
  unsigned int Width, Height;

public:
  Game(unsigned int width, unsigned int height);

public:
  void Init();
  void ProcessInput(float dt);
  void Update(float dt);
  void Render();
};
#endif
