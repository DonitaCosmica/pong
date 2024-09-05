#ifndef SIDE_HPP
#define SIDE_HPP

namespace pong {
  class Entity {
  public:
    Entity() = default;
    Entity(Entity &&) = default;
    Entity(const Entity &) = default;
    Entity &operator=(Entity &&) = default;
    Entity &operator=(const Entity &) = default;
    ~Entity() = default;

  private:
    
  };
}

#endif // !SIDE_HPP
