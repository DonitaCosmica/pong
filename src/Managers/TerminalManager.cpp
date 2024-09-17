#include "TerminalManager.hpp"
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>

namespace pong {
  TerminalManager::TerminalManager() { currentSize = fetchTerminalSize(); }

  TerminalManager::TerminalSize TerminalManager::fetchTerminalSize() const
  {
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    return { size.ws_row, size.ws_col };
  }

  TerminalManager::TerminalSize TerminalManager::getTerminalSize()
  {
    if(hasTerminalResized())
      currentSize = fetchTerminalSize();

    return currentSize;
  }

  bool TerminalManager::hasTerminalResized()
  {
    TerminalSize newSize = fetchTerminalSize();
    return newSize.rows != currentSize.rows || newSize.cols != currentSize.cols;
  }
}
