#pragma once
#include "Mlecz.h"

Mlecz::Mlecz(Swiat* swiat) : Roslina(swiat)
{
	sila = 0;
	inicjatywa = 0;
}
Mlecz::Mlecz(Swiat* swiat, int x, int y) : Roslina(swiat, x, y)
{
	sila = 0;
	inicjatywa = 0;
}
void Mlecz::akcja()
{
	for (int i = 0; i < 3; i++)
	{
		ruch(rand() % 20);
	}
}
void Mlecz::kolizja(Organizm* organizm, bool x)
{
	this->czyZyje(false);
	std::cout << "Organizm ("<< this->nazwa() << ")  zostal zjedzony przez organizm (" << organizm->nazwa() << ") na polu (" << this->pozycjaX() << "," << this->pozycjaY() << ").\n";
}
char Mlecz::rysowanie()
{
	return 'M';
}
void Mlecz::rozmnazanie(Swiat* swiat, int x, int y)
{
	Organizm* organizm = new Mlecz(swiat, x, y);
}
char* Mlecz::nazwa()
{
	return "MELCZ";
}