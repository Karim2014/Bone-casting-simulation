#pragma once
class Dice {
private:
	int* faces;
	float* faceProbabilities;
public:
	Dice(size_t);
	Dice(size_t, double*);
	void setProbability(size_t, double);
	~Dice(void);
};

