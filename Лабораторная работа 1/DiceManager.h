#pragma once
#include "dice.h"

class DiceManager
{
private:
	unsigned int testCount; // количество испытаний
	Dice* dice; // сслыка на кость
	unsigned int* dropped;
	void (*callback)(int);
public:
	DiceManager(Dice*, unsigned int);
	void setDisplayFunc(void (*callback)(int)); //  функция обратного вызова
	void testDice();
	unsigned int getDropped(size_t face);
	float getEProbability(size_t); // эмпирическая вероятность
	~DiceManager(void);
};

