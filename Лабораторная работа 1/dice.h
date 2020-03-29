#pragma once
class Dice {
private:
	int* faces;
	float* faceProbabilities;
public:
	Dice(void);
	Dice(double*);
	void setProbability(size_t, double);
	~Dice(void);
};

