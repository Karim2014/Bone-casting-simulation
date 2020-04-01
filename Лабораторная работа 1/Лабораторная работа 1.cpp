// ������������ ������ 1.cpp: ���������� ����� ����� ��� ����������� ����������.
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

	cout << "������������ ������ �1. �������� ������� �.�. �����-19 �����" << endl;
	cout << "��������� ��������� �������� ��������� ����� � ������ ��������� ���� � �������������� ������. �������� � ���� ������� - ������ � ��������������." << endl << endl;
	cout << "�������� ����� ������� (1 - �������������� / 2 - ������) [1]: ";
	int mode;
	cin >> mode;
	cout << "������� ���������� ������ ����� (2-20) [6]: ";
	size_t faces;
	cin >> faces;
	if (faces < 2 && faces > 20) faces = 6;
	cout << "������ ����������� ������ �����? (1 - �� / 2 - ���) [2]: ";
	int inputProb;
	cin >> inputProb;
	Dice* dice;
	if (inputProb == 1) {
		cout << "������� ����������� ��������� ������ �����" << endl;
		float* probs = new float[faces];
		bool ok;
		do {
			ok = true;
			for (int i = 0; i < faces; i++) {
				cin >> probs[i];
			}
			float sum = 0;
			for (int i = 0; i < faces-1; i++) {
				sum += probs[i];
			}
			if (sum >= 1) {
				ok = false;
				cout << "����������� ������� ��������. ��������� �������" << endl;
			}
		} while (!ok);
		dice = new Dice(faces, probs);
	} else {
		cout << endl;
		cout << "����� ������������ � ������������ �������" << endl;
		dice = new Dice(faces);
		cout << "������������� ����������� ��������� ������ ����� " << (float) 1 / faces << endl;
	}

	DiceManager* diceMgr;
	if (mode == 2) {
		// ������ �����
	} else {
		// ���������
		srand(time(0));
		int k = 1000 + rand() % (50000-1000);
		cout << "���������� ������� " << k << endl;
		diceMgr = new DiceManager(dice, k);
	}

	cout << "��������� ������ ��������� ����������� � ������� ����" << endl << endl;

	//diceMgr->setDisplayFunc(display);
	diceMgr->testDice();
	cout << setw(15) << "����� " << setw(18) << "���-�� �����." << setw(15) << "����. ���-���" << setw(15) <<  "����. ���." << endl;
	for (int i = 0; i < dice->getFaceCount(); i++){
		cout << setw(13) << i+1 << setw(15) << diceMgr->getDropped(i) << setw(17) << (float) diceMgr->getEProbability(i) << setw(17) << dice->getProbability(i) << endl;
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