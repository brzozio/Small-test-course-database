#pragma once

#include<iostream>
#include<cstdlib>
#include<string>
#include <windows.h>

class Tank {
public:
	std::string TankName;
	int HP = 100;
	int DPS = 10;

	int tier = 1;

	struct Ammo {
		int Penetration = 16;
		int iloscPociskow = 10;
	};
	Ammo BasicAmmo; 
	Ammo GoldAmmo;	

	int Armor = 15;
	float GunHandling = 0.35; // wplywa na celnosc


	void createTank();
	void battle();
	void showStatistics();
	void upgrading();
};

