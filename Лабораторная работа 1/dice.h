#pragma once
class Dice {
private:
	size_t faceCount;
	int* faces;
	float* faceProbabilities;
public:
	Dice(size_t);
	Dice(size_t, double*);
	int throwDice();
	void setProbability(size_t, double);
	~Dice(void);
};

