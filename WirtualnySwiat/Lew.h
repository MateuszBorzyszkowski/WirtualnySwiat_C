#pragma once
#include "Zwierze.h"

class Lew : public Zwierze
{
public:
	Lew(Swiat* swiat);
	Lew(Swiat* swiat, int x, int y);
	void akcja();
	void kolizja(Organizm* organizm, bool x);
	char rysowanie();
	void rozmnazanie(Swiat* swiat, int x, int y);
	char* nazwa();
};