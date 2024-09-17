#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include "KeyboardManager.hpp"

namespace pong {
  class InputManager {
  public:
    InputManager() = default;
    InputManager(InputManager &&) = default;
    InputManager(const InputManager &) = default;
    InputManager &operator=(InputManager &&) = default;
    InputManager &operator=(const InputManager &) = default;
    ~InputManager() = default;

    void start();
    void update();
    bool isKeyPressed(int) const;

  private:
    mutable int lastKey = ERR;
    KeyboardManager keyboardManager;
  };
}

#endif // !INPUTMANAGER_HPP
