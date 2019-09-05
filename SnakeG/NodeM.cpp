#include"NodeM.h"

double speed = 0.05;

Node::Node()
{
	x = 18;
	y = 18;
	pNext = nullptr;
	pPrev = this;
	direct = LEFT;
	sh.setRadius(3.f);
};
Node::Node(const float & _x, const float & _y, Node * _pNext)
{
	x = _x;
	y = _y;
	pNext = _pNext;
	sh.setRadius(3.f);
}
void Node::setToTail(Node * _pTail)
{
	if (_pTail->direct == RIGHT)
	{
		x = _pTail->x - 6;
		y = _pTail->y;
	}
	else if (_pTail->direct == LEFT)
	{
		x = _pTail->x + 6;
		y = _pTail->y;
	}
	else if (_pTail->direct == UP)
	{
		x = _pTail->x;
		y = _pTail->y - 6;
	}
	else if (_pTail->direct == DOWN)
	{
		x = _pTail->x;
		y = _pTail->y + 6;
	}
	_pTail->pNext = this;
	this->pPrev = _pTail;
}
sf::CircleShape Node::getShape()
{
	return sh;
}
void Node::setNodePosition()
{
	sh.setPosition(x, y);
}
Node* Node::getPnext()
{
	return pNext;
}
Node* Node::getPprev()
{
	return pPrev;
}
float Node::getX()
{
	return x;
}
float Node::getY()
{
	return y;
}
DirectNode Node::getDirection()
{
	return direct;
}
void Node::setNextPozition(Node * _pPrev)
{
	if (direct == RIGHT)
		x += 0.05;
	else if (direct == LEFT)
		x -= 0.05;
	else if (direct == UP)
		y -= 0.05;
	else if (direct == DOWN)
		y += 0.05;
	direct = _pPrev->direct;
}
void Node::setX(float _x)
{
	x = _x;
}
void Node::setY(float _y)
{
	y = _y;
}
void Node::setPNext(Node * _pCur)
{
	pNext = _pCur;
}
void Node::setPPrev(Node * _pCur)
{
	pPrev = _pCur;
}
void Node::ChangeDir(DirectNode _dir)
{
	direct = _dir;
}