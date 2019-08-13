#pragma once
#include <SFML/Graphics.hpp>
unsigned int wWidth = 200;
unsigned int wHight = 200;
sf::RenderWindow window(sf::VideoMode(wWidth, wHight), "SFMLworks");
sf::CircleShape shape(3.f);
sf::Vector2f ShapePozition;
sf::Event event;

