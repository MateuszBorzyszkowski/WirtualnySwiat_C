#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze
{
public:
	Wilk(Swiat* swiat);
	Wilk(Swiat* swiat, int x, int y);
	void akcja();
	void kolizja(Organizm* organizm, bool x);
	char rysowanie();
	void rozmnazanie(Swiat* swiat, int x, int y);
	char* nazwa();
};