#pragma once
#include "Wilk.h"

Wilk::Wilk(Swiat* swiat) : Zwierze(swiat)
{
	sila = 9;
	inicjatywa = 5;

}
Wilk::Wilk(Swiat* swiat, int x, int y) : Zwierze(swiat, x, y)
{
	sila = 9;
	inicjatywa = 5;
}
void Wilk::akcja()
{
	ruch(1);
}
void Wilk::kolizja(Organizm* organizm, bool x)
{
	this->czyZyje(false);
	std::cout << "Organizm ("<< this->nazwa() << ") na polu (" << this->pozycjaX() << "," << this->pozycjaY() << ") zostal zjedzony przez organizm (" << organizm->nazwa() << ") na polu (" << organizm->pozycjaX() << "," << organizm->pozycjaY() << ").\n";
}
char Wilk::rysowanie()
{
	return 'W';
}
void Wilk::rozmnazanie(Swiat* swiat, int x, int y)
{
	Organizm* organizm = new Wilk(swiat, x, y);
}
char* Wilk::nazwa()
{
	return "WILK";
}