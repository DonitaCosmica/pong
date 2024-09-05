#ifndef TERMINALMANAGER_HPP
#define TERMINALMANAGER_HPP

#include <utility>

namespace pong {
  class TerminalManager {
  public:
    TerminalManager() = default;
    TerminalManager(TerminalManager &&) = default;
    TerminalManager(const TerminalManager &) = default;
    TerminalManager &operator=(TerminalManager &&) = default;
    TerminalManager &operator=(const TerminalManager &) = default;
    ~TerminalManager() = default;

    struct TerminalSize {
      int rows;
      int cols;
    };

    TerminalSize getTerminalSize() const;
    void drawBorder(int, int) const;

  private:
    int borderTop;
    int borderBottom;
    int borderLeft;
    int borderRight;
  };
}

#endif
