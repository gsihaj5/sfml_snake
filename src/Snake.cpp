#include "Snake.h"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>

Snake::Snake(sf::Vector2f initialPosition, int bodyLength)
    : bodyLength(bodyLength) {

  head = sf::RectangleShape({50, 50});
  head.setFillColor(sf::Color(200, 250, 50));
  head.setPosition({initialPosition.x * 50, initialPosition.y * 50});

  for (int i = 1; i < bodyLength; i++) {
    sf::RectangleShape newBody = sf::RectangleShape({50, 50});
    newBody.setFillColor(sf::Color(100, 250, 50));
    newBody.setPosition({initialPosition.x * 50, (initialPosition.y + i) * 50});
    bodyArray.emplace_back(newBody);
  }
};

void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(head, states);
  for (int i = 0; i < bodyArray.size(); i++) {
    target.draw(bodyArray[i], states);
  }
}

void Snake::move(sf::Vector2f direction) {
  sf::Vector2f prev = head.getPosition();

  head.setPosition({head.getPosition().x + direction.x * 50,
                    head.getPosition().y + direction.y * 50});

  for (int i = 0; i < bodyArray.size(); i++) {
    sf::Vector2f temppos = bodyArray[i].getPosition();
    bodyArray[i].setPosition(prev);
    prev = temppos;
  }
}
