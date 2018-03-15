#pragma once
#include "Swiat.h"
#include "Wilk.h"
#include "Owca.h"
#include "Antylopa.h"
#include "Panda.h"
#include "Lew.h"
#include "Trawa.h"
#include "Guarana.h"
#include "Mlecz.h"

Swiat::Swiat()
{
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			mapa[i][j] = nullptr;
		}
	}

	for (int i = 0; i < 5; i++)	{Organizm* organizm = new Wilk(this);}
	for (int i = 0; i < 5; i++)	{Organizm* organizm = new Owca(this);}
	for (int i = 0; i < 3; i++)	{Organizm* organizm = new Antylopa(this);}
	for (int i = 0; i < 3; i++)	{Organizm* organizm = new Panda(this);}
	for (int i = 0; i < 2; i++)	{Organizm* organizm = new Lew(this);}
	for (int i = 0; i < 4; i++)	{Organizm* organizm = new Trawa(this);}
	for (int i = 0; i < 2; i++)	{Organizm* organizm = new Guarana(this);}
	for (int i = 0; i < 2; i++)	{Organizm* organizm = new Mlecz(this);}
}
void Swiat::rysujSwiat()
{
	std::cout << "\n";
	std::cout << "===============================================================\n";
	std::cout << "   ";

	for (int j = 0; j < N; j++)
	{
		if (j < 10)
		{
			std::cout << j << "  ";
		}
		else
		{
			std::cout << j << " ";
		}
	}
	std::cout << "\n";
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if (i == 0 && j < 10)
			{
				std::cout << j << "   ";
			}
			if (i == 0 && j > 9)
			{
				std::cout << j << "  ";
			}

			if (mapa[i][j] != nullptr)
				std::cout << mapa[i][j]->rysowanie() << "  ";
			else
				std::cout << ".  ";
		}
		std::cout << "\n";
	}
	std::cout << "===============================================================\n";
}
void Swiat::wykonajTure()
{
	std::sort(kolejka.begin(), kolejka.end(), [](Organizm* organizm_1, Organizm* organizm_2) -> bool 
	{
		if (organizm_1->inicjatywaOrganizmu() == organizm_2->inicjatywaOrganizmu())	return organizm_1->wiekOrganizmu() > organizm_2->wiekOrganizmu();
		else return organizm_1->inicjatywaOrganizmu() > organizm_2->inicjatywaOrganizmu();
	});

	for (unsigned int i = 0; i < kolejka.size(); ++i)
	{
		Organizm* organizm = kolejka[i];
		if (organizm != nullptr)
		{
			if (organizm->czyUmarl())
			{
				int x = organizm->pozycjaX();
				int y = organizm->pozycjaY();
				organizm = nullptr;
				delete organizm;
				kolejka[i] = nullptr;
				dodajOrganizmNaMape(nullptr, x, y);
				this->usunOrganizm();
			}

			if (organizm == nullptr) continue;
			if (organizm->wiekOrganizmu() > 0)	organizm->akcja();
			organizm->zwiekszWiek();

			if (organizm->czyUmarl())
			{
				int x = organizm->pozycjaX();
				int y = organizm->pozycjaY();
				organizm = nullptr;
				delete organizm;
				kolejka[i] = nullptr;
				dodajOrganizmNaMape(nullptr, x, y);
				this->usunOrganizm();
			}
		}
	}

	auto itr = std::find(kolejka.begin(), kolejka.end(), nullptr);
	while (itr != kolejka.end())
	{
		itr = kolejka.erase(itr);
		itr = std::find(itr, kolejka.end(), nullptr);
	}

}
void Swiat::zapiszSwiat(int tura)
{
	std::fstream plik;
	plik.open("plikSwiata.txt", std::ios::out);
	plik << tura << "\n";

	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if (mapa[i][j] != nullptr) {
				plik << mapa[i][j]->rysowanie() << " " << i << " " << j << " " << mapa[i][j]->silaOrganizmu() << " " << mapa[i][j]->inicjatywaOrganizmu() << " " << mapa[i][j]->wiekOrganizmu();
			}
		}
	}
}
int Swiat::wczytajSwiat()
{
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			mapa[i][j] = nullptr;
		}
	}
	kolejka.clear();
	std::fstream plik;
	plik.open("plikSwiata.txt", std::ios::in);
	char nazwa;
	int tura;
	int x, y, sila, inicjatywa, wiek;
	plik >> tura;


	while (!plik.eof() )
	{
		plik >> nazwa;
		plik >> x;
		plik >> y;
		plik >> sila;
		plik >> inicjatywa;
		plik >> wiek;

		Organizm* organizm = nullptr;

		switch (nazwa)
		{
		case 'W':
			organizm = new Wilk(this, x, y);
			break;
		case 'O':
			organizm = new Owca(this, x, y);
			break;
		case 'A':
			organizm = new Antylopa(this, x, y);
			break;
		case 'P':
			organizm = new Panda(this, x, y);
			break;
		case 'L':
			organizm = new Lew(this, x, y);
			break;
		case 'T':
			organizm = new Trawa(this, x, y);
			break;
		case 'G':
			organizm = new Guarana(this, x, y);
			break;
		case 'M':
			organizm = new Mlecz(this, x, y);
			break;
		}

		organizm->ustawPozycje(x, y);
		organizm->ustawSile(sila);
		organizm->ustawInicjatywe(inicjatywa);
		organizm->ustawWiek(wiek);
		this->dodajOrganizmNaMape(organizm, x, y);
	}
	return tura;
}

Organizm * Swiat::organizmNaPolu(int x, int y)
{
	return mapa[x][y];
}
bool Swiat::miejsceZajete(int x, int y)
{
	return mapa[x][y] != nullptr;
}
void Swiat::dodajOrganizmNaMape(Organizm * organizm, int x, int y)
{
	mapa[x][y] = organizm;
}
void Swiat::dodajOrganizmDoKolejki(Organizm * organizm)
{
	if (std::find(kolejka.begin(), kolejka.end(), organizm) != kolejka.end()) return;
	kolejka.push_back(organizm);
}
void Swiat::przesunOrganizm(Organizm * organizm, int nowy_x, int nowy_y, int x, int y)
{
	if (this->miejsceZajete(nowy_x, nowy_y))
	{
		Organizm * a = mapa[nowy_x][nowy_y];
		a->ustawPozycje(x, y);
		mapa[x][y] = a;
		mapa[nowy_x][nowy_y] = organizm;
	}
	else
	{
		mapa[x][y] = nullptr;
		mapa[nowy_x][nowy_y] = organizm;
	}
}

void Swiat::dodajOrganizm()
{
	liczba_organizmow += 1;
}
void Swiat::usunOrganizm()
{
	liczba_organizmow -= 1;
}
int Swiat::iloscOrganizmow()
{
	return liczba_organizmow;
}



