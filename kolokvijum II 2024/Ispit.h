#pragma once
#include <iostream>
using namespace std;

class Ispit
{
private:
	char* nazivIspita;
	int ocena;
	int espb;
public:
	Ispit();
	~Ispit();
	Ispit(const char* _nazivIspita, int _ocena, int _espb);
	Ispit(const Ispit& drugi);

	friend ostream& operator << (ostream& izlaz, Ispit& ispit);
	friend istream& operator >> (istream& ulaz, Ispit& ispit);

	float operator+ (float levi);
	bool operator > (Ispit& drugi);

	Ispit& operator = (const Ispit& drugi);
};