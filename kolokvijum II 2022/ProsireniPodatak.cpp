#include "ProsireniPodatak.h";

ProsireniPodatak::ProsireniPodatak() {
	T = 0;
	E = 0;
	N = 0;
}

ProsireniPodatak::ProsireniPodatak(float _T, float _E, float _N) {
	T = _T;
	E = _E;
	N = _N;
}

ProsireniPodatak::ProsireniPodatak(const ProsireniPodatak& drugi)
{
	T = drugi.T;
	E = drugi.E;
	N = drugi.N;
}

ProsireniPodatak::~ProsireniPodatak() {

}

ostream& operator << (ostream& izlaz, ProsireniPodatak& pp)
{
	izlaz << pp.T << " " << pp.E << " " << pp.N;
	return izlaz;
}

istream& operator >> (istream& ulaz, ProsireniPodatak& pp)
{
	ulaz >> pp.T >> pp.E >> pp.N;
	return ulaz;
}

ProsireniPodatak& ProsireniPodatak::operator=(const ProsireniPodatak& drugi)
{
	if (this != &drugi)
	{
		this->T = drugi.T;
		this->E = drugi.E;
		this->N = drugi.N;
	}
	return *this;
}

float ProsireniPodatak::getSubjektivniOsecaj(float T, float E, float N)
{
	float rezultat = T + (0.33 * E) - (0.7 * N) - 4.0;
	return rezultat;
}

float ProsireniPodatak::operator+(float drugi)
{
	float suma = 0;
	suma = drugi + getSubjektivniOsecaj(T, E, N);
	return suma;
}

bool ProsireniPodatak::operator>(ProsireniPodatak& drugi)
{
	if (this->getSubjektivniOsecaj(this->T, this->E, this->N) > drugi.getSubjektivniOsecaj(drugi.T, drugi.E, drugi.N))
	{
		return true;
	}
	else {
		return false;
	}
}