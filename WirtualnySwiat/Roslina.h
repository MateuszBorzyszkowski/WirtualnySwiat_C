#pragma once
#include "Organizm.h"

class Roslina
	:public Organizm
{
public:
	Roslina(Swiat* swiat);
	Roslina(Swiat* swiat, int x, int y);
	virtual void rozmnazanie(Swiat* swiat, int x, int y) = 0;
	void ruch(int prawdopodobienstwo);
};