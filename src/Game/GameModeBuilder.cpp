#include "GameModeBuilder.hpp"
#include "../Physics/Point.hpp"
#include <termios.h>
#include <unistd.h>

#define BACKGROUND "\033[48;2;0;0;0m"
#define RESET "\033[0m"
#define getFuncName(val) #val

namespace pong {
  void GameModeBuilder::setRawMode(bool enable)
  {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);

    if(enable)
      t.c_lflag &= ~(ICANON | ECHO);
    else
      t.c_lflag |= (ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &t);
  }

  std::string GameModeBuilder::getPlayerName()
  {
    std::string playerName;
    std::cin >> playerName;
    playerName = playerName.substr(0, 5);
    return playerName;
  }

  GameModeBuilder& GameModeBuilder::setBoard(TerminalManager::TerminalSize terminalSize)
  {
    int terminalWidth = terminalSize.cols;
    int terminalHeight = terminalSize.rows - 1;
    int height = terminalHeight / 4;

    Point origin(2, height);
    Point top(terminalWidth / 2, height);
    Point bottom(terminalWidth / 2, terminalHeight - 1);
    Point left(2, height + (3 * height) / 2);
    Point right(terminalWidth - 1, height + (3 * height) / 2);

    std::vector<Point> points = { origin, top, bottom, left, right };
    board = std::make_unique<Board>(points, terminalWidth - 2, 3 * height);
    return *this;
  }

  GameModeBuilder& GameModeBuilder::addPlayer1(UIManager *uiManager)
  {
    uiManager->drawInputAddPlayer(getFuncName(addPlayer1));
    std::string playerName = getPlayerName();

    int racquetHeight = board->getHeight() / 4;
    int racquetWidth = 2;

    Point origin = board->getOrigin();
    Point top(origin.x + 2, origin.y + (racquetHeight / 2));
    Point bottom(origin.x + 2, origin.y + racquetHeight * 1.5f);
    std::vector<Point> points = { top, bottom };

    auto racquet = std::make_shared<Racquet>(points, racquetWidth, racquetHeight);
    auto side = std::make_shared<Side>(Side::Position::LEFT, player1);
    player1 = std::make_shared<Player>(playerName, side, racquet);

    return *this;
  }

  GameModeBuilder& GameModeBuilder::addPlayer2(UIManager *uiManager)
  {
    uiManager->drawInputAddPlayer(getFuncName(addPlayer2));
    std::string playerName = getPlayerName();

    int racquetHeight = board->getHeight() / 4;
    int racquetWidth = 2;

    Point origin = board->getOrigin();
    Point top(origin.x + board->getWidth() - 4, origin.y + (racquetHeight / 2));
    Point bottom(origin.x + board->getWidth() - 4, origin.y + racquetHeight * 1.5f);
    std::vector<Point> points = { top, bottom };

    auto racquet = std::make_shared<Racquet>(points, racquetWidth, racquetHeight);
    auto side = std::make_shared<Side>(Side::Position::RIGHT, player2);
    player2 = std::make_shared<Player>(playerName, side, racquet);
    return *this;
  }

  GameModeBuilder& GameModeBuilder::addPlayer3(UIManager *uiManager)
  {
    uiManager->drawInputAddPlayer(getFuncName(addPlayer3));
    std::string playerName = getPlayerName();

    auto racquet = std::make_shared<Racquet>();
    auto player = std::make_shared<Player>(playerName, nullptr, racquet);

    player3 = player;
    return *this;
  }

  GameModeBuilder& GameModeBuilder::addBall()
  {
    Point origin = board->getOrigin();
    int x = (board->getWidth() + 2) / 2;
    int y = origin.y + board->getHeight() / 2;

    ball = std::make_unique<Ball>(x, y);
    return *this;
  }

  std::unique_ptr<GameMode1v1> GameModeBuilder::build1v1()
  {
    return std::make_unique<GameMode1v1>(std::move(board), std::move(player1),
      std::move(player2), std::move(ball));
  }

  std::unique_ptr<GameMode2v1> GameModeBuilder::build2v1()
  {
    return std::make_unique<GameMode2v1>(std::move(board), std::move(player1),
      std::move(player2), std::move(player3), std::move(ball));
  }
}
