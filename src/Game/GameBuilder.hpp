#ifndef GAMEBUILDER_HPP
#define GAMEBUILDER_HPP

#include "Game.hpp"
#include "GameMode.hpp"
#include "../Managers/InputManager.hpp"
#include "../Managers/UIManager.hpp"

namespace pong {
  class Game::Builder {
  public:
    Builder &setUIManager(UIManager *uiManager);
    Builder &setInputManager(InputManager *inputManager);
    Builder &setGameMode(GameMode *gameMode);
    Game *build();

  private:
    UIManager* uiManager = nullptr;
    InputManager* inputManager = nullptr; 
    GameMode* gameMode = nullptr;
  };
}

#endif // !GAMEBUILDER_HPP
