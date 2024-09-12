#ifndef GAMEMODE_HPP
#define GAMEMODE_HPP

#include <memory>
#include <utility>
#include "../Entities/Board.hpp"
#include "../Entities/Player.hpp"
#include "../Entities/Ball.hpp"
#include "../Entities/Score.hpp"

namespace pong {
  class GameMode {
  public:
    GameMode() = default;
    GameMode(GameMode &&) = default;
    GameMode(const GameMode &) = default;
    GameMode &operator=(GameMode &&) = default;
    GameMode &operator=(const GameMode &) = default;
    virtual ~GameMode() = default;

    GameMode(std::unique_ptr<Board>, std::unique_ptr<Score>,
      std::shared_ptr<Player>, std::shared_ptr<Player>, std::unique_ptr<Ball>);

    enum class Mode {
      ONE_ONE,
      TWO_ONE
    };

    Mode getMode() const;
    std::pair<int, int> getScores() const;
    const Board& getBoard() const;
    const Player& getPlayer1() const;
    const Player& getPlayer2() const;
    const Ball& getBall() const;
    virtual std::pair<std::string, std::string> getPlayerNames() const = 0;

  protected:
    Mode mode;
    std::unique_ptr<Board> board;
    std::unique_ptr<Score> score;
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
    std::unique_ptr<Ball> ball;
  };
}

#endif // !GAMEMODE_HPP
