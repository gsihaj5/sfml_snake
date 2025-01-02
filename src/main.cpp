#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include "Snake.h"

int main() {
  auto window =
      sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");

  float xDir = 1;
  float yDir = 1;
  float tresshold = 600.f;
  float speed = 50.f;
  sf::Clock clock;
  window.setFramerateLimit(5);
  sf::Vector2f direction = {0, -1};

  Snake snake(sf::Vector2f(5, 5), 3);

  while (window.isOpen()) {
    float currentTime = clock.restart().asSeconds();
    float fps = 1.0f / currentTime;
    std::cout << "FPS: " << fps << "\n";
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }
    window.clear();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A)) {
      direction = {-1, 0};
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)) {
      direction = {0, -1};
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D)) {
      direction = {1, 0};
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S)) {
      direction = {0, 1};
    }

    snake.move(direction);
    window.draw(snake);
    window.display();
  }
}
