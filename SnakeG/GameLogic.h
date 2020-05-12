#pragma once
#include<iostream>
#include"Graphics.h"
#include"Input.h"
#include<list>

enum Direction
{
	dUP, dDOWN, dRIGHT, dLEFT
};


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
	Direction dirSnake = dRIGHT;
};

Snake::Snake()
{
	body.push_front(sf::Vector2f(10, 10));
	body.push_front(sf::Vector2f(10 + snakeThickness * 2, 10));
	body.push_front(sf::Vector2f(10 + snakeThickness * 4, 10));
}

void Snake::SnakeUpdate(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Key::Right || key == sf::Keyboard::Key::Numpad6)
	{
		//Right
		if (dirSnake != dLEFT) // дл€ того что бы не мен€ть направление в одной плоскости
		{
			dirSnake = dRIGHT; // мен€ем направление
			if (body.front().x >= wWidth)
				body.push_front(sf::Vector2f(0, body.front().y)); // добавл€ем в начало один элемент если дошли до кра€ пол€
			else
				body.push_front(sf::Vector2f(body.front().x + snakeThickness * 2, body.front().y)); // добавл€ем в начало один элемент если Ќ≈ дошли до кра€ пол€
			body.pop_back(); // удал€ем с конца один элемент
		}
	}
	else if (key == sf::Keyboard::Key::Left || key == sf::Keyboard::Key::Numpad4)
	{
		//Left
		if (dirSnake != dRIGHT)
		{
			dirSnake = dLEFT;
			if (body.front().x <= 0)
				body.push_front(sf::Vector2f(wWidth, body.front().y));
			else
				body.push_front(sf::Vector2f(body.front().x - snakeThickness * 2, body.front().y));
			body.pop_back();
		}
	}
	else if (key == sf::Keyboard::Key::Down || key == sf::Keyboard::Key::Numpad2)
	{
		//Down
		if (dirSnake != dUP)
		{
			dirSnake = dDOWN;
			if (body.front().y >= wHight)
				body.push_front(sf::Vector2f(body.front().x, 0));
			else
				body.push_front(sf::Vector2f(body.front().x, body.front().y + snakeThickness * 2));
			body.pop_back();
		}
	}
	else if (key == sf::Keyboard::Key::Up || key == sf::Keyboard::Key::Numpad8)
	{
		//Up
		if (dirSnake != dDOWN)
		{
			dirSnake = dUP;
			if (body.front().y <= 0)
				body.push_front(sf::Vector2f(body.front().x, wHight));
			else
				body.push_front(sf::Vector2f(body.front().x, body.front().y - snakeThickness * 2));
			body.pop_back();
		}
	}
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