#pragma once
#include"SFML/Graphics.hpp"

enum DirectNode
{
	UP, DOWN, LEFT, RIGHT
};

class Node
{
public:
	Node();
	Node(const float & _x,const float & _y, Node * _pNext);
	void setToTail(Node * _pTail);
	sf::CircleShape getShape();
	void setNodePosition();
	Node* getPnext();
	Node* getPprev();
	float getX();
	float getY();
	DirectNode getDirection();
	void setNextPozition(Node *_pPrev);
	void setX(float _x);
	void setY(float _y);
	void setPNext(Node * _pCur);
	void setPPrev(Node * _pCur);
	void ChangeDir(DirectNode _dir);
	//~Node();

private:
	float x;
	float y;
	Node* pNext;
	Node* pPrev;
	DirectNode direct;
	sf::CircleShape sh;
};