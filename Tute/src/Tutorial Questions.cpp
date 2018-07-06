#include <iostream>
#include<string>

int main() {

	enum class MonsterType
	{
		//orcs, goblins, trolls, ogres, and skeletons
		ORC,
		GOBLIN,
		TROLL,
		OGRE,
		SKELETON
	};

	MonsterType monster1{ MonsterType::GOBLIN };
	MonsterType monster2{ MonsterType::OGRE };

	std::cout << "Monster 1 is of type " << static_cast<int>(monster1) << std::endl;
	std::cout << "Monster 2 is of type " << static_cast<int>(monster2) << std::endl;

	//std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}