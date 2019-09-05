#include<iostream>
#include"Graphics.h"
#include "NodeM.h"



int main()
{
	//////////////////////
	// лабуда с объектом
	Obj o;
	o.pushToHead();
	o.pushToHead();
	o.pushToHead();
	o.pushToHead();
	o.pushToHead();
	o.pushToHead();
	o.pushToHead();

	while (window.isOpen())
	{
		window.clear();
		o.getIvent(event);
		o.moveObj();
		o.drawObj(); // отрисовка объекта
		window.display();
	}
	return 0;
}