#pragma once
#include <SFML\Graphics.hpp>

bool snakeAlive = true;
float cell = 12;
unsigned int wWidth = cell * 20;
unsigned int wHight = wWidth;

sf::RenderWindow window(sf::VideoMode(wWidth, wHight), "SFMLworks");
sf::Event event;
int speed;


sf::CircleShape food(cell / 2);
sf::Vector2f FoodPozition;
