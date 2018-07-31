#include <utility> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cstdint>
#include <vector>
#include <initializer_list>
#include <assert.h>

#include "Creature.h"

int main()
{
	std::string name;

	std::cout << "Enter your name: ";
	std::cin >> name;
	
	Player player{ name };
	std::cout << "Welcome, " << name << std::endl;
	std::cout << "You have " << player.getHealth() << " health and are carrying " << player.getGold() << " gold.";

	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}


