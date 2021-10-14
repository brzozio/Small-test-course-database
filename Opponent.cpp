#include<iostream>
#include<cstdlib>
#include<string>
#include <windows.h>
#include "Opponent.h"


void Opponent::upgrading() {
	HP += 20;
	DPS += 15;
	Armor += 7;
	GunHandling -= 0.02; // wplywa na celnosc strzalu
	BasicAmmo.Penetration += 10;
	GoldAmmo.Penetration += 15;
}
