#include "MonsterGenerator.h"
#include "Monster.h"


//Now edit function generateMonster() to generate a random MonsterType(between 0 and Monster::MAX_MONSTER_TYPES - 1) 
//and a random hit points(between 1 and 100).This should be fairly straightforward.
//Once you’ve done that, define two static fixed arrays of size 6 inside the function(named s_names and s_roars) 
//and initialize them with 6 names and 6 sounds of your choice.
//Pick a random name from these arrays.

Monster MonsterGenerator::generateMonster()
{
	Monster m;
	m.m_mtype = static_cast<Monster::MonsterType>(getRandomNumber(0, static_cast<int>(Monster::MonsterType::MAX_MONSTER_TYPES - 1)));
	m.m_hitPoints = getRandomNumber(1, 100);
	static std::string s_names[6]{"Frank", "Benny", "Gloria", "Mahmud", "Yusuf", "Shen"};
	static std::string s_roars[6]{"grrrr","whooo", "ickyickyicky", "booo", "gotcha!", "weeeeee"};
	m.m_name = s_names[getRandomNumber(0, 5)];
	m.m_roar = s_roars[getRandomNumber(0, 5)];
	return m;
}

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int MonsterGenerator::getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
																				 // evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}