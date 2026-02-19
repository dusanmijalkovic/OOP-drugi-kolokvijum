#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template <class t>
class Kolekcija
{
private:
	t* niz;
	int maxElemenata;
	int trElemenata;

public:
	Kolekcija();
	Kolekcija(int _maxElemenata);
	~Kolekcija();

	void DodajPodatak(t& podatak);
	void Obrisi(int redniBroj);
	float OdrediProsek();
	t NajveciPodatak();
	void Sacuvaj(const char* imeFajla);
	void Ucitaj(const char* imeFajla);


	friend ostream& operator << (ostream& izlaz, Kolekcija<t>& kolekcija) {
		izlaz << kolekcija.maxElemenata << " " << kolekcija.trElemenata << endl;
		for (int i = 0; i < kolekcija.trElemenata; i++) {
			izlaz << kolekcija.niz[i] << endl;
		}
		return izlaz;
	}
	
	friend istream& operator >> (istream& ulaz, Kolekcija<t>& kolekcija)
	{
		if (kolekcija.niz != nullptr) {
			delete[] kolekcija.niz;
		}

		ulaz >> kolekcija.maxElemenata >> kolekcija.trElemenata;

		kolekcija.niz = new t[kolekcija.maxElemenata];

		for (int i = 0; i < kolekcija.trElemenata; i++)
		{
			ulaz >> kolekcija.niz[i];
		}

		return ulaz;
	}
};

template <class t>
Kolekcija <t>::Kolekcija()
{
	maxElemenata = 0;
	trElemenata = 0;
	niz = nullptr;
}

template <class t>
Kolekcija <t>::Kolekcija(int _maxElemenata)
{
	maxElemenata = _maxElemenata;
	trElemenata = 0;
	niz = new t[maxElemenata];
}

template <class t>
Kolekcija<t>::~Kolekcija() {
	if (niz != nullptr) {
		delete[] niz;
		niz = nullptr;
	}
}

template <class t>
void Kolekcija <t>::DodajPodatak(t& podatak)
{
	if (trElemenata == maxElemenata) {
		throw "Greska pri dodavanju podataka!";
	}
	niz[trElemenata] = podatak;
	trElemenata += 1;
}

template <class t>
void Kolekcija <t>::Obrisi(int redniBroj){
	int index = redniBroj - 1;
	if (index < 0 || index > trElemenata - 1) {
		throw "Doslo je do greske prilikom brisanja.";
	}
	for (int i = index; i < trElemenata - 1; i++) {
		niz[i] = niz[i + 1];
	}
	trElemenata = trElemenata - 1;
}

template <class t>
float Kolekcija<t>::OdrediProsek()
{
	float suma = 0;
	float prosek = 0;
	for (int i = 0; i < trElemenata; i++) {
		suma = niz[i] + suma;
	}
	prosek = suma / trElemenata;
	return prosek;
}

template <class t>
t Kolekcija<t>::NajveciPodatak() {
	int indexMax = 0;
	for (int i = 0; i < trElemenata; i++) {
		if (niz[i] > niz[indexMax]) {
			indexMax = i;
		}
	}
	return niz[indexMax];
}


template <class t>
void Kolekcija<t>::Sacuvaj(const char* imeFajla)
{
	ofstream izlaz(imeFajla);
	if (!izlaz.is_open()) {
		throw "Doslo je do greske priliko cuvanja u fajl!";
	}
	else {
		izlaz << *this;
		izlaz.close();
	}
}

template <class t>
void Kolekcija<t>::Ucitaj(const char* imeFajla) {
	ifstream ulaz(imeFajla);
	if (!ulaz.is_open()) {
		throw "Doslo je do greske prilik citanja iz fajla!";
	}
	else {
		ulaz >> *this;
		ulaz.close();
	}
}