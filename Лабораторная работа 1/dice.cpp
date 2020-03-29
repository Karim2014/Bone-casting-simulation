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
		std::cout << faceProbabilitiesVector[i] << std::endl;
	}
}

Dice::Dice(size_t faceCount, float* faceProbabilities) {

}

int Dice::throwDice() 
{

	float k = ((float) rand() / RAND_MAX);
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

Dice::~Dice(void)
{
	delete[] faces;
	delete[] faceProbabilities;
	delete[] faceProbabilitiesVector;
}