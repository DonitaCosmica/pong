#include "RacquetManager.hpp"

namespace pong {
  float RacquetManager::speed = 1.5f;

  void RacquetManager::moveUp(Racquet &racquet, const Board &board)
  {
    Point top = racquet.getTop();
    Point bottom = racquet.getBottom();

    if(top.y - speed >= board.getTop().y)
    {
      top.y -= speed;
      bottom.y -= speed;
      racquet.setPosition(top, bottom);
    }
  }

  void RacquetManager::moveDown(Racquet &racquet, const Board &board)
  {
    Point top = racquet.getTop();
    Point bottom = racquet.getBottom();

    if(bottom.y + speed <= board.getBottom().y)
    {
      top.y += speed;
      bottom.y += speed;
      racquet.setPosition(top, bottom);
    }
  }
}
