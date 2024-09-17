#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <unordered_map>
#include <string>

namespace pong {
  class Canvas {
  public:
    Canvas() = default;
    Canvas(Canvas &&) = default;
    Canvas(const Canvas &) = default;
    Canvas &operator=(Canvas &&) = default;
    Canvas &operator=(const Canvas &) = default;
    ~Canvas() = default;

    enum class AreaType {
      INIT,
      MENU,
      SCORE,
      GAME
    };

    struct Area {
      int x;
      int y;
      int width;
      int height;
    };

    Canvas(int, int);

    void defineArea(const std::string&, int, int, int, int);
    void updateSize(int, int);
    const Area& getArea(const std::string&) const;

  private:
    int totalWidth;
    int totalHeight;
    std::unordered_map<std::string, Area> areas;
  };
}

#endif // !CANVAS_HPP
