#pragma once

#include<iostream>
#include<cstdlib>
#include<string>
#include <windows.h>

class Opponent {
public:
	std::string TankName;
	int HP = 100;
	int DPS = 12;

	int tier = 1;

	struct Ammo {
		int Penetration = 25;
		int iloscPociskow = 10;
	};
	Ammo BasicAmmo;
	Ammo GoldAmmo;

	int Armor = 15;
	float GunHandling = 0.4; // wplywa na RNG


	void upgrading();
};
