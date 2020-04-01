#pragma once
class Dice {
private:
	size_t faceCount;
	int* faces;
	float* faceProbabilities;
	float* faceProbabilitiesVector;
	void checkDice();
public:
	Dice(size_t);
	Dice(size_t, float*);
	int throwDice();
	void setProbability(size_t, double);
	float getProbability(size_t i) { return faceProbabilities[i]; }
	size_t getFaceCount();
	~Dice(void);
	//
};

