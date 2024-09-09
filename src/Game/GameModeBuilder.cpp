#include "GameModeBuilder.hpp"

#define getFuncName(val) #val

namespace pong {
  std::string GameModeBuilder::getPlayerName()
  {
    std::string playerName;
    std::cin >> playerName;
    playerName = playerName.substr(0, 5);
    return playerName;
  }

  GameModeBuilder& GameModeBuilder::setBoard(int width, int height)
  {
    board = std::make_unique<Board>(width, height);
    return *this;
  }

  GameModeBuilder& GameModeBuilder::setScore()
  {
    score = std::make_unique<Score>();
    return *this;
  }

  GameModeBuilder& GameModeBuilder::addPlayer1(UIManager *uiManager)
  {
    uiManager->drawInputAddPlayer(getFuncName(addPlayer1));
    std::string playerName = getPlayerName();

    auto racquet = std::make_shared<Racquet>();
    auto player = std::make_shared<Player>(playerName, nullptr, racquet);

    player1 = player;
    sides.emplace_back(std::make_shared<Side>(Side::Position::LEFT, player));
    return *this;
  }

  GameModeBuilder& GameModeBuilder::addPlayer2(UIManager *uiManager)
  {
    uiManager->drawInputAddPlayer(getFuncName(addPlayer2));
    std::string playerName = getPlayerName();

    auto racquet = std::make_shared<Racquet>();
    auto player = std::make_shared<Player>(playerName, nullptr, racquet);

    player2 = player;
    sides.emplace_back(std::make_shared<Side>(Side::Position::RIGHT, player));
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
    ball = std::make_unique<Ball>();
    return *this;
  }

  std::unique_ptr<GameMode1v1> GameModeBuilder::build1v1()
  {
    return std::make_unique<GameMode1v1>(
      std::move(board), std::move(score), std::move(player1),
      std::move(player2), std::move(ball));
  }

  std::unique_ptr<GameMode2v1> GameModeBuilder::build2v1()
  {
    return std::make_unique<GameMode2v1>(
      std::move(board), std::move(score), std::move(player1),
      std::move(player2), std::move(player3),
      std::move(ball));
  }
}
