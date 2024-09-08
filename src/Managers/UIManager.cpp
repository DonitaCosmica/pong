#include "UIManager.hpp"
#include <iostream>
#include <algorithm>
#include <unistd.h>
#include <sstream>

namespace pong {
  UIManager::UIManager(TerminalManager *terminalManager) : terminalManager(terminalManager)
  {
    system("clear");

    auto terminalSize = terminalManager->getTerminalSize();
    int terminalWidth = terminalSize.cols;
    int terminalHeight = terminalSize.rows - 1;

    canvas = Canvas(terminalWidth, terminalHeight);
    canvas.defineArea("init", 0, 0, terminalWidth, terminalHeight);
    canvas.defineArea("menu", 0, 0, terminalWidth, terminalHeight);
    canvas.defineArea("score", 0, 0, terminalWidth, terminalHeight / 4);
    canvas.defineArea("game", 0, terminalHeight / 4, terminalWidth, (3 * terminalHeight) / 4 + 3);

    drawBorder("init");
  }

  int UIManager::countLines(const std::string &text) const
  {
    return std::count(text.begin(), text.end(), '\n') + (text.back() != '\n' ? 1 : 0);
  }

  std::pair<int, int> UIManager::centerPos(const std::string &message, float posYFactor, const Canvas::Area &area) const
  {
    int centerX = area.width / 2 - message.size() / 2;
    int centerY = area.height * posYFactor - (countLines(message) / 2);
    return { centerX, centerY };
  }

  void UIManager::drawBorder(const std::string &areaName) const
  {
    const Canvas::Area& borderArea = canvas.getArea(areaName);
    int rows = borderArea.height;
    int cols = borderArea.width;
    int offsetY = borderArea.y;

    std::cout << "\033[" << offsetY << ";0H" << std::string(cols, '#') << std::endl;

    for(int i = 0; i < rows - 2; i++)
      std::cout << "#" << std::string(cols - 2, ' ') << "#\n";

    std::cout << std::string(cols, '#') << std::endl;
  }

  void UIManager::drawMenu() const
  {
    const std::string menu =
      "******************************\n"
      "*       WELCOME TO PONG      *\n"
      "******************************\n"
      "*       1. Play 1 vs 1       *\n"
      "*       2. Play 2 vs 1       *\n"
      "*       3. Exit              *\n"
      "******************************\n"
      "Enter your choice: ";

    showMessages(menu, canvas.getArea("menu"));
  }

  void UIManager::drawScore() const
  {
    const std::string score =
      "******************************\n"
      "*           POINTS           *\n"
      "******************************\n"
      "*   Nombre    **    Nombre   *\n"
      "*     1       **      1      *\n"
      "******************************\n";

    showMessages(score, canvas.getArea("score"));
  }

  void UIManager::showMessage(const std::string &message, MsgType type) const
  {
    const Canvas::Area &area = canvas.getArea(type == MsgType::ERROR ? "menu" : "game");
    auto [centerX, centerY] = centerPos(message, dictionaryYFactor.at(type), area);
    std::cout << "\33[" << centerY + area.y << ";" << centerX + area.x << "H" << message << std::endl;
    usleep(2000000);
  }

  void UIManager::showMessages(const std::string &message, const Canvas::Area &area) const
  {
    int centerY = area.height / 2 - (countLines(message) / 2);
    std::istringstream stream(message);
    std::string line;
    int lineNumber = 0;

    while(std::getline(stream, line))
    {
      int centerX = area.width / 2 - line.size() / 2;
      std::cout << "\033[" << (area.y + centerY + lineNumber) << ";" << centerX + area.x << "H" << line;
      lineNumber++;
    }
  }

  // TODO: Dibujar marcador y borde del juego al llamar una funcion
  // TODO: Adaptar el render para el tipo de canvas
  void UIManager::render(GameState state) const
  {
    const Canvas::Area &area = getArea("menu");
    if(terminalManager->hasTerminalResized())
    {
      system("clear");

      const std::string &areaName = state == GameState::MENU ? "init" ? "game";
      drawBorder(areaName);
      return;
    }

    auto terminalSize = terminalManager->getTerminalSize();
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
