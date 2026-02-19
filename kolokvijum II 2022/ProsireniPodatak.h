#pragma once
#include <iostream>
using namespace std;

class ProsireniPodatak {
private:
	float T;
	float E;
	float N;
public:
	ProsireniPodatak();
	ProsireniPodatak(float _T, float _E, float _N);
	ProsireniPodatak(const ProsireniPodatak& drugi);
	~ProsireniPodatak();

	ProsireniPodatak& operator=(const ProsireniPodatak& drugi);

	friend ostream& operator << (ostream& izlaz, ProsireniPodatak& pp);
	friend istream& operator >> (istream& ulaz, ProsireniPodatak& pp);

	float operator +(float operand);
	bool operator >(ProsireniPodatak& drugi);

	float getSubjektivniOsecaj(float T, float E, float N);
};