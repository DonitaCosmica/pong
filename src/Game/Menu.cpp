#include "Menu.hpp"
#include "GameMode1v1.hpp"
#include "GameMode2v1.hpp"
#include <iostream>
#include <stdexcept>

namespace pong {
  Menu& Menu::GetInstance()
  {
    static Menu instance;
    return instance;
  }

  GameMode* Menu::showMenu(UIManager &uiManager)
  {
    const std::string menu = 
      "******************************\n"
      "*       WELCOME TO PONG      *\n"
      "******************************\n"
      "*       1. Play 1 vs 1       *\n"
      "*       2. Play 2 vs 1       *\n"
      "*       3. Exit              *\n"
      "******************************\n"
      "Enter your choice: ";

    uiManager.showMessages(menu);
    GameMode *gameMode = nullptr;

    int choice;
    std::cin >> choice;
    GameMode::Mode selectedMode = static_cast<GameMode::Mode>(choice - 1); 

    switch(selectedMode)
    {
      case GameMode::Mode::ONE_ONE:
        gameMode = new GameMode1v1();
        break;
      case GameMode::Mode::TWO_ONE:
        gameMode = new GameMode2v1();
        break;
      default:
        throw std::runtime_error("Opcion Invalida");
    }

    return gameMode;
  }
}
