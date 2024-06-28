#ifndef GAME_H
#define GAME_H

#include "GLFW/glfw3.h"

#define uint unsigned int
enum GameState { GAME_ACTIVE, GAME_MENU, GAME_WIN };
class Game {
public:
  GameState State;
  bool Keys[1024];
  uint Width, Height;

public:
  Game(uint width, uint height);

public:
  void Init();
  void ProcessInput(float dt);
  void Update(float dt);
  void Render();
};
#endif
