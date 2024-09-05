#include "./Game/Game.hpp"
#include "./Game/GameBuilder.hpp"
#include "./Game/Menu.hpp"
#include "./Managers/InputManager.hpp"
#include "./Managers/UIManager.hpp"
#include "./Managers/TerminalManager.hpp"

#include <iostream>
#include <memory>

int main (int argc, char *argv[])
{
  std::unique_ptr<pong::InputManager> inputManager = std::make_unique<pong::InputManager>();
  std::unique_ptr<pong::TerminalManager> terminalManager = std::make_unique<pong::TerminalManager>();
  std::unique_ptr<pong::UIManager> uiManager = std::make_unique<pong::UIManager>(terminalManager.get());
  pong::Menu& menu = pong::Menu::GetInstance();

  bool gameRunning = true;
  while(gameRunning)
  {
    try
    {
      pong::GameMode *selectedMode = menu.showMenu(*uiManager);
      selectedMode->initializeGame();

      pong::Game *game = pong::Game::Builder()
        .setUIManager(uiManager.get())
        .setInputManager(inputManager.get())
        .setGameMode(selectedMode)
        .build();

      game->run();
      gameRunning = false;

      delete game;
      delete selectedMode;
    }
    catch (const std::exception &e)
    {
      uiManager->showMessage(e.what(), pong::UIManager::MsgType::ERROR); 
    }
  }

  return 0;
}
