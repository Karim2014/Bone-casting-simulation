// Лабораторная работа 1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "dice.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Dice* dice = new Dice(6);
	for (int i = 0; i < 20; i++) 
		cout << dice->throwDice() << ", ";

	delete dice;

	system("pause");

	return 0;
}

