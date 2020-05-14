#include<iostream>
#include"Graphics.h"
#include"Input.h"
#include"GameLogic.h"


int main()
{
	Snake Sn;
	speed = 200; // game refresh rate in milliseconds

	food.setFillColor(sf::Color::Yellow);
	FoodPozition.x = 99.f;
	FoodPozition.y = 21.f;
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
		

		// отрисовка
		window.clear();
		Sn.SnakeDraw();
		window.draw(food);
		window.display();

		counterSteps++;
		cout << counterSteps << " - steps from start game\n";


		sf::sleep(sf::milliseconds(speed));
	}
	return 0;
}