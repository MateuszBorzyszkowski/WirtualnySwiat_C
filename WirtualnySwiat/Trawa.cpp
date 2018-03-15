#pragma once
#include "Trawa.h"

Trawa::Trawa(Swiat* swiat) : Roslina(swiat)
{
	sila = 0;
	inicjatywa = 0;
}
Trawa::Trawa(Swiat* swiat, int x, int y) : Roslina(swiat, x, y)
{
	sila = 0;
	inicjatywa = 0;
}
void Trawa::akcja()
{
	ruch(rand() % 10);
}
void Trawa::kolizja(Organizm* organizm, bool x)
{
	this->czyZyje(false);
	std::cout << "Organizm ("<< this->nazwa() << ") zostal zjedzony przez organizm (" << organizm->nazwa() << ") na polu (" << this->pozycjaX() << "," << this->pozycjaY() << ").\n";
}
char Trawa::rysowanie()
{
	return 'T';
}
void Trawa::rozmnazanie(Swiat* swiat, int x, int y)
{
	Organizm* organizm = new Trawa(swiat, x, y);
}
char* Trawa::nazwa()
{
	return "TRAWA";
}