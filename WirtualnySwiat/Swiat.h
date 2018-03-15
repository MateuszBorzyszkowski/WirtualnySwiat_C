#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

#define N 20
class Organizm;

class Swiat
{
public:
	Swiat();
	void rysujSwiat();
	void wykonajTure();
	void zapiszSwiat(int tura);
	int wczytajSwiat();

	Organizm * organizmNaPolu(int x, int y);
	bool miejsceZajete(int x, int y);
	void dodajOrganizmNaMape(Organizm *, int x, int y);
	void dodajOrganizmDoKolejki(Organizm *);
	void przesunOrganizm(Organizm *, int nowy_x, int nowy_y, int x, int y);
		
	void dodajOrganizm();
	void usunOrganizm();
	int iloscOrganizmow();

	
protected:
	Organizm* mapa[N][N];
	std::vector<Organizm *> kolejka;
	int liczba_organizmow;
};
