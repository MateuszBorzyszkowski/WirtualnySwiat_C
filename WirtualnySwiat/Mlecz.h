#pragma once
#include "Roslina.h"

class Mlecz : public Roslina
{
public:
	Mlecz(Swiat* swiat);
	Mlecz(Swiat* swiat, int x, int y);
	void akcja();
	void kolizja(Organizm* organizm, bool x);
	char rysowanie();
	void rozmnazanie(Swiat* swiat, int x, int y);
	char* nazwa();
};