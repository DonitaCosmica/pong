#ifndef TERMINALMANAGER_HPP
#define TERMINALMANAGER_HPP

#include <utility>

namespace pong {
  class TerminalManager {
  public:
    TerminalManager();
    TerminalManager(TerminalManager &&) = default;
    TerminalManager(const TerminalManager &) = default;
    TerminalManager &operator=(TerminalManager &&) = default;
    TerminalManager &operator=(const TerminalManager &) = default;
    ~TerminalManager() = default;

    struct TerminalSize {
      int rows;
      int cols;
    };

    TerminalSize getTerminalSize();
    void drawBorder(int, int) const;
    bool hasTerminalResized();

  private:
    TerminalSize currentSize;

    TerminalSize fetchTerminalSize() const;
  };
}

#endif
