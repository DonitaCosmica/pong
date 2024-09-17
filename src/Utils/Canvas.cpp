#include "Canvas.hpp"

namespace pong {
  Canvas::Canvas(int totalWidth, int totalHeight) :
    totalWidth(totalWidth), totalHeight(totalHeight) {}

  void Canvas::defineArea(const std::string &name, int x, int y, int width, int height)
  {
    areas[name] = { x, y, width, height };
  }

  void Canvas::updateSize(int newWidth, int newHeight)
  {
    float widthRatio = static_cast<float>(newWidth) / totalWidth;
    float heightRatio = static_cast<float>(newHeight) / totalHeight;

    for(auto &[name, area] : areas)
    {
      area.width = static_cast<int>(area.width * widthRatio);
      area.height = static_cast<int>(area.height * heightRatio);
      area.x = static_cast<int>(area.x * widthRatio);
      area.y = static_cast<int>(area.y * heightRatio);

      if (area.width < 0) area.width = 0;
      if (area.height < 0) area.height = 0;
      if (area.x < 0) area.x = 0;
      if (area.y < 0) area.y = 0;
    }

    totalWidth = newWidth;
    totalHeight = newHeight;
  }

  const Canvas::Area& Canvas::getArea(const std::string &name) const
  {
    return areas.at(name);
  }
}
