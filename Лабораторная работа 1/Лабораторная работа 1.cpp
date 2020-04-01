// Ћабораторна€ работа 1.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include "dice.h"
#include "DiceManager.h"
#include <iostream>
#include <iomanip>

using namespace std;

void display(int);

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");

	float* p = new float[4]; 
	p[0] = 0.2; p[1] = 0.0; p[2] = 0.3; p[3] = 0.4; //p[4] = 0.0; p[5] = 0.0;
	Dice* dice = new Dice(6);
	DiceManager* diceMgr = new DiceManager(dice, 5000);

	//diceMgr->setDisplayFunc(display);
	diceMgr->testDice();
	cout << setw(15) << "√рань " << setw(18) << "кол-во выпад." << setw(15) << "Ёмир. вер-сть" << endl;
	for (int i = 0; i < dice->getFaceCount(); i++){
		cout << setw(13) << i+1 << setw(15) << diceMgr->getDropped(i) << setw(17) << (float) diceMgr->getEProbability(i) << endl;
	}

	cout << endl;
	delete diceMgr;
	delete dice;

	system("pause");

	return 0;
}

void display(int face)
{
	cout << face << " ";
}