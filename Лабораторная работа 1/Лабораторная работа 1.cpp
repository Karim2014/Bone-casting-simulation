// Лабораторная работа 1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "dice.h"
#include "DiceManager.h"
#include <iostream>

using namespace std;

void display(int);

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");

	Dice* dice = new Dice(6);
	DiceManager* diceMgr = new DiceManager(dice, 10000);

	//diceMgr->setDisplayFunc(display);
	diceMgr->testDice();

	for (int i = 0; i < dice->getFaceCount(); i++){
		cout << "Грань " << i+1 << ":" << endl << " Количество выпадений: " << diceMgr->getDropped(i)
			<< endl << " Эмпирическая вероятность: " << (float) diceMgr->getEProbability(i) << endl << endl;
	}


	delete diceMgr;
	delete dice;

	system("pause");

	return 0;
}

void display(int face)
{
	cout << face << " ";
}