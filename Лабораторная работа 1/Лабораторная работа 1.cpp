// Лабораторная работа 1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "dice.h"
#include "DiceManager.h"
#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

void display(int);

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");

	cout << "Лабораторная работа №1. Выполнил Сабитов К.А. ИСзск-19 ИИТЗО" << endl;
	cout << "Программа имитирует бросание игральной кости с учетом различных форм и несимметричных граней. Работает в двух режимах - ручном и автоматическом." << endl << endl;
	cout << "Выберите режим бросков (1 - автоматический / 2 - ручной) [1]: ";
	int mode;
	cin >> mode;
	cout << "Введите количество граней кости (2-20) [6]: ";
	size_t faces;
	cin >> faces;
	if (faces < 2 || faces > 20) faces = 6;
	cout << "Ввести вероятности граней кости? (1 - да / 2 - нет) [2]: ";
	int inputProb;
	cin >> inputProb;
	Dice* dice;
	if (inputProb == 1) {
		cout << "Введите вероятности выпадения каждой грани" << endl;
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
				cout << "Вероятности введены ошибочно. Повторите попытку" << endl;
			}
			cout << endl;
		} while (!ok);
		dice = new Dice(faces, probs);
	} else {
		cout << endl;
		cout << "Кость сформирована с симетричными гранями" << endl;
		dice = new Dice(faces);
		cout << "Теоретические вероятности выпадения каждой грани " << (float) 1 / faces << endl;
	}

	DiceManager* diceMgr;
	unsigned int k = 100;
	if (mode == 2) {
		cout << "Введите количество бросков: ";
		cin >> k;
	} else {
		// автоматом
		srand(time(0));
		k = 1000 + rand() % (50000-1000);
		cout << "Количество бросков " << k << endl;
	}

	diceMgr = new DiceManager(dice, k);
	cout << "Результат работы программы представлен в таблице ниже" << endl << endl;

	//diceMgr->setDisplayFunc(display);
	diceMgr->testDice();
	cout << setw(10) << "Грань " << setw(15) << "Кол-во выпад." << setw(15) << "Ожид.кол-во" << setw(15) << "Эмир. вер-сть" << setw(15) <<  "Теор. вер." << endl;
	for (int i = 0; i < dice->getFaceCount(); i++){
		cout << setw(7) << i+1 << setw(12) << diceMgr->getDropped(i) << setw(17) << diceMgr->getExpectedDrop(i) << setw(17) << (float) diceMgr->getEProbability(i) << setw(17) << dice->getProbability(i) << endl;
	}

	cout << endl;
	cout << "Критерий Пирсона (хи-квадрат): " << diceMgr->pearson() << endl;
	delete diceMgr;
	delete dice;

	system("pause");

	return 0;
}

void display(int face)
{
	cout << face << " ";
}