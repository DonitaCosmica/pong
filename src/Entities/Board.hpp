#ifndef BOARD_HPP
#define BOARD_HPP

#include "Entity.hpp"
#include "Ball.hpp"
#include "Score.hpp"
#include "Side.hpp"

namespace pong {
  class Board : public Entity {
  public:
    Board() = default;
    Board(Board &&) = default;
    Board(const Board &) = default;
    Board &operator=(Board &&) = default;
    Board &operator=(const Board &) = default;
    ~Board() = default;

    Board(int, int);

    const Point& getTop() const;
    const Point& getBottom() const;
    const Point& getLeft() const;
    const Point& getRight() const;

  private:
    Ball *ball; 
    Side *leftSide;
    Side *rightSide;
    Score *score;
  };
}

#endif // !BOARD_HPP
