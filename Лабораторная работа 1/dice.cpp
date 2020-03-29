#include "StdAfx.h"
#include "dice.h"


Dice::Dice(size_t faceCount)
{
	faces = new int[faceCount];
	faceProbabilities = new float[faceCount];
	for (int i = 0; i < faceCount; i++) {
		faces[i] = i + 1;
		faceProbabilities[i] = 1 / faceCount;
	}
}


Dice::~Dice(void)
{
}
