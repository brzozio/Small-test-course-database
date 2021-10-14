#include<iostream>
#include<cstdlib>
#include<string>
#include <windows.h>
#include "Tank.h"


int main() {
	std::cout << "Witaj w kreatorze tankietki Dowodco ..." << std::endl;
		Sleep(2000);
		system("cls");
	std::cout << "Nadeszla ta wielkopomna chwila na rozpoczecie walki z innymi tankietkami ..." << std::endl;
		Sleep(2000);
		system("cls");;
	std::cout << "Zatem przygotuj swoja ukochana tankietke ..."; 
		Sleep(2000);
		system("cls");
	std::cout << "Mistrzu!" << std::endl;
		Sleep(2000);
		system("cls");
	Tank tankietka;
	tankietka.createTank();
	tankietka.battle();
}