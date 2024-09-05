#include "GameBuilder.hpp"
#include <iostream>
#include <stdexcept>

namespace pong {
  Game::Builder& Game::Builder::setUIManager(UIManager *uiManager)
  {
    this->uiManager = uiManager;
    return *this;
  }

  Game::Builder& Game::Builder::setInputManager(InputManager* inputManager)
  {
    this->inputManager = inputManager;
    return *this;
  }

  Game::Builder& Game::Builder::setGameMode(GameMode* gameMode)
  {
    this->gameMode = gameMode;
    return *this;
  }

  Game* Game::Builder::build() {
    if (!uiManager || !inputManager || !gameMode)
      throw std::runtime_error("Faltan parametros");

    return new Game(uiManager, inputManager, gameMode);
  }
}
