#include<iostream>
#include"Graphics.h"
#include "NodeM.h"



int main()
{
	//////////////////////
	// ������ � ��������
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
		o.drawObj(); // ��������� �������
		window.display();
	}
	return 0;
}