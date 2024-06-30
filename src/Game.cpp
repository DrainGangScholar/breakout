#include "../include/Game.hpp"

Game::Game(unsigned int width, unsigned int height) {
  this->State = GAME_ACTIVE;
  this->Width = width;
  this->Height = height;
}
void Game::Init() {}
void Game::ProcessInput(float dt) {}
void Game::Update(float dt) {}
void Game::Render() {}
