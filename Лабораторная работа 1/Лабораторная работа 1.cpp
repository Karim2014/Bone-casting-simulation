// ������������ ������ 1.cpp: ���������� ����� ����� ��� ����������� ����������.
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

	float* p = new float[6]; 
	p[0] = 0.0; p[1] = 0.0; p[2] = 0.5; p[3] = 0.5; p[4] = 0.0; p[5] = 0.0;
	Dice* dice = new Dice(6, p);
	DiceManager* diceMgr = new DiceManager(dice, 5000);

	//diceMgr->setDisplayFunc(display);
	diceMgr->testDice();

	for (int i = 0; i < dice->getFaceCount(); i++){
		cout << "����� " << i+1 << ":" << endl << " ���������� ���������: " << diceMgr->getDropped(i)
			<< endl << " ������������ �����������: " << (float) diceMgr->getEProbability(i) << endl << endl;
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