#include "StdAfx.h"
#include "dice.h"

Dice::Dice(size_t faceCount)
{
	this->faceCount = faceCount;
	srand(time(0));
	faces = new int[faceCount];
	faceProbabilities = new float[faceCount];
	faceProbabilitiesVector = new float[faceCount];
	for (int i = 0; i < faceCount; i++) {
		faces[i] = i + 1;
		faceProbabilities[i] = (float) 1 / faceCount;
		faceProbabilitiesVector[i] = i == 0 ? 0 + faceProbabilities[i] : faceProbabilitiesVector[i-1] + faceProbabilities[i];
	}
}

Dice::Dice(size_t faceCount, float* faceProbabilities) {
	this->faceCount = faceCount;
	srand(time(0));
	faces = new int[faceCount];
	this->faceProbabilities = faceProbabilities;
	checkDice();
	faceProbabilitiesVector = new float[faceCount];
	for (int i = 0; i < faceCount; i++) {
		faces[i] = i + 1;
		faceProbabilitiesVector[i] = i == 0 ? 0 + faceProbabilities[i] : faceProbabilitiesVector[i-1] + faceProbabilities[i];
	}
}

int Dice::throwDice() 
{

	float k = ((float) (rand()+1) / RAND_MAX);
	if (k > 0 && k <= faceProbabilitiesVector[0]) return 1;
	for (int i = 0; i < faceCount-1; i++) 
	{
		if (k > faceProbabilitiesVector[i] && k <= faceProbabilitiesVector[i+1])
		{
			return i+2;
		}
	}
	return 1;
}

size_t Dice::getFaceCount() 
{
	return faceCount;
}

void Dice::checkDice() 
{
	float sum = 0;
	for (int i = 0; i < faceCount-1; i++) {
		sum+= faceProbabilities[i];
	}
	faceProbabilities[faceCount-1] = 1 - sum;
}

Dice::~Dice(void)
{
	delete[] faces;
	delete[] faceProbabilities;
	delete[] faceProbabilitiesVector;
}