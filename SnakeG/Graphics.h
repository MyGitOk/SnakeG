#pragma once
#include <SFML/Graphics.hpp>
#include"NodeM.h"
#include<deque>
#include<list>

int windowWidth = 200;
int windowHight = 200;
sf::RenderWindow window(sf::VideoMode(windowWidth, windowHight), "SFMLworks");
sf::Event event;
sf::CircleShape shape(3.f);
sf::Vector2f ShapePozition;

float step = 6; // шаг движения
float checkStep = 0; // для проверки шага
float speed = 0.03; // скорость движения

class Obj
{
public:
	Obj();
	void drawObj();
	void moveObj();
	void pushToHead();
	void popFromTail();
	void getIvent(sf::Event _event);
	//~Obj();

private:
	
	int size;
	Node* pHead;
	Node* pTail;
};

Obj::Obj()
{
	size = 1;
	pHead = new Node;
	pTail = pHead;
}
void Obj::drawObj()
{
	Node * pTmp = pHead;
	while (pTmp->getPnext() != nullptr)
	{
		pTmp->setNodePosition();
		window.draw(pTmp->getShape());
		pTmp = pTmp->getPnext();
	}
}
void Obj::pushToHead()
{
	Node * newPHead = new Node;
	newPHead->ChangeDir(pHead->getDirection());
	if (newPHead->getDirection() == RIGHT)
	{
		if (pHead->getX() >= windowWidth)
			newPHead->setX(0);
		else
			newPHead->setX(pHead->getX() + step);
		newPHead->setY(pHead->getY());
	}
	else if (newPHead->getDirection() == LEFT)
	{
		if (pHead->getX() <= 0)
			newPHead->setX(float(windowWidth));
		else
			newPHead->setX(pHead->getX() - step);
		newPHead->setY(pHead->getY());
	}
	else if (newPHead->getDirection() == UP)
	{
		if (pHead->getY() <= 0)
			newPHead->setY(float(windowHight));
		else
			newPHead->setY(pHead->getY() - step);
		newPHead->setX(pHead->getX());
	}
	else if (newPHead->getDirection() == DOWN)
	{
		if (pHead->getY() >= windowHight)
			newPHead->setY(0);
		else
			newPHead->setY(pHead->getY() + step);
		newPHead->setX(pHead->getX());
	}
	newPHead->setPNext(pHead); // у головы следующий узел тот который раньше был головой
	newPHead->setPPrev(nullptr); // у головы предыдущий узел == нул

	pHead->setPPrev(newPHead); // у предыдущей головы предыдущий узел - новая голова
	pHead = newPHead; // перестановка указателя на новую голову
}
void Obj::popFromTail()
{
	Node * pTmp;
	pTmp = pTail->getPprev();
	pTmp->setPNext(nullptr);
	delete pTail;
	pTail = pTmp;
}
void Obj::moveObj()
{
	if (int(step) == int(checkStep))
	{
		checkStep = 0; // обнуляем проверку шага

		pushToHead();
		popFromTail();
	}
	else
	{
		checkStep += speed;
	}
}
void Obj::getIvent(sf::Event _event)
{
	while (window.pollEvent(_event))
	{
		if (_event.type == sf::Event::Closed)
			window.close();
		else if (_event.type == sf::Event::KeyPressed)
		{
			if (_event.key.code == sf::Keyboard::Up)
			{
				pHead->ChangeDir(UP);
			}
			else if (_event.key.code == sf::Keyboard::Down)
			{
				pHead->ChangeDir(DOWN);
			}
			else if (_event.key.code == sf::Keyboard::Right)
			{
				pHead->ChangeDir(RIGHT);
			}
			else if (_event.key.code == sf::Keyboard::Left)
			{
				pHead->ChangeDir(LEFT);
			}
		}
	}

}