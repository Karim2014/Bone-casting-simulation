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
	unsigned int getDropped(size_t face);
	unsigned int getExpectedDrop(size_t face) {return dice->getProbability(face) * testCount;} 
	float getEProbability(size_t); // ������������ �����������
	double pearson();
	~DiceManager(void);
};

