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

  GameMode::Mode Menu::getSelectedMode()
  {
    int choice;
    std::cin >> choice;

    switch(choice)
    {
      case 1:
        return GameMode::Mode::ONE_ONE;
      case 2:
        return GameMode::Mode::TWO_ONE;
      case 3:
        exit(0);
      default:
        throw std::runtime_error("Opcion Invalida");
    }
  }
}
