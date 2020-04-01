#include "StdAfx.h"
#include "DiceManager.h"

DiceManager::DiceManager(Dice* dice, unsigned int testCount)
{
	this->dice = dice;
	this->testCount = testCount;
	this->callback = nullptr;
	this->dropped = new unsigned int[dice->getFaceCount()];
	for (int i = 0; i < dice->getFaceCount(); i++)
		dropped[i] = 0;
}

void DiceManager::setDisplayFunc(void (*callback)(int))
{
	this->callback = callback;
}

void DiceManager::testDice() 
{
	int face; // выпавшая грань
	for (int i = 0; i < this->testCount; i++) 
	{
		face = this->dice->throwDice();
		if (callback != nullptr)
			callback(face);
		dropped[face-1]++;
	}
}

float DiceManager::getEProbability(size_t face)
{
	if (face >= dice->getFaceCount())
		throw "Невозможно расчитать теоретическую вероятность: выход за границы массива";
	return (float) dropped[face] / testCount;
}

float DiceManager::getDropped(size_t face) 
{
	if (face >= dice->getFaceCount())
		throw "Невозможно отобразить количество выпавших граней: выход за границы массива";
	return dropped[face];
}

double DiceManager::pearson() 
{
	double sum = 0.0;
	for (int i = 0; i < dice->getFaceCount(); i++) {
		sum += pow((double) dropped[i] - getExpectedDrop(i), 2) / getExpectedDrop(i);
	}
	return sum;
}

DiceManager::~DiceManager(void)
{
	delete[] dropped;
}
