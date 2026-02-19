#define _CRT_SECURE_NO_WARNINGS
#include "Ispit.h"
#include <iostream>
#include <string.h>

Ispit::Ispit() {
	nazivIspita = nullptr;
	ocena = 0;
	espb = 0;
}

Ispit::~Ispit() {
	if (nazivIspita != nullptr) {
		delete[] nazivIspita;
		nazivIspita = nullptr;
	}
}

Ispit::Ispit(const char* _nazivIspita, int _ocena, int _espb) {
	ocena = _ocena;
	espb = _espb;
	nazivIspita = new char[strlen(_nazivIspita) + 1];
	strcpy(nazivIspita, _nazivIspita);
}

Ispit::Ispit(const Ispit& drugi)
{
	ocena = drugi.ocena;
	espb = drugi.espb;
	nazivIspita = new char[strlen(drugi.nazivIspita) + 1];
	strcpy(nazivIspita, drugi.nazivIspita);
}

Ispit& Ispit::operator=(const Ispit& drugi)
{
	if (this != &drugi) {
		if (nazivIspita != nullptr) {
			delete[] nazivIspita;
		}
		ocena = drugi.ocena;
		espb = drugi.espb;
		nazivIspita = new char[strlen(drugi.nazivIspita) + 1];
		strcpy(nazivIspita, drugi.nazivIspita);
	}
	return *this;
}

ostream& operator << (ostream& izlaz, Ispit& ispit) {
	izlaz << ispit.nazivIspita << " " << ispit.ocena << " " << ispit.espb;
	return izlaz;
}

istream& operator >> (istream& ulaz, Ispit& ispit) {
	char privremeno[100];
	delete[] ispit.nazivIspita;
	ulaz >> privremeno >> ispit.ocena >> ispit.espb;
	ispit.nazivIspita = new char[strlen(privremeno) + 1];
	strcpy(ispit.nazivIspita, privremeno);
	return ulaz;
}

float Ispit::operator+(float drugi)
{
	float rezultat = 0;
	rezultat = drugi + ocena;
	return rezultat;
}

bool Ispit::operator>(Ispit& drugi) {
	if (this->espb > drugi.espb) {
		return true;
	}
	else {
		return false;
	}
}