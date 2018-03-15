#pragma once
#include "Zwierze.h"

class Owca : public Zwierze
{
public:
	Owca(Swiat* swiat);
	Owca(Swiat* swiat, int x, int y);
	void akcja();
	void kolizja(Organizm* organizm, bool x);
	char rysowanie();
	void rozmnazanie(Swiat* swiat, int x, int y);
	char* nazwa();
};