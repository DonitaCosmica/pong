#ifndef MENU_HPP
#define MENU_HPP

#include "GameMode.hpp"
#include "../Managers/UIManager.hpp"

namespace pong {
  class Menu {
  public:
    Menu(Menu &&) = delete;
    Menu(const Menu &) = delete;
    Menu &operator=(Menu &&) = delete;
    Menu &operator=(const Menu &) = delete;

    static Menu& GetInstance();
    GameMode::Mode getSelectedMode();

  private:
    Menu() = default;
    ~Menu() = default;
  };
}

#endif // !MENU_HPP
