#pragma once
#include "Roslina.h"

class Trawa	: public Roslina
{
public:
	Trawa(Swiat* swiat);
	Trawa(Swiat* swiat, int x, int y);
	void akcja();
	void kolizja(Organizm* organizm, bool x);
	char rysowanie();
	void rozmnazanie(Swiat* swiat, int x, int y);
	char* nazwa();
};