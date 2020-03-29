#pragma once
class Dice {
private:
	size_t faceCount;
	int* faces;
	float* faceProbabilities;
	float* faceProbabilitiesVector;
public:
	Dice(size_t);
	Dice(size_t, float*);
	int throwDice();
	void setProbability(size_t, double);
	size_t getFaceCount();
	~Dice(void);
	//
};

