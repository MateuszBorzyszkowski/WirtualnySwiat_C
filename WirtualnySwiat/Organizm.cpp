#pragma once
#include "Organizm.h"
#include "Swiat.h"

Organizm::Organizm(Swiat* swiat, int x, int y)
{
	pomocnicza = swiat;
	if (swiat->iloscOrganizmow() > N*N)	throw '!';
	sila = 0;
	inicjatywa = 0;
	wiek = 0;
	czy_przesunac = true;
	czy_zyje = true;
	this->x = x;
	this->y = y;
	if (pomocnicza->miejsceZajete(x, y))
	{
		bool dalej = true;
		for (int j = 0; j < N; j++)
		{
			for (int i = 0; i < N; i++)
			{
				dalej = pomocnicza->miejsceZajete(i, j);
				if (dalej == false)
				{
					this->x = i;
					this->y = j;
					break;
				}
			}
			if (dalej == false)	break;
		}
	}
	pomocnicza->dodajOrganizmNaMape(this, this->x, this->y);
	pomocnicza->dodajOrganizmDoKolejki(this);
	pomocnicza->dodajOrganizm();
}
Organizm::Organizm(Swiat * swiat) : Organizm(swiat, rand() % N, rand() % N)
{}

bool Organizm::czyUmarl()
{
	return !czy_zyje;
}
bool Organizm::czyPrzesunac()
{
	return czy_przesunac;
}
void Organizm::czyZyje(bool x)
{
	czy_zyje = x;
}

int Organizm::silaOrganizmu()
{
	return sila;
}
int Organizm::inicjatywaOrganizmu()
{
	return inicjatywa;
}
int Organizm::wiekOrganizmu()
{
	return wiek;
}
int Organizm::pozycjaX()
{
	return x;
}
int Organizm::pozycjaY()
{
	return y;
}

void Organizm::zwiekszWiek()
{
	wiek += 1;
}

void Organizm::ustawSile(int x)
{
	sila = x;
}
void Organizm::ustawInicjatywe(int x)
{
	inicjatywa = x;
}
void Organizm::ustawWiek(int x)
{
	wiek = x;
}
void Organizm::ustawPozycje(int x, int y)
{
	this->x = x;
	this->y = y;
}
void Organizm::ustawPrzesuwanie(bool x)
{
	czy_przesunac = x;
}


