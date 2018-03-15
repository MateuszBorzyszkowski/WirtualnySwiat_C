#pragma once
#include "Panda.h"



Panda::Panda(Swiat* swiat) : Zwierze(swiat)
{
	sila = 7;
	inicjatywa = 3;
}
Panda::Panda(Swiat* swiat, int x, int y) : Zwierze(swiat, x, y)
{
	sila = 7;
	inicjatywa = 3;
}
void Panda::akcja()
{

	int lenistwo = rand() % 4;
	if (lenistwo == 0)
	{
		ruch(1);
	}

}
void Panda::kolizja(Organizm* organizm, bool x)
{
	this->czyZyje(false);
	std::cout << "Organizm ("<< this->nazwa() << ") na polu (" << this->pozycjaX() << "," << this->pozycjaY() << ") zostal zjedzony przez organizm (" << organizm->nazwa() << ") na polu (" << organizm->pozycjaX() << "," << organizm->pozycjaY() << ").\n";
}
char Panda::rysowanie()
{
	return 'P';
}
void Panda::rozmnazanie(Swiat* swiat, int x, int y)
{
	Organizm* organizm = new Panda(swiat, x, y);
}
char* Panda::nazwa()
{
	return "PANDA";
}