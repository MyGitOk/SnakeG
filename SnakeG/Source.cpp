#include<iostream>
#include"Graphics.h"
#include"Input.h"
#include"GameLogic.h"


int main()
{
	Snake Sn;
	
	shape.setFillColor(sf::Color::Green);
	ShapePozition.x = 20.f;
	ShapePozition.y = 20.f;
	float step = 0.05;

	/////////
	food.setFillColor(sf::Color::Yellow);
	FoodPozition.x = 100.f;
	FoodPozition.y = 20.f;

	enum Direction
	{
		dUP, dDOWN, dRIGHT, dLEFT
	};
	Direction dir = dRIGHT;

	while (window.isOpen())
	{
		//считывание с клавиатуры
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed)
			{
				Sn.SnakeUpdate(event.key.code);
				if (event.key.code == sf::Keyboard::Up)
				{
					ShapePozition.y -= step * 30; // надо что бы здесь менялось направление
					dir = dUP;
				}
				else if (event.key.code == sf::Keyboard::Down)
				{
					ShapePozition.y += step * 30;
					dir = dDOWN;
				}
				else if (event.key.code == sf::Keyboard::Right)
				{
					ShapePozition.x += step * 30;
					dir = dRIGHT;
				}
				else if (event.key.code == sf::Keyboard::Left)
				{
					ShapePozition.x -= step * 30;
					dir = dLEFT;
				}
			}

		}

		// направление + проход через края поля
		if (dir == dUP)
		{
			if (ShapePozition.y <= 0)
			{
				ShapePozition.y = wHight;
			}
			ShapePozition.y -= step;
		}
		else if (dir == dDOWN)
		{
			if (ShapePozition.y >= wHight)
			{
				ShapePozition.y = 0;
			}
			ShapePozition.y += step;
		}
		else if (dir == dLEFT)
		{
			if (ShapePozition.x <= 0)
			{
				ShapePozition.x = wWidth;
			}
			ShapePozition.x -= step;
		}
		else if (dir == dRIGHT)
		{
			if (ShapePozition.x >= wWidth)
			{
				ShapePozition.x = 0;
			}
			ShapePozition.x += step;
		}


		//shape.move(ShapePozition);
		shape.setPosition(ShapePozition);
		food.setPosition(FoodPozition);


		// отрисовка
		window.clear();
		Sn.SnakeDraw();
		window.draw(shape);
		window.draw(food);
		window.display();
		

	}
	return 0;
}