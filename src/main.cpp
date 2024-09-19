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

std::unique_ptr<pong::GameMode> configureGameMode(pong::GameMode::Mode, pong::UIManager*, pong::TerminalManager*);
void runGameLoop(pong::UIManager*, pong::InputManager*, std::unique_ptr<pong::GameMode>&);

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
      uiManager->render(pong::GameState::MENU);
      std::unique_ptr<pong::GameMode> gameMode = configureGameMode(selectedMode, uiManager.get(), terminalManager.get());
      runGameLoop(uiManager.get(), inputManager.get(), gameMode);
    }
    catch (const std::exception &e)
    {
      uiManager->showMessage(e.what(), pong::UIManager::MsgType::ERROR);
      uiManager->render(pong::GameState::MENU);
    }
  }

  return 0;
}

std::unique_ptr<pong::GameMode> configureGameMode(pong::GameMode::Mode selectedMode, pong::UIManager* uiManager, pong::TerminalManager* terminalManager)
{
  pong::GameModeBuilder builder;
  builder.setBoard(terminalManager->getTerminalSize())
    .addPlayer1(uiManager)
    .addPlayer2(uiManager)
    .addBall();

  if (selectedMode == pong::GameMode::Mode::ONE_ONE)
    return builder.build1v1();
  else if (selectedMode == pong::GameMode::Mode::TWO_ONE)
    return builder.addPlayer3(uiManager).build2v1();

  throw std::runtime_error("Modo de juego no válido");
}

void runGameLoop(pong::UIManager* uiManager, pong::InputManager* inputManager, std::unique_ptr<pong::GameMode>& gameMode)
{
  auto game = pong::Game::Builder()
    .setUIManager(uiManager)
    .setInputManager(inputManager)
    .setGameMode(gameMode.get())
    .build();

  game->run();
}
