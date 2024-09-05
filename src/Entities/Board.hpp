#ifndef BOARD_HPP
#define BOARD_HPP

#include "Entity.hpp"
#include "Side.hpp"
#include "Score.hpp"

namespace pong {
  class Board : public Entity {
  public:
    Board() = default;
    Board(Board &&) = default;
    Board(const Board &) = default;
    Board &operator=(Board &&) = default;
    Board &operator=(const Board &) = default;
    ~Board();

    Board(int, int);

    const Point& getTop() const;
    const Point& getBottom() const;
    const Point& getLeft() const;
    const Point& getRight() const;

  private:
    Score *score;
    Point *top;
    Point *bottom;
    Point *left;
    Point *right;

    void setBoundaryPoints();
  };
}

#endif // !BOARD_HPP
