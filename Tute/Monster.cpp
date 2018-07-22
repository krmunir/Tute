
#include <iostream>

#include "Monster.h"


void Monster::print() {
	//Bones the skeleton has 4 hit points and says *rattle*
	std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << std::endl;
}


std::string Monster::getTypeString() {
	switch (m_mtype)
	{
	case Monster::DRAGON: return "dragon";
	case Monster::GOBLIN: return "goblin";
	case Monster::OGRE: return "ogre";
	case Monster::ORC: return "orc";
	case Monster::SKELETON: return "skeleton";
	case Monster::TROLL: return "troll";
	case Monster::VAMPIRE: return "vampire";
	case Monster::ZOMBIE: return "zombie";
	default: return "unknown monster type???";
	}
}