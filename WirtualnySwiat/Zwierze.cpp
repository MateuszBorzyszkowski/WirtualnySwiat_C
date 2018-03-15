#pragma once
#include "Zwierze.h"
#include "Swiat.h"

Zwierze::Zwierze(Swiat* swiat) : Organizm(swiat)
{}
Zwierze::Zwierze(Swiat* swiat, int x, int y) : Organizm(swiat, x, y)
{}
void Zwierze::ruch(int o_ile)
{
	int x = this->x;
	int y = this->y;
	switch (rand() % 4)
	{
	case 0: x = x - o_ile; break;
	case 1: y = y + o_ile; break;
	case 2: x = x + o_ile; break;
	case 3: y = y - o_ile; break;
	}

	if (x < 0) x += N;
	if (y < 0) y += N;
	if (x > N - 1) x -= N;
	if (y > N - 1) y -= N;
	if (pomocnicza->miejsceZajete(x, y))
	{
		Organizm* organizm = pomocnicza->organizmNaPolu(x, y);
		if (rysowanie() == organizm->rysowanie())
		{
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
					if (nowy_y > N - 1)	nowy_y -= N;
					dalej = pomocnicza->miejsceZajete(nowy_x, nowy_y);
					if (dalej == false)
					{
						this->rozmnazanie(pomocnicza, nowy_x, nowy_y);
						std::cout << "Na polu (" << nowy_x << "," << nowy_y << ") powstal nowy organizm (" << organizm->nazwa() << ")  w wyniku rozmnozenia organizmu (" << organizm->nazwa() << ") na polu (" << x << "," << y << ").\n";
						break;
					}
				}
				if (dalej == false)	break;
			}
		}
		else
		{
					int sila_atakujacego = this->silaOrganizmu();
					int sila_broniacego = organizm->silaOrganizmu();
					if (sila_atakujacego >= sila_broniacego)
					{
						organizm->kolizja(this, false);
					}
					else
					{
						if (organizm->nazwa() == "LEW")
						{
							if (sila_atakujacego > 4)
							{
								std::cout << "Jestem " << this->nazwa() << " (" << this->pozycjaX() << "," << this->pozycjaY() << ") i mam duzo sily i czuje sie silny! LEW mi nie straszny dlatego bede sie bic!\n";
								this->kolizja(organizm, false);
							}
							else
							{
								std::cout << "Jestem " << this->nazwa() << " (" << this->pozycjaX() << "," << this->pozycjaY() << ") i mam mniej sily niz LEW, dlatego nie podejmuje walki. I wcale nie tchorze!\n";
								
									pomocnicza->przesunOrganizm(this, x, y, this->x, this->y);
									this->x = x;
									this->y = y;
								
							}
						}
						else
						{
							this->kolizja(organizm, false);
						}
					}
			
		}
	}
	else
	{
		pomocnicza->przesunOrganizm(this, x, y, this->x, this->y);
		this->x = x;
		this->y = y;
	}
}