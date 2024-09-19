#include "KeyboardManager.hpp"

namespace pong {
  void KeyboardManager::start()
  {
    initscr();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    cbreak();
    noecho(); 
    curs_set(0); 
    clear();
  }

  int KeyboardManager::getKey() const { return getch(); }
}
