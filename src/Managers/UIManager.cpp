#include "UIManager.hpp"
#include <iostream>
#include <algorithm>
#include <unistd.h>
#include <sstream>
#include <cctype>

#define COLPLAYER 3
#define RED "\033[91m"
#define BLUE "\033[94m"
#define BLACK "\033[30m"
#define GREEN "\033[92m"
#define YELLOW "\033[93m"
#define CYAN "\033[96m"
#define RESET "\033[0m"

namespace pong {
  UIManager::UIManager(TerminalManager *terminalManager) : terminalManager(terminalManager)
  {
    clearScreen();

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

  std::string UIManager::extractIntegerWords(const std::string &str) const
  {
    auto it = std::find_if(str.begin(), str.end(), ::isdigit);
    if(it != str.end())
      return std::string(1, *it);

    return "0";
  }

  void UIManager::clearScreen() const { system("clear"); }

  void UIManager::drawBorder(const std::string &areaName) const
  {
    const Canvas::Area& borderArea = canvas.getArea(areaName);
    int rows = borderArea.height;
    int cols = borderArea.width;
    int offsetY = borderArea.y;

    std::cout << "\033[" << offsetY << ";0H";
    std::cout << BLACK << std::string(cols, '#') << RESET << std::endl;
    for(int i = 0; i < rows - 2; i++)
      std::cout << BLACK << "#" << RESET << std::string(cols - 2, ' ') << BLACK << "#" << RESET << std::endl;

    std::cout << BLACK << std::string(cols, '#') << RESET << std::endl;
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

  void UIManager::drawScore(std::string &player1Name, std::string &player2Name, int pointsPlayer1, int pointsPlayer2) const
  {
    const Canvas::Area &scoreArea = canvas.getArea("score");
    const std::string score =
      "******************************\n"
      "*           POINTS           *\n"
      "******************************\n"
      "*             **             *\n"
      "*             **             *\n"
      "******************************\n"; 

    showMessages(score, canvas.getArea("score"));

    std::transform(player1Name.begin(), player1Name.end(), player1Name.begin(), ::toupper);
    std::transform(player2Name.begin(), player2Name.end(), player2Name.begin(), ::toupper);

    int scoreLength = score.size() / countLines(score);
    int namesRow = (scoreArea.height / 2) - (countLines(score) / 2) + COLPLAYER;
    int pointsRow = namesRow + 1;
    int startWriteCell = (scoreArea.width / 2) - (scoreLength / 2);

    int player1Col = startWriteCell + player1Name.size();
    std::cout << "\033[" << namesRow << ";" << (player1Name.size() == 5 ? player1Col : player1Col + 1) << "H" << BLUE << player1Name << RESET;
    std::cout << "\033[" << pointsRow << ";" << (player1Col + 2) << "H" << pointsPlayer1;

    int player2Col = startWriteCell + (scoreLength / 2) + player2Name.size();
    std::cout << "\033[" << namesRow << ";" << (player2Name.size() == 5 ? player2Col : player2Col + 1) << "H" << RED << player2Name << RESET;
    std::cout << "\033[" << pointsRow << ";" << (player2Col + 2) << "H" << pointsPlayer2;
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

    showMessages(inputAddPlayer, menuArea);

    int inputRow = (menuArea.height / 2) - (countLines(inputAddPlayer) / 2) + COLPLAYER;
    int inputCol = menuArea.width / 2 - 2;
    std::cout << "\033[" << inputRow << ";" << inputCol << "H";
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
          ? std::cout << RED << "#" << RESET << std::endl
          : std::cout << BLUE << "#" << RESET << std::endl;
      }
    }
  }

  void UIManager::drawBall(const Ball& ball) const
  {
    int x = ball.getPoint().x;
    int y = ball.getPoint().y;

    std::cout << "\033[" << y << ";" << x << "H";
    std::cout << BLACK << "●" << RESET << std::endl;
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
        std::cout << GREEN << message << RESET << std::endl;
        break;
      case MsgType::ERROR:
        std::cout << RED << message << RESET << std::endl;
        break;
    }

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
    const Canvas::Area &area = canvas.getArea("menu");
    if(terminalManager->hasTerminalResized())
    {
      system("clear");

      const std::string &areaName = state == GameState::MENU ? "init" : "game";
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
