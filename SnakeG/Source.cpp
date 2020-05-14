#include<iostream>
#include"Graphics.h"
#include"Input.h"
#include"GameLogic.h"
#include<Windows.h>


int main()
{
	Snake Sn;
	speed = 200; // game refresh rate in milliseconds

	food.setFillColor(sf::Color::Yellow);
	FoodPozition.x = cell * 8;
	FoodPozition.y = cell * 2;
	food.setPosition(FoodPozition);

	int counterSteps = 0;

	while (window.isOpen())
	{
		//считывание с клавиатуры
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed)
				Sn.SnakeUpdate(event.key.code);
		}

		Sn.SnakeMove();
		counterSteps++;

		// отрисовка
		window.clear();
		Sn.SnakeDraw();
		window.draw(food);
		window.display();

		if (!snakeAlive)
		{
			MessageBoxA(0, "Game Over", "Snake_Game", MB_OK);
			sf::sleep(sf::seconds(3));
			window.close();
		}


		cout << "Food: " << FoodPozition.x << " X " << FoodPozition.y << " Y\n";
		cout << counterSteps << " - steps from start game\n";


		sf::sleep(sf::milliseconds(speed));
	}
	return 0;
}