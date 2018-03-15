#pragma once
#include "Roslina.h"

class Guarana : public Roslina
{
public:
	Guarana(Swiat* swiat);
	Guarana(Swiat* swiat, int x, int y);
	void akcja();
	void kolizja(Organizm* organizm, bool x);
	char rysowanie();
	void rozmnazanie(Swiat* swiat, int x, int y);
	char* nazwa();
};