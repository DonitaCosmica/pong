#include "UIManager.hpp"
#include <iostream>
#include <unistd.h>
#include <sstream>

namespace pong {
  UIManager::UIManager(TerminalManager *terminalManager) : terminalManager(terminalManager)
  {
    system("clear");
    TerminalManager::TerminalSize terminalSize = terminalManager->getTerminalSize();
    terminalManager->drawBorder(terminalSize.rows, terminalSize.cols);
  }

  std::pair<int, int> UIManager::calculateCenteredPosition(int sizeMsg, float positionYFactor) const
  {
    TerminalManager::TerminalSize terminalSize = terminalManager->getTerminalSize();
    int centerX = terminalSize.cols / 2 - sizeMsg / 2;
    int centerY = terminalSize.rows * positionYFactor - 4;

    return { centerX, centerY };
  }

  void UIManager::showMessage(const std::string &message, MsgType type) const
  {
    std::cout << "\033[H";

    float positionYFactor = dictionaryYFactor.at(type);
    auto [centerX, centerY] = calculateCenteredPosition(message.size(), positionYFactor);
    std::cout << "\33[" << centerY << ";" << centerX << "H" << message << std::endl;

    if(type == MsgType::ERROR)
    {
      usleep(2000000);
      render();
    }
  }

  void UIManager::showMessages(const std::string &message) const
  {
    TerminalManager::TerminalSize size = terminalManager->getTerminalSize();
    std::cout << "\033[H";

    int centerY = size.rows / 2 - 4;
    std::istringstream stream(message);
    std::string line;
    int lineNumber = 0;

    while(std::getline(stream, line))
    {
      int centerX = size.cols / 2 - line.size() / 2;
      std::cout << "\033[" << (centerY + lineNumber) << ";" << centerX << "H" << line;
      lineNumber++;
    }
  }

  void UIManager::render() const
  {
    TerminalManager::TerminalSize terminalSize = terminalManager->getTerminalSize();
    std::cout << "\033[" << 1 << ";" << 1 << "H";

    int borderThickness = 1;
    int height = terminalSize.rows - 2;
    int width = terminalSize.cols - 2;

    std::cout << "\033[" << (borderThickness + 1) << ";" << (borderThickness + 1) << "H";

    for(int i = 0; i < height; i++)
    {
      std::cout << std::string(width, ' ');
      std::cout << "\033[" << (borderThickness + i +1) << ";" << (borderThickness + 1) << "H";
    }

    std::cout << "\033[" << (borderThickness + height + 1) << ";" << (borderThickness + 1) << "H";
  }
}
