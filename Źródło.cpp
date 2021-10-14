#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
#include <stdbool.h>
#define TRUE 1
#define FALSE 0

struct studenci {
	std::string imie;
	std::string nazwisko;
	int numerAlbumu;
};
//strcmp(string1, string2) - zwroci 0 jesli sa identyczne
struct studenci Studenci[20];
int iloscStudentow, studenciDodawani;
int zmiennaSwitchCase;

void wyszukajStudenta(int iloscPracownikow, studenci Studenc[]);
void wypiszStudentow(int iloscPracownikow, studenci Studenc[]);
void dodajStudenta(int iloscPracownikow, studenci Studenc[]);


int main() {
	bool outCheck = FALSE;
	iloscStudentow = 0;
	while (outCheck == FALSE) {
		std::cout<<"Podaj co chcesz zrobic:\n 1 - Dodac studenta\n 2 - Wyszukac studenta\n 3 - Wypisac studentow\n 4 - Zakonczyc program\n";
		std::cin >> zmiennaSwitchCase;
		iloscStudentow = iloscStudentow + studenciDodawani;
		switch (zmiennaSwitchCase) {
		case 1: dodajStudenta(iloscStudentow, Studenci); break;
		case 2: wyszukajStudenta(iloscStudentow, Studenci); break;
		case 3: wypiszStudentow(iloscStudentow, Studenci); break;
		case 4: outCheck = TRUE;
		}
	}
}
void dodajStudenta(int iloscStudentow, studenci Studenci[]) {
	std::cout<<"Podaj ilosc pracownikow do dodania\n";
	std::cin>>studenciDodawani;
	for (int i = iloscStudentow; i < iloscStudentow + studenciDodawani; i++) {
		std::cout<<"Podaj imie, nazwisko oraz numer identyfikacyjny " << i << " pracownika \n";
		std::cin>>Studenci[i].imie;
		std::cin>>Studenci[i].nazwisko;
		std::cin>>Studenci[i].numerAlbumu;
	}
}
void wyszukajStudenta(int iloscStudentow, studenci Studenci[]) {
	std::string imieTemporary;
	std::string nazwiskoTemporary;
	int numerTemporary;
	int zmienna_switch;
	for (TRUE) {
		std::cout<<"Podaj co chcesz zrobic:\n1 - Wyszukaj pracownika po imieniu\n2 - Wyszukaj pracownika po nazwisku\n3 - Wyszukaj pracownika po numerze identyfikacyjnym\n4 - Zakoncz program\n";
		std::cin>>zmienna_switch;

		switch (zmienna_switch){
		case 1:
			std:: cout << "Podaj imie pracownika, ktore chcesz wyszukac: ";
			std::cin>>imieTemporary;
			std:: cout << std::endl;

			for (int i = 0; i < iloscStudentow; i++) {
				if (imieTemporary == Studenci[i].imie) {
					std::cout << "Imie wyszukanego pracownika: " << Studenci[i].imie <<"\nNazwisko wyszukanego pracownika: " << Studenci[i].nazwisko << "\nNumer identyfikacyjny pracownika: " << Studenci[i].numerAlbumu << "\n\n";
				}
			}
			break;

		case 2:
			std::cout<<"Podaj nazwisko pracownika, ktore chcesz wyszukac: ";
			std::cin>>nazwiskoTemporary;
			std::cout<<std::endl; std::cout<<std::endl;
			
			for (int i = 0; i < iloscStudentow; i++) {
				if (nazwiskoTemporary == Studenci[i].nazwisko) {
					std::cout << "Imie wyszukanego studenta: " << Studenci[i].imie << "\nNazwisko wyszukanego studenta " << Studenci[i].nazwisko << "\nNumer albumu studenta: " << Studenci[i].numerAlbumu << "\n\n";
				}
			}
			break;

		case 3:
			std::cout << "Podaj numer identyfikacyjny studenta, ktory chcesz wyszukac: ";
			std::cin >> numerTemporary;
			std::cout<<"\n";

			for (int i = 0; i < iloscStudentow; i++){
				if (numerTemporary == Studenci[i].numerAlbumu) {
					std::cout << "Imie wyszukanego studenta: " << Studenci[i].imie << "\nNazwisko wyszukanego studenta " << Studenci[i].nazwisko << "\nNumer albumu studenta: " << Studenci[i].numerAlbumu << "\n\n";
				}
			}
			break;

		case 4:
			std::cout<<"KONCZYMY PROGRAM\n\n";
			system("PAUSE");
			exit(0);
			break;
		}
		std::cout << "\n\n";
	}
}
void wypiszStudentow(int iloscStudentow, studenci Studenci[]) {
	for (int i = 0; i < iloscStudentow; i++) {
		std::cout<<"Imie: " << Studenci[i].imie << "\n";
		std::cout<<"Nazwisko: " << Studenci[i].nazwisko << "\n";
		std::cout<<"Numer albumu: " << Studenci[i].numerAlbumu << "\n";
		printf("\n");
	}
}