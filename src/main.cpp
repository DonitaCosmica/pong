#include "./Game/Game.hpp"
#include "./Game/GameModeBuilder.hpp"
#include "./Game/GameBuilder.hpp"
#include "./Game/Menu.hpp"
#include "./Managers/InputManager.hpp"
#include "./Managers/UIManager.hpp"
#include "./Managers/TerminalManager.hpp"
#include "./Utils/Canvas.hpp"
#include "./Enums/GameState.hpp"

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
      uiManager->drawMenu();
      pong::GameMode::Mode selectedMode = menu.getSelectedMode();

      auto terminalSize = terminalManager->getTerminalSize();
      int terminalWidth = terminalSize.cols - 2;
      int terminalHeight = terminalSize.rows - 2;

      pong::GameModeBuilder builder;
      builder.setBoard(terminalWidth, terminalHeight)
        .setScore()
        .addPlayer1()
        .addPlayer2()
        .addBall();

      std::unique_ptr<pong::GameMode> gameMode;
      if(selectedMode == pong::GameMode::Mode::ONE_ONE)
        gameMode = builder.build1v1();
      else if(selectedMode == pong::GameMode::Mode::TWO_ONE)
        gameMode = builder.addPlayer3().build2v1();

      auto game = pong::Game::Builder()
        .setUIManager(uiManager.get())
        .setInputManager(inputManager.get())
        .setGameMode(gameMode.get())
        .build();

      game->run();
      gameRunning = false;
    }
    catch (const std::exception &e)
    {
      uiManager->showMessage(e.what(), pong::UIManager::MsgType::ERROR);
      uiManager->render(pong::GameState::MENU);
    }
  }

  return 0;
}
