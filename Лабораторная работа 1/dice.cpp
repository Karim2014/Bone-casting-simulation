#include "StdAfx.h"
#include "dice.h"


Dice::Dice(size_t faceCount)
{
	this->faceCount = faceCount;
	srand(time(0));
	faces = new int[faceCount];
	faceProbabilities = new float[faceCount];
	for (int i = 0; i < faceCount; i++) {
		faces[i] = i + 1;
		faceProbabilities[i] = 1 / faceCount;
	}
}


Dice::~Dice(void)
{
	delete[] faces;
	delete[] faceProbabilities;
}

int Dice::throwDice() {
	return floor(((double) rand()/RAND_MAX) * faceCount) + 1;
}