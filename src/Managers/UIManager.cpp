#include "UIManager.hpp"
#include <iostream>
#include <algorithm>
#include <unistd.h>
#include <sstream>
#include <cctype>

#define COLPLAYER 4
#define BACKGROUND "\033[48;2;0;0;0m"
#define RED "\033[38;2;255;0;0m"
#define BLUE "\033[38;2;0;0;255m"
#define YELLOW "\033[38;2;255;255;0m"
#define GREEN "\033[38;2;0;255;0m"
#define RESET "\033[0m"

namespace pong {
  UIManager::UIManager(TerminalManager *terminalManager) : terminalManager(terminalManager)
  {
    clearScreen();

    auto terminalSize = terminalManager->getTerminalSize();
    int terminalWidth = terminalSize.cols;
    int terminalHeight = terminalSize.rows - 1;

    canvas = Canvas(terminalWidth, terminalHeight);
    canvas.defineArea("init", 1, 1, terminalWidth, terminalHeight);
    canvas.defineArea("menu", 1, 1, terminalWidth, terminalHeight);
    canvas.defineArea("score", 1, 1, terminalWidth, terminalHeight / 4);
    canvas.defineArea("game", 1, terminalHeight / 4 - 1, terminalWidth, (3 * terminalHeight) / 4 + 3);

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

  std::string UIManager::extractIntegerWords(const std::string &str) const
  {
    auto it = std::find_if(str.begin(), str.end(), ::isdigit);
    if(it != str.end())
      return std::string(1, *it);

    return "0";
  }

  void UIManager::clearScreen() const { system("clear"); }

  void UIManager::drawBackground(const Canvas::Area &area) const
  {
    for(int i = 1; i < area.height - 1; i++)
    {
      std::cout << "\033[" << (area.y + i) << ";" << area.x << "H";
      std::cout << BACKGROUND << std::string(area.width, ' ') << RESET;
    }
  }

  void UIManager::drawBorder(const std::string &areaName) const
  {
    const Canvas::Area& borderArea = canvas.getArea(areaName);
    int rows = borderArea.height;
    int cols = borderArea.width;
    int offsetY = borderArea.y;
    int offsetX = borderArea.x;

    std::cout << "\033[" << offsetY << ";" << offsetX << "H";
    std::cout << BACKGROUND << std::string(cols, '#') << RESET;
    for(int i = 1; i < rows - 1; i++)
    {
      std::cout << "\033[" << (offsetY + i) << ";" << offsetX << "H";
      std::cout << BACKGROUND << "#" << std::string(cols - 2, ' ') << "#" << RESET;
    }

    std::cout << "\033[" << (offsetY + rows - 1) << ";" << offsetX << "H";
    std::cout << BACKGROUND << std::string(cols, '#') << RESET;
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

    showMessages(menu, canvas.getArea("menu"), MsgType::NORMAL);
  }

  void UIManager::drawScore(std::string &player1Name, std::string &player2Name) const
  {
    const Canvas::Area &scoreArea = canvas.getArea("score");
    drawBackground(scoreArea);

    const std::string score =
      "******************************\n"
      "*           POINTS           *\n"
      "******************************\n"
      "*             **             *\n"
      "*             **             *\n"
      "******************************\n"; 

    showMessages(score, scoreArea, MsgType::NORMAL);

    std::transform(player1Name.begin(), player1Name.end(), player1Name.begin(), ::toupper);
    std::transform(player2Name.begin(), player2Name.end(), player2Name.begin(), ::toupper);

    int scoreLength = score.size() / countLines(score);
    int namesRow = (scoreArea.height / 2) - (countLines(score) / 2) + COLPLAYER;
    int startWriteCell = (scoreArea.width / 2) - (scoreLength / 2);

    int player1Col = startWriteCell + player1Name.size() + 1;
    std::cout << "\033[" << namesRow << ";" << (player1Name.size() == 5 ? player1Col : player1Col + 1) << "H" << BACKGROUND << player1Name << RESET;

    int player2Col = startWriteCell + (scoreLength / 2) + player2Name.size() + 1;
    std::cout << "\033[" << namesRow << ";" << (player2Name.size() == 5 ? player2Col : player2Col + 1) << "H" << BACKGROUND << player2Name << RESET;
  }

  void UIManager::drawPoints(const Side &side, int pointsPlayer, std::string &playerName)
  {
    const Canvas::Area &scoreArea = canvas.getArea("score");
    int scoreLength = 31;
    int pointsRow = (scoreArea.height / 2) + 2;
    int startWriteCell = (scoreArea.width / 2) - (scoreLength / 2);
    int playerCol = startWriteCell + (side.isLeft() ? 0 : (scoreLength / 2)) + playerName.size() + 3;

    std::cout << "\033[" << pointsRow << ";" << playerCol << "H" << BACKGROUND << pointsPlayer << RESET;
  }

  void UIManager::drawInputAddPlayer(const std::string &player) const
  {
    const Canvas::Area &menuArea = canvas.getArea("menu");
    const std::string inputAddPlayer =
      "******************************\n"
      "*          PLAYER " + extractIntegerWords(player) + "          *\n"
      "******************************\n"
      "*                            *\n"
      "******************************\n";

    showMessages(inputAddPlayer, menuArea, MsgType::NORMAL);

    int inputRow = (menuArea.height / 2) - (countLines(inputAddPlayer) / 2) + COLPLAYER;
    int inputCol = menuArea.width / 2 - 1;
    std::cout << "\033[" << inputRow << ";" << inputCol << "H";
  }

  void UIManager::drawWinner(std::string &winner) const
  {
    const Canvas::Area &gameArea = canvas.getArea("game");
    const std::string winnerBoardTop =
      "******************************\n"
      "*           WINNER           *\n"
      "******************************\n"
      "*                            *\n";

    const std::string winnerBoardBottom =
      "******************************\n";

    auto [centerX, centerY] = centerPos(winner, 0.75f, gameArea);
    showMessages(winnerBoardTop, gameArea, MsgType::WINNER);
    std::transform(winner.begin(), winner.end(), winner.begin(), ::toupper);

    std::cout << "\033[" << (centerY + 2)<< ";" << (centerX + 1) << "H";
    std::cout << BACKGROUND << YELLOW << winner << RESET;
    std::cout << "\033[" << (centerY + 3) << ";" << (centerX - (winnerBoardBottom.size() / 2) + 3) << "H";
    std::cout << BACKGROUND << YELLOW << winnerBoardBottom << RESET;
    usleep(5000000);
  }

  void UIManager::drawRacquet(const Racquet &racquet, const Side &side) const
  {
    int x = racquet.getTop().x;
    int y = racquet.getTop().y;

    for(int i = 0; i < racquet.getHeight() + 1; i++)
    {
      for(int j = 0; j < racquet.getWidth(); j++)
      {
        std::cout << "\033[" << (y + i) << ";" << (x + j) << "H";
        side.isLeft()
          ? std::cout << RED << BACKGROUND << "#" << RESET << std::endl
          : std::cout << BLUE << BACKGROUND << "#" << RESET << std::endl;
      }
    }
  }

  void UIManager::drawBall(const Ball& ball) const
  {
    int x = ball.getPosition().x;
    int y = ball.getPosition().y;

    std::cout << "\033[" << y << ";" << x << "H";
    std::cout << BACKGROUND << "●" << RESET << std::endl;
  }

  void UIManager::showMessage(const std::string &message, MsgType type) const
  {
    const Canvas::Area &area = canvas.getArea(type == MsgType::ERROR ? "menu" : "game");
    auto [centerX, centerY] = centerPos(message, dictionaryYFactor.at(type), area);
    std::cout << "\33[" << centerY + area.y << ";" << centerX + area.x << "H";

    switch(type)
    {
      case MsgType::WINNER:
        std::cout << YELLOW << message << RESET << std::endl;
        break;
      case MsgType::NORMAL:
        std::cout << message << std::endl;
        break;
      case MsgType::ERROR:
        std::cout << RED << message << RESET << std::endl;
    }

    usleep(2000000);
  }

  void UIManager::showMessages(const std::string &message, const Canvas::Area &area, MsgType type) const
  {
    int centerY = area.height / 2 - (countLines(message) / 2);
    std::istringstream stream(message);
    std::string line;
    int lineNumber = 0;

    while(std::getline(stream, line))
    {
      int centerX = area.width / 2 - line.size() / 2;
      std::cout << "\033[" << (area.y + centerY + lineNumber) << ";" << (centerX + area.x) << "H";

      switch(type)
      {
        case MsgType::WINNER:
          std::cout << BACKGROUND << YELLOW << line << RESET;
          break;
        case MsgType::NORMAL:
          std::cout << BACKGROUND << line << RESET;
          break;
        case MsgType::ERROR:
          std::cout << BACKGROUND << RED << line<< RESET;
      }
 
      lineNumber++;
    }
  }

  void UIManager::render(GameState state)
  {
    const std::string &areaName = state == GameState::MENU ? "menu" : "game";
    const Canvas::Area &area = canvas.getArea(areaName);

    if(terminalManager->hasTerminalResized())
    {
      auto terminalSize = terminalManager->getTerminalSize();
      int terminalWidth = terminalSize.cols;
      int terminalHeight = terminalSize.rows - 1;
      canvas.updateSize(terminalWidth, terminalHeight);

      clearScreen();
      drawBorder(areaName);
      return;
    }

    int borderThickness = 1;
    int height = area.height - 2;
    int width = area.width - 2;

    std::cout << "\033[" << (borderThickness + area.y) << ";" << (borderThickness + area.x) << "H";

    for(int i = 0; i < height; i++)
    {
      std::cout << "\033[" << (borderThickness + i + area.y) << ";" << (borderThickness + area.x) << "H";
      std::cout << BACKGROUND << std::string(width, ' ') << RESET;
    }

    std::cout << "\033[" << (borderThickness + area.y) << ";" << (borderThickness + area.x) << "H";
  }
}
