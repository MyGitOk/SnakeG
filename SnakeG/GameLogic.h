#pragma once
#include<iostream>
#include"Graphics.h"
#include"Input.h"
#include<list>

class Snake
{
public:
	Snake();
	void SnakeUpdate(sf::Keyboard::Key d);
	void SnakeDraw();
	
	~Snake();


private:
	list<sf::Vector2f> body;
	float snakeThickness = 3;
};

Snake::Snake()
{
	body.push_front(sf::Vector2f(10 , 10));
	body.push_front(sf::Vector2f(10 + snakeThickness * 2, 10));
	body.push_front(sf::Vector2f(10 + snakeThickness * 4, 10));
}

void Snake::SnakeUpdate(sf::Keyboard::Key d)
{
	switch (d)
	{
	case sf::Keyboard::Key::Right:
		body.push_front(sf::Vector2f(body.front().x + snakeThickness * 2, body.front().y));
		break;
	case sf::Keyboard::Key::Left:
		body.push_front(sf::Vector2f(body.front().x - snakeThickness * 2, body.front().y));
		break;
	case sf::Keyboard::Key::Down:
		body.push_front(sf::Vector2f(body.front().x, body.front().y + snakeThickness * 2));
		break;
	case sf::Keyboard::Key::Up:
		body.push_front(sf::Vector2f(body.front().x, body.front().y - snakeThickness * 2));
		break;
	}

	body.pop_back();
}
void Snake::SnakeDraw()
{
	sf::CircleShape bodyPart(snakeThickness);
	for (sf::Vector2f n : body)
	{
		bodyPart.setPosition(n);
		bodyPart.setFillColor(sf::Color::Red);
		window.draw(bodyPart);
	}
}

Snake::~Snake()
{
}