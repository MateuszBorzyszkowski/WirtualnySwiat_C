#pragma once
#include "Roslina.h"
#include "Swiat.h"

Roslina::Roslina(Swiat* swiat) : Organizm(swiat)
{}
Roslina::Roslina(Swiat* swiat, int x, int y) : Organizm(swiat, x, y)
{}
void Roslina::ruch(int prawdopodobienstwo)
{
	if (prawdopodobienstwo == 0)
	{
		int x = this->x;
		int y = this->y;

		bool dalej = true;
		for (int j = y - 1; j < y + 2; j++)
		{
			for (int i = x - 1; i < x + 2; i++)
			{
				int nowy_x, nowy_y;
				nowy_x = i;
				nowy_y = j;
				if (nowy_x < 0)	nowy_x += N;
				if (nowy_y < 0)	nowy_y += N;
				if (nowy_x > N - 1)	nowy_x -= N;
				if (nowy_y > N - 1) nowy_y -= N;
				dalej = pomocnicza->miejsceZajete(nowy_x, nowy_y);
				if (dalej == false)
				{
					this->rozmnazanie(pomocnicza, nowy_x, nowy_y);
					std::cout << "Na polu (" << nowy_x << "," << nowy_y << ") powstal nowy organizm (" << this->nazwa() << ") w wyniku rozmnozenia organizmu (" << this->nazwa() << ") na polu (" << x << "," << y << ").\n";
					break;
				}
			}
			if (dalej == false)	break;
		}
	}
}