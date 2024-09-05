#include "TerminalManager.hpp"
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>

namespace pong {
  TerminalManager::TerminalSize TerminalManager::getTerminalSize() const
  {
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    return { size.ws_row, size.ws_col };
  }

  void TerminalManager::drawBorder(int rows, int cols) const
  {
    for (int i = 0; i < cols; i++) std::cout << "#";
    std::cout << std::endl;

    for (int i = 0; i < rows - 2; i++) {
      std::cout << "#";
      for (int j = 0; j < cols - 2; j++) std::cout << " ";
      std::cout << "#" << std::endl;
    }

    for (int i = 0; i < cols; i++) std::cout << "#";
    std::cout << std::endl;
  }
}
