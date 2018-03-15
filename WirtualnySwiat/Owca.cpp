#pragma once
#include "Owca.h"

Owca::Owca(Swiat* swiat) : Zwierze(swiat)
{
	sila = 4;
	inicjatywa = 4;
}
Owca::Owca(Swiat* swiat, int x, int y) : Zwierze(swiat, x, y)
{
	sila = 4;
	inicjatywa = 4;
}
void Owca::akcja()
{
	ruch(1);
}
void Owca::kolizja(Organizm* organizm, bool x)
{
	this->czyZyje(false);
	std::cout << "Organizm ("<< this->nazwa() << ") na polu (" << this->pozycjaX() << "," << this->pozycjaY() << ") zostal zjedzony przez organizm (" << organizm->nazwa() << ") na polu (" << organizm->pozycjaX() << "," << organizm->pozycjaY() << ").\n";
}
char Owca::rysowanie()
{
	return 'O';
}
void Owca::rozmnazanie(Swiat* swiat, int x, int y)
{
	Organizm* organizm = new Owca(swiat, x, y);
}
char* Owca::nazwa()
{
	return "OWCA";
}