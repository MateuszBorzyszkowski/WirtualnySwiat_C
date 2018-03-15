#pragma once
#include <iostream>
#include "Swiat.h"

#define N 20

class Organizm
{
public:
	Organizm(Swiat* swiat, int x, int y);
	Organizm(Swiat* swiat);
	virtual void akcja() = 0;
	virtual void kolizja(Organizm * organizm, bool x) = 0;
	virtual char rysowanie() = 0;
	virtual char * nazwa() = 0;

	bool czyUmarl();
	bool czyPrzesunac();
	void czyZyje(bool x);

	
	int silaOrganizmu();
	int wiekOrganizmu();
	int inicjatywaOrganizmu();
	int pozycjaX();
	int pozycjaY();

	void zwiekszWiek();

	void ustawSile(int x);
	void ustawInicjatywe(int x);
	void ustawWiek(int x);
	void ustawPozycje(int x, int y);
	void ustawPrzesuwanie(bool x);

protected:
	Swiat * pomocnicza;
	int sila;
	int inicjatywa;
	int wiek;
	int x;
	int y;
	bool czy_zyje;
	bool czy_przesunac;
};