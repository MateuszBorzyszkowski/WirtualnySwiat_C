#pragma once
#include "Organizm.h"

class Zwierze
	:public Organizm
{
public:
	Zwierze(Swiat* swiat);
	Zwierze(Swiat* swiat, int x, int y);
	virtual void rozmnazanie(Swiat* swiat, int x, int y) = 0;
	void ruch(int o_ile);

};