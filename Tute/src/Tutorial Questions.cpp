#include <iostream>
#include<string>

int main() {

	enum MonsterType 
	{
		//orcs, goblins, trolls, ogres, and skeletons
		MONSTER_ORC,
		MONSTER_GOBLIN,
		MONSTER_TROLL,
		MONSTER_OGRE,
		MONSTER_SKELETON
	};

	MonsterType monster1{ MONSTER_GOBLIN };
	MonsterType monster2{ MONSTER_OGRE };

	std::cout << "Monster 1 is of type " << monster1 << std::endl;
	std::cout << "Monster 2 is of type " << monster2 << std::endl;

	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}