#include <iostream>
#include<string>

enum class monsterType {
	OGRE,
	DRAGON,
	ORC,
	GIANT_SPIDER,
	SLIME
};

struct monster {
	monsterType mtype;
	std::string name;
	int health;
};

void printMonster(monster monst);

std::string monstType(monster monst);

int main() {
	monster ogre{ monsterType::OGRE, "Mean Ogre",100 };
	monster slime{ monsterType::SLIME, "Slimy Slime",50 };

	printMonster(ogre);
	printMonster(slime);
	std::cin.get();

	return 0;
}

void printMonster(monster monst) {
	std::cout << "My name is " << monst.name << " and I am a monster of type " << monstType(monst) << " and I have " << monst.health << " health" << std::endl;
}

std::string monstType(monster monst) {
	switch (monst.mtype)
	{
	case monsterType::OGRE:
		return "Ogre";
	case monsterType::DRAGON:
		return "Dragon";
	case monsterType::GIANT_SPIDER:
		return "Giant Spider";
	case monsterType::ORC:
		return "Orc";
	case monsterType::SLIME:
		return "Slime";
	default:
		return "Unknown type";
	}
}