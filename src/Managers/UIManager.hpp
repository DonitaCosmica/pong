#ifndef UIMANAGER_HPP
#define UIMANAGER_HPP

#include "TerminalManager.hpp"
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
      SCORE,
      NORMAL,
      ERROR
    };
 
    void drawBall() const;
    void drawRacquet() const;
    void setBoard() const;

    void render() const;
    void showMessages(const std::string&) const;
    void showMessage(const std::string&, MsgType) const; 

  private:
    TerminalManager *terminalManager;

    const std::unordered_map<MsgType, float> dictionaryYFactor =
    {
      { MsgType::SCORE, 0.1f },
      { MsgType::NORMAL, 0.5f },
      { MsgType::ERROR, 0.9f }
    };

    std::pair<int, int> calculateCenteredPosition(int, float) const;
  };
}

#endif // !UIMANAGER_HPP
