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
	void SnakeMove();
	void SnakeDraw();

	~Snake();


private:
	list<sf::Vector2f> body;
	float snakeThickness = cell;
	Direction dirSnake = dRIGHT;
};

Snake::Snake()
{
	body.push_front(sf::Vector2f(snakeThickness, cell * 4));		// x:  6  y: 24
	body.push_front(sf::Vector2f(snakeThickness * 2, cell * 4));	// x: 12  y: 24
	body.push_front(sf::Vector2f(snakeThickness * 3, cell * 4));	// x: 18  y: 24
}

void Snake::SnakeUpdate(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Key::Right || key == sf::Keyboard::Key::Numpad6)
	{
		//Right
		if (dirSnake != dLEFT) // ��� ���� ��� �� �� ������ ����������� � ����� ���������
			dirSnake = dRIGHT; // ������ �����������
	}
	else if (key == sf::Keyboard::Key::Left || key == sf::Keyboard::Key::Numpad4)
	{
		//Left
		if (dirSnake != dRIGHT)
			dirSnake = dLEFT;
	}
	else if (key == sf::Keyboard::Key::Down || key == sf::Keyboard::Key::Numpad2)
	{
		//Down
		if (dirSnake != dUP)
			dirSnake = dDOWN;
	}
	else if (key == sf::Keyboard::Key::Up || key == sf::Keyboard::Key::Numpad8)
	{
		//Up
		if (dirSnake != dDOWN)
			dirSnake = dUP;
	}
}
void Snake::SnakeMove()
{
	switch (dirSnake)
	{
	case dRIGHT:
		if (body.front().x >= wWidth)
			body.push_front(sf::Vector2f(0, body.front().y)); // ��������� � ������ ���� ������� ���� ����� �� ���� ����
		else
			body.push_front(sf::Vector2f(body.front().x + snakeThickness, body.front().y)); // ��������� � ������ ���� ������� ���� �� ����� �� ���� ����
		break;
	case dLEFT:
		if (body.front().x <= 0)
			body.push_front(sf::Vector2f(wWidth, body.front().y));
		else
			body.push_front(sf::Vector2f(body.front().x - snakeThickness, body.front().y));
		break;
	case dDOWN:
		if (body.front().y >= wHight)
			body.push_front(sf::Vector2f(body.front().x, 0));
		else
			body.push_front(sf::Vector2f(body.front().x, body.front().y + snakeThickness));
		break;
	case dUP:
		if (body.front().y <= 0)
			body.push_front(sf::Vector2f(body.front().x, wHight));
		else
			body.push_front(sf::Vector2f(body.front().x, body.front().y - snakeThickness));
		break;
	default:
		break;
	}
	
	// g������� �� �������� ������
	int i = 0;
	for (sf::Vector2f n : body) 
	{
		if (body.front() == n && i != 0) // �������� �������� ������� ��������
			snakeAlive = false;
		i++;
	}


	if (body.front() != FoodPozition ) // ���� �� ����� ��� ����� ������� ���� ������� � ������
		body.pop_back();
	cout << "Head: " << body.front().x << " X " << body.front().y << " Y\n";
}
void Snake::SnakeDraw()
{
	sf::CircleShape bodyPart(snakeThickness / 2);
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