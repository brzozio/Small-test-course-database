// w pozniejszej wersji do wprowadzenia ze GunHandling wplywa na to czy przeciwnik trafi w nas oraz czy my trafimy w przeciwnika

#include<iostream>
#include<cstdlib>
#include<string>
#include <windows.h>
#include "Tank.h"
#include "Opponent.h"

float PUNKTY = 0; // punkty do awanowania tankietki
Opponent opponent[10];

void Tank::showStatistics() {
	std::cout << "Statystyki twojej tankietki to:  " << std::endl
		<< "Tier: " << tier << std::endl
		<< "HP: " << HP << std::endl
		<< "DPS: " << DPS << std::endl
		<< "Armor: " << Armor <<std::endl
		<< "Gun Handling: " << GunHandling << std::endl
		<< "Amunicja podstawowa: " << BasicAmmo.Penetration<< std::endl
		<< "Amunicja goldowa: " << GoldAmmo.Penetration<< std::endl;
		
}
void Tank::createTank() {
	int zmiennaWyborStatystyk;
	std::cout << "Witaj w kreatorze tankietki ... " << std::endl;
		Sleep(4000);
		system("cls");
		std::cout << "Przeciwnicy beda coraz silniejsi wraz z wzrostem twojego poziomu oraz bedzie ich coraz wiecej!" << std::endl;
		PUNKTY += 5; //punkty startowe

	for (int i = 0; i < PUNKTY; i++) {
		std::cout << "\nMasz " << PUNKTY - i << " punktow do zainwestowania w tankietke!" << std::endl;
		std::cout << "\n\nWybierz w co chcesz zainwestowac: " << std::endl
			<< "1 - HP - punkty wytrzymalosci + 20 HP" << std::endl
			<< "2 - DPS - damage per shot + 15 HP" << std::endl
			<< "3 - Armor + 10 mm" << std::endl
			<< "4 - Gun Handling - wplywa na RNG" << std::endl
			<< "5 - Amunicja - zwiekszenie penetracji pociskow" << std::endl;
		std::cin >> zmiennaWyborStatystyk;
		switch (zmiennaWyborStatystyk) {
		case 1:
			HP += 20;
			break;
		case 2:
			DPS += 15;
			break;
		case 3:
			Armor += 10;
			break;
		case 4:
			GunHandling -= 0.01; // wplywa na RNG oraz celnosc strzalu
			break;
		case 5:
			BasicAmmo.Penetration += 5;
			GoldAmmo.Penetration += 10;
			break;
		default:
			std::cout << "\nWybierz liczbe od 1 do 4!" << std::endl;
		}
		system("cls");
		showStatistics(); // wyswietlanie statystyk czolgu po kazdym rozwinieciu
	}
	
}
void Tank::battle() {
	int iloscRywali = tier*3 - 1; // ustalanie ilosci przeciwnikow na podstawie tieru tankietki
	int PIENIONZKI = 0;
	int HPTankietkiPrzedBitwa = HP;
	int HPtankietkiBitwa = HP;
	int HPOpponentPrzedBitwa = opponent[iloscRywali].HP; 

	std::cout << "Przygotuj sie do walki!\n" << std::endl;
			Sleep(1000);
	std::cout << "Pojawia sie przeciwnik! Musimy go pokonac!" << std::endl;
			Sleep(1000);
	std::cout << "Strzelaj!" << std::endl;

	int iloscPokonanychRywali = 0; // ilosc pokonanych rywali
	while (HPtankietkiBitwa > 0 && iloscPokonanychRywali <= iloscRywali) {

			std::cout << "\n\nPojawia sie " << iloscPokonanychRywali + 1 << " rywal!\nPrzygotuj sie do walki!" << std::endl;

			// --------------------------------------------------------------------------------------------------
			if (opponent[iloscRywali].BasicAmmo.Penetration > Armor) {
				HPtankietkiBitwa = HPtankietkiBitwa - opponent[iloscRywali].DPS; // do zmiany NA WIEKSZA ILOSC RYWALI w pozniejszej wersji
				opponent[iloscRywali].BasicAmmo.iloscPociskow = BasicAmmo.iloscPociskow - 1;
			}
			// ----------------------------------------------------------------------------------------------------

			int zmiennaSwitch;
			std::cout << "\n\nZ jakiej amunicji chcesz skorzystac?\nGoldowa posiada wiecej mm penetracji pancerza\n1 - BasicAmmo\n2 - GoldAmmo\n";
			std::cin >> zmiennaSwitch;
				system("cls");
			switch (zmiennaSwitch) {
			case 1: // BasicAmmo
				if (BasicAmmo.Penetration > opponent[iloscRywali].Armor) {
					opponent[iloscRywali].HP = opponent[iloscRywali].HP - DPS; // uszkadzamy przeciwnika
					BasicAmmo.iloscPociskow = BasicAmmo.iloscPociskow - 1;
					std::cout << "\n\nTrafilismy go! Zostalo nam " << BasicAmmo.iloscPociskow << " Basic pociskow!" << std::endl;
				}
				else std::cout << "\n\nNie przebilismy go!" << std::endl;
				break;

			case 2: // GoldAmmo
				if (GoldAmmo.Penetration > opponent[iloscRywali].Armor) {
					opponent[iloscRywali].HP = opponent[iloscRywali].HP - DPS; // uszkadzamy przeciwnika
					GoldAmmo.iloscPociskow = GoldAmmo.iloscPociskow - 1;
					std::cout << "\n\nTrafilismy go! Zostalo nam " << GoldAmmo.iloscPociskow << " Gold pociskow!" << std::endl;
				}
				else std::cout << "\n\nNie przebilismy go!" << std::endl;
				break;
			}

			// Sprawdzanie czy HP < 0 aby nie pokazywaly sie wartosci ujmene --------------------------------------------
				if (opponent[iloscRywali].HP < 0) {
					opponent[iloscRywali].HP = 0;
				}
				if (HPtankietkiBitwa < 0) {
					HPtankietkiBitwa = 0;
				}
			// ----------------------------------------------------------------------------------------------------------
			std::cout << "Po naszym trafieniu przeciwnik ma: " << opponent[iloscRywali].HP << " punktow HP!" << std::endl;
			std::cout << "Po trafieniu przeciwnika mamy: " << HPtankietkiBitwa << " punktow HP!" << std::endl;

			if (opponent[iloscRywali].HP <= 0) {
				std::cout << "\n\n\nBrawo! Pokonales przeciwnika! Jednakze uwazaj, nadciagaja kolejni, lepiej sie podlecz i przyszykuj do kolejnej walki!" << std::endl;
				opponent[iloscRywali].HP = HPOpponentPrzedBitwa;

				iloscPokonanychRywali++; // zwiekszanie ilosci pokonanych rywali w celu przywolania kolejnego przeciwnika
				PUNKTY += 1.5;
				PIENIONZKI += HPOpponentPrzedBitwa  + 0.2 * (HPTankietkiPrzedBitwa - HPtankietkiBitwa); // obliczanie pieniazkowm za pomoca ktrorych mozna potem zakupic apteczki albo pociskow
			
				std::cout << "\nZa te walke zdobyles " << PIENIONZKI << " pesos!" << std::endl;
				std::cout << "\n\nZa te walke zdobyles " << PUNKTY << " punktow do awansowania!" << std::endl
						  << "Mozesz ulepszyc swoj pojazd, podleczyc sie albo zakupic amunicje juz teraz!\nCzy chcesz to zrobic ? \n1 - tak\n2 - nie" << std::endl;
				std::cin >> zmiennaSwitch;
					system("cls");

				switch (zmiennaSwitch) {
				case 1:
					std::cout << "\nAktualnie posiadasz " << PIENIONZKI << " pesos." << std::endl;
					std::cout << "Czy chcesz zregenerowac swoje HP? Bedzie to kosztowac 80 pesos\n1 - TAK, 2 - NIE" << std::endl;
					std::cin >> zmiennaSwitch;
					switch (zmiennaSwitch) {
						case 1:
							if (80 > PIENIONZKI) {
								std::cout << "\nNie stac cie na podleczenie sie! Musisz sobie jakos poradzic!" << std::endl;
							}
							else {
								HP = HPTankietkiPrzedBitwa;
								PIENIONZKI -= 80;
							}
							break;
					}
					std::cout << "Czy chcesz zakupic wiecej amunicji? Jedna amunicja Basic to 2 pesos, jeden pocisk Gold to 10 pesos" << std::endl
							  << "Aktualnie posiadasz " << PIENIONZKI << " pesos." << std::endl
						      << "Aktualnie posiadasz " << BasicAmmo.iloscPociskow << " Basic Ammo oraz " << GoldAmmo.iloscPociskow << " GoldAmmo" << std::endl
							  << "\n1 - TAK, 2 - NIE" << std::endl;
					std::cin >> zmiennaSwitch;
						system("cls");
					switch (zmiennaSwitch) {
					case 1:
						int wyborZakupuAmunicji = 0;;
						int temporary = 0;
						std::cout << "\nJaka amunicje chcesz zakupic? 1 - Basic, 2 - Gold" << std::endl
							<< "Jedna amunicja Basic to 2 pesos, jeden pocisk Gold to 10 pesos" << std::endl;
						std::cin >> wyborZakupuAmunicji;
							system("cls");
							int ilosc;
						if (wyborZakupuAmunicji == 1) {
							std::cout << "\nIle amunicji chcesz zakupic?" << std::endl;
							std::cin >> ilosc;
								system("cls");
						}
						switch (wyborZakupuAmunicji) {
						case 1:
							if (ilosc * 2 > PIENIONZKI) {
								std::cout << "Nie mozesz zakupic tyle amunicji!\nMax to:" << PIENIONZKI / 2 << std::endl;
								ilosc = PIENIONZKI / 2;
								std::cout << "\nCzy chcesz zakupic max?\n1 - TAK, 2 - NIE" << std::endl;
								std::cin >> temporary;
								if (temporary == 1) {
									PIENIONZKI -= ilosc * 2;
									BasicAmmo.iloscPociskow += ilosc;
									std::cout << "\n\nZakupiles " << ilosc << " amunicji Basic!" << std::endl;
								}
							}
							else {
								PIENIONZKI -= ilosc * 2;
								BasicAmmo.iloscPociskow += ilosc;
								std::cout << "\n\nZakupiles " << ilosc << " amunicji Basic!" << std::endl;
							}
							break;
						case 2:
							if (ilosc * 10 > PIENIONZKI) {
								std::cout << "Nie mozesz zakupic tyle amunicji!\nMax to:" << PIENIONZKI / 10 << std::endl;
								ilosc = PIENIONZKI / 10;
								std::cout << "\nCzy chcesz zakupic max?\n1 - TAK, 2 - NIE" << std::endl;
								std::cin >> temporary;
								if (temporary == 1) {
									PIENIONZKI -= ilosc * 10;
									GoldAmmo.iloscPociskow += ilosc;
									std::cout << "\n\nZakupiles " << ilosc << " amunicji Basic!" << std::endl;
								}
							}
							else {
								PIENIONZKI -= ilosc * 10;
								GoldAmmo.iloscPociskow += ilosc;
								std::cout << "\n\nZakupiles " << ilosc << " amunicji Basic!" << std::endl;
							}
							break;
						}
						break;
					}
					upgrading();
					break;
				case 2:
					std::cout << "\n\nDobrze, zatem przygotuj  sie do nastepnej walki kolego!" << std::endl;
					break;
				}
			}
		}
	std::cout << "\n\nNo niestety, nie uda³o nam siê go pokonaæ!" << std::endl
			  << "Wracaj do garazu i sprobuj ponownie!" << std::endl;
				HP = HPTankietkiPrzedBitwa; // prawie darmowa regeneracja HP w garazu
				PIENIONZKI -= 20; // 20 pesos to oplata za regeneracje HP w garazu
	battle();
}
void Tank::upgrading() {
	std::cout << "\n\nTwoj aktualny TIER tankietki to: " << tier << std::endl;
	int zmiennaUpgradeSwitchCase;
	float TrudnoscLevelowania = 50;
	
	for (int i = 0; i < (int)PUNKTY; i++) {
		std::cout << "\n\nMasz " << (int)PUNKTY - i << " punktow do awansowania!" << std::endl;
		std::cout << "\n\nWybierz w co chcesz zainwestowac: " << std::endl
			<< "1 - HP - punkty wytrzymalosci + 20 HP" << std::endl
			<< "2 - DPS - damage per shot + 15 HP" << std::endl
			<< "3 - Armor + 10 mm" << std::endl
			<< "4 - Gun Handling - wplywa na RNG" << std::endl
			<< "5 - Amunicja - zwiekszenie penetracji pociskow" << std::endl;
		std::cin >> zmiennaUpgradeSwitchCase;
			system("cls");
		switch (zmiennaUpgradeSwitchCase) {
		case 1:
			HP += 20;
			break;
		case 2:
			DPS += 15;
			break;
		case 3:
			Armor += 10;
			break;
		case 4:
			GunHandling -= 0.01; // celnosc strzalu
			break;
		case 5:
			BasicAmmo.Penetration += 5;
			GoldAmmo.Penetration += 10;
			break;
		default:
			std::cout << "Wybierz liczbe od 1 do 4!" << std::endl;
		}
		showStatistics(); // wyswietlanie statystyk czolgu po kazdym rozwinieciu
		if (((DPS + HP + Armor + BasicAmmo.Penetration + GoldAmmo.Penetration) / 5) >= TrudnoscLevelowania) {
			tier++;
			std::cout << "\n\nAwansowales na wyzszy tier! Teraz twoja tankietka jest silniejsza!\nKazda statystyka jest zwiekszana o 2!" << std::endl;
				HP += 15;
				DPS += 5;
				Armor += 10;
				GunHandling -= 0.005;
				BasicAmmo.Penetration += 10;
				GoldAmmo.Penetration += 10;
			TrudnoscLevelowania += 10*(float)tier + TrudnoscLevelowania*1.2;
			for (int i = 0; i < 10; i++) {
				opponent[i].upgrading(); // ulepszanie sie przeciwnikow po awansowaniu na wyzszy tier
			}
			
		}
	}
}
