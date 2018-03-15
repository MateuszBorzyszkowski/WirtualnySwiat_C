#pragma once
#include "Antylopa.h"

Antylopa::Antylopa(Swiat* swiat) : Zwierze(swiat)
{
	sila = 4;
	inicjatywa = 4;
}
Antylopa::Antylopa(Swiat* swiat, int x, int y) : Zwierze(swiat, x, y)
{
	sila = 4;
	inicjatywa = 4;
}

void Antylopa::akcja()
{
	ruch(2);
}
void Antylopa::kolizja(Organizm* organizm, bool x)
{
	int ruszyc = rand() % 2;
	if (ruszyc == 1)
	{
		this->czyZyje(false);
		std::cout << "Organizm (" << this->nazwa() << ") na polu (" << this->pozycjaX() << "," << this->pozycjaY() << ") zostal zjedzony przez organizm (" << organizm->nazwa() << ") na polu (" << organizm->pozycjaX() << "," << organizm->pozycjaY() << ").\n";
	}
	else
	{
		int nowy_x, nowy_y;
		int x = this->x;
		int y = this->y;
		bool dalej = true;
		this->ustawPrzesuwanie(false);
		for (int j = y - 1; j < y + 2; j++)
		{
			for (int i = x - 1; i < x + 2; i++)
			{

				nowy_x = i;
				nowy_y = j;
				if (nowy_x < 0)	nowy_x += N;
				if (nowy_y < 0)	nowy_y += N;
				if (nowy_x > N - 1)	nowy_x -= N;
				if (nowy_y > N - 1)	nowy_y -= N;

				dalej = pomocnicza->miejsceZajete(nowy_x, nowy_y);

				if (dalej)
				{
					Organizm* nowy = pomocnicza->organizmNaPolu(x, y);
					if (rysowanie() != nowy->rysowanie() && nowy->silaOrganizmu() < this->silaOrganizmu())
					{
						nowy->kolizja(this, false);
						pomocnicza->przesunOrganizm(this, nowy_x, nowy_y, this->x, this->y);
						this->x = nowy_x;
						this->y = nowy_y;
						dalej = false;
					}
				}
				else
				{
					pomocnicza->przesunOrganizm(this, nowy_x, nowy_y, this->x, this->y);
					this->x = nowy_x;
					this->y = nowy_y;
				}
				if (dalej == false)	break;
			}
			if (dalej == false)	break;
		}
		std::cout << "Organizm ("<< this->nazwa() << ") na polu (" << this->pozycjaX() << "," << this->pozycjaY() << ") zmienil trase aby uciec przed organizmem (" << organizm->nazwa() << ") na polu (" << organizm->pozycjaX() << "," << organizm->pozycjaY() << ").\n";

	}
}
char Antylopa::rysowanie()
{
	return 'A';
}
void Antylopa::rozmnazanie(Swiat* swiat, int x, int y)
{
	Organizm* organizm = new Antylopa(swiat, x, y);
}
char* Antylopa::nazwa()
{
	return "ANTYLOPA";
}