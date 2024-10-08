#ifndef GAMEMODEBUILDER_HPP
#define GAMEMODEBUILDER_HPP

#include <vector>
#include "../Managers/UIManager.hpp"
#include "../Entities/Board.hpp"
#include "../Entities/Score.hpp"
#include "../Entities/Player.hpp"
#include "../Entities/Ball.hpp"
#include "../Managers/TerminalManager.hpp"
#include "GameMode1v1.hpp"
#include "GameMode2v1.hpp"

namespace pong {
  class GameModeBuilder {
  public:
    GameModeBuilder() = default;
    GameModeBuilder(GameModeBuilder &&) = default;
    GameModeBuilder(const GameModeBuilder &) = delete;
    GameModeBuilder &operator=(GameModeBuilder &&) = default;
    GameModeBuilder &operator=(const GameModeBuilder &) = delete;
    ~GameModeBuilder() = default;

    GameModeBuilder& setBoard(TerminalManager::TerminalSize);
    GameModeBuilder& addPlayer1(UIManager*);
    GameModeBuilder& addPlayer2(UIManager*);
    GameModeBuilder& addPlayer3(UIManager*);
    GameModeBuilder& addBall();
    std::unique_ptr<GameMode1v1> build1v1();
    std::unique_ptr<GameMode2v1> build2v1();

  private:
    std::unique_ptr<Board> board;
    std::shared_ptr<Player> player1, player2, player3;
    std::unique_ptr<Ball> ball;

    void setRawMode(bool enable);
    std::string getPlayerName();
  };
}

#endif // !GAMEMODEBUILDER_HPP 
