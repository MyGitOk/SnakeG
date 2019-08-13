#pragma once
#include<conio.h>
#include"Graphics.h"
using namespace std;
enum Direction
{
	STOP,
	LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80, TWO = 50, FOUR = 52, SIX = 54, EIGHT = 56
};
//Direction dir;

//class Input
//{
//public:
//	Input()
//	{
//		key;
//	}
//	//~Input();
//	void readKey()
//	{
//		if (sf::Keyboard::Key /*_kbhit()*/)
//		{
//			cout << key;
//			
//			if (key = 224)
//			{
//				key = _getch();
//			}
//
//			if (/*key == LEFT || FOUR*/ key == RIGHT || SIX)
//			{
//				/*ShapePozition.x -= 1;*/
//				ShapePozition.x += 1;
//				cout << ShapePozition.x;
//			}
//			else if (key == RIGHT || SIX)
//			{
//				ShapePozition.x += 1;
//			}
//			else if (key == UP || EIGHT)
//			{
//				ShapePozition.y -= 1;
//			}
//			else if (key == DOWN || TWO)
//			{
//				ShapePozition.y += 1;
//			}
//			//switch (_getch())
//			//{
//			//case 'a':
//			//{
//			//	dir = LEFT;
//			//	ShapePozition.x--;
//			//	break;
//			//}
//			//case'd':
//			//	dir = RIGHT;
//			//	ShapePozition.x++;
//			//	break;
//			//case'w':
//			//	dir = UP;
//			//	break;
//			//case's':
//			//	dir = DOWN;
//			//	break;
//			//}
//		}
//	}
//private:
//	sf::Keyboard::Key key;
//};