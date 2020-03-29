#pragma once
#include "dice.h"

class DiceManager
{
private:
	unsigned int testCount; // ���������� ���������
	Dice* dice; // ������ �� �����
	unsigned int* dropped;
	void (*callback)(int);
public:
	DiceManager(Dice*, unsigned int);
	void setDisplayFunc(void (*callback)(int)); //  ������� ��������� ������
	void testDice();
	float getEProbability(size_t); // ������������ �����������
	~DiceManager(void);
};

