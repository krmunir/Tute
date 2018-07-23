#include <utility> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>
#include <array>
#include <cassert>
#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()


#include "Monster.h"
#include "MonsterGenerator.h"



int main()
{
	
	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // If using Visual Studio, discard first random value

	for (int i = 0; i < 20; ++i)
	{
		Monster m = MonsterGenerator::generateMonster();
		m.print();

	}
	
	//std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}



