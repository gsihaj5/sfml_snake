#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
class Snake : public sf::Drawable {
 private:
  sf::RectangleShape head;
  std::vector<sf::RectangleShape> bodyArray;
  int bodyLength;

 public:
  Snake(sf::Vector2f initialPosition, int bodyLength);
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  void move(sf::Vector2f direction);
};
