#ifndef KEYBOARDMANAGER_HPP
#define KEYBOARDMANAGER_HPP

#include <ncurses.h>

namespace pong {
  class KeyboardManager {
  public:
    KeyboardManager() = default;
    KeyboardManager(KeyboardManager &&) = default;
    KeyboardManager(const KeyboardManager &) = default;
    KeyboardManager &operator=(KeyboardManager &&) = default;
    KeyboardManager &operator=(const KeyboardManager &) = default;
    ~KeyboardManager();

    void start();
    int getKey() const;
  };
}

#endif // !KEYBOARDMANAGER_HPP
