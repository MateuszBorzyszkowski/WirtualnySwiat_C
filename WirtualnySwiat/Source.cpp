#pragma once
#include <iostream>
#include "Swiat.h"
#include <time.h> 
#include <conio.h>

int main()
{
	srand(time(NULL));

	char znak;
	int tura = 0;
	Swiat* swiat = new Swiat();

	std::cout << "WYKONAJ TURE: '1' \nZAPISZ DO PLIKU: '2' \nWCZYTAJ Z PLIKU: '3' \n";
	std::cout << "===============================================================\n\n";
	//std::cout << "PIERWOTNE ROZSTAWIENIE ORGANIZMOW NA MAPIE:" << "\n";

	//swiat->rysujSwiat();

	while (std::cin >> znak)
	{
		system("CLS");
		std::cout << "WYKONAJ TURE: '1' \nZAPISZ DO PLIKU: '2' \nWCZYTAJ Z PLIKU: '3' \n";
		std::cout << "===============================================================\n\n";


		if (znak == '1')
		{
			std::cout << "\n" << "Tura: " << tura;
			swiat->rysujSwiat();
			swiat->wykonajTure();
			tura++;
			std::cout << "\n" << "Tura: " << tura;
			swiat->rysujSwiat();			
		}
		else if (znak == '2')
		{
			std::cout << "Zapisana tura: " << tura << "\n";
			swiat->zapiszSwiat(tura);
			swiat->rysujSwiat();
		}
		else if (znak == '3')
		{
			tura = swiat->wczytajSwiat();
			std::cout << "Tura: " << tura << "\n";
			swiat->rysujSwiat();
		}
		
	}

	return 0;
}