#include "Canvas.hpp"

namespace pong {
  Canvas::Canvas(int totalWidth, int totalHeight) :
    totalWidth(totalWidth), totalHeight(totalHeight) {}

  void Canvas::defineArea(const std::string &name, int x, int y, int width, int height)
  {
    areas[name] = { x, y, width, height };
  }

  const Canvas::Area& Canvas::getArea(const std::string &name) const
  {
    return areas.at(name);
  }
}
