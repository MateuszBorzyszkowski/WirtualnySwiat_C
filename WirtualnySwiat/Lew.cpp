#pragma once
#include "Lew.h"

Lew::Lew(Swiat* swiat) : Zwierze(swiat)
{
	sila = 11;
	inicjatywa = 7;
}
Lew::Lew(Swiat* swiat, int x, int y) : Zwierze(swiat, x, y)
{
	sila = 11;
	inicjatywa = 7;
}
void Lew::akcja()
{
	ruch(1);
}
void Lew::kolizja(Organizm* organizm, bool x)
{
	this->czyZyje(false);
	std::cout << "Organizm ("<< this->nazwa() << ") na polu (" << this->pozycjaX() << "," << this->pozycjaY() << ") zostal zjedzony przez organizm (" << organizm->nazwa() << ") na polu (" << organizm->pozycjaX() << "," << organizm->pozycjaY() << ").\n";
}
char Lew::rysowanie()
{
	return 'L';
}
void Lew::rozmnazanie(Swiat* swiat, int x, int y)
{
	Organizm* organizm = new Lew(swiat, x, y);
}
char* Lew::nazwa()
{
	return "LEW";
}