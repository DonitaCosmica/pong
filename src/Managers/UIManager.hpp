#ifndef UIMANAGER_HPP
#define UIMANAGER_HPP

#include "../Enums/GameState.hpp"
#include "TerminalManager.hpp"
#include "../Utils/Canvas.hpp"
#include "../Entities/Racquet.hpp"
#include "../Entities/Ball.hpp"
#include "../Entities/Side.hpp"
#include <string>
#include <unordered_map>

namespace pong {
  class UIManager {
  public:
    UIManager() = default;
    UIManager(UIManager &&) = default;
    UIManager(const UIManager &) = default;
    UIManager &operator=(UIManager &&) = default;
    UIManager &operator=(const UIManager &) = default;
    ~UIManager() = default;

    UIManager(TerminalManager*);

    enum class MsgType {
      WINNER,
      NORMAL,
      ERROR
    };

    void clearScreen() const;
    void drawBall(const Ball&) const;
    void drawRacquet(const Racquet&, const Side&) const;
    void setBoard(const Canvas::Area&) const;
    void drawMenu() const;
    void drawScore(std::string&, std::string&, int, int) const;
    void drawBorder(const std::string&) const;
    void drawInputAddPlayer(const std::string&) const;

    void render(GameState) const;
    void showMessage(const std::string&, MsgType) const;

  private:
    TerminalManager *terminalManager;
    Canvas canvas;

    const std::unordered_map<MsgType, float> dictionaryYFactor =
    {
      { MsgType::WINNER, 0.25f },
      { MsgType::NORMAL, 0.5f },
      { MsgType::ERROR, 0.7f }
    };

    void showMessages(const std::string&, const Canvas::Area&) const;
    int countLines(const std::string&) const;
    std::string extractIntegerWords(const std::string&) const;
    std::pair<int, int> centerPos(const std::string&, float, const Canvas::Area&) const;
  };
}

#endif // !UIMANAGER_HPP
