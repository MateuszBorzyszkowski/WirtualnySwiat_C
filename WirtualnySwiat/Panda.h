#pragma once
#include "Zwierze.h"

class Panda : public Zwierze
{
public:
	Panda(Swiat* swiat);
	Panda(Swiat* swiat, int x, int y);
	void akcja();
	void kolizja(Organizm* organizm, bool x);
	char rysowanie();
	void rozmnazanie(Swiat* swiat, int x, int y);
	char* nazwa();
};

