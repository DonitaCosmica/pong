#include "InputManager.hpp"
#include <iostream>

namespace pong {
  void InputManager::start()
  {
    keyboardManager.start();
  }

  void InputManager::update()
  {
    lastKey = keyboardManager.getKey();
  }
  
  bool InputManager::isKeyPressed(int key) const
  {
    return lastKey == key;
  }
}
