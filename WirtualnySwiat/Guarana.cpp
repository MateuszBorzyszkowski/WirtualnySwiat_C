#pragma once
#include "Guarana.h"

Guarana::Guarana(Swiat* swiat) : Roslina(swiat)
{
	sila = 0;
	inicjatywa = 0;
}
Guarana::Guarana(Swiat* swiat, int x, int y) : Roslina(swiat, x, y)
{
	sila = 0;
	inicjatywa = 0;
}
void Guarana::akcja()
{
	for (int i = 0; i < 3; i++)
	{
		ruch(rand() % 30);
	}
}
void Guarana::kolizja(Organizm* organizm, bool x)
{
	this->czyZyje(false);
	std::cout << "Organizm ("<< this->nazwa() << ") zostal zjedzony przez organizm (" << organizm->nazwa() << ") na polu (" << this->pozycjaX() << "," << this->pozycjaY() << ").\n";
	std::cout << "Organizm ("<< organizm->nazwa() << ") znajdujacy sie na polu (" << organizm->pozycjaX() << "," << organizm->pozycjaY() << ") z pododu zjedzenia GURANY otrzymuje +3 do swojej sily. Jego aktualna sila: " << organizm->silaOrganizmu()+3 << ".\n";
	organizm->ustawSile((organizm->silaOrganizmu()) + 3);
}
char Guarana::rysowanie()
{
	return 'G';
}
void Guarana::rozmnazanie(Swiat* swiat, int x, int y)
{
	Organizm* organizm = new Guarana(swiat, x, y);
}
char* Guarana::nazwa()
{
	return "GUARANA";
}