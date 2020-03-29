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
		faceProbabilities[i] = 1 / faceCount;
		faceProbabilitiesVector[i] = i == 0 ? 0 + faceProbabilities[i] : faceProbabilities[i-1] + faceProbabilities[i];
	}
}

int Dice::throwDice() 
{

	float k = rand() / RAND_MAX;
	for (int i = faceCount-1; i < 0; i--) 
	{
		if (k < faceProbabilitiesVector[i] && k >= faceProbabilitiesVector[i-1])
		{
			return i;
		}
	}
}

size_t Dice::getFaceCount() 
{
	return faceCount;
}

Dice::~Dice(void)
{
	delete[] faces;
	delete[] faceProbabilities;
	delete[] faceProbabilitiesVector;
}