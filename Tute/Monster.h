#pragma once

#include <iostream>
#include <string>

class Monster
{

public:
	enum MonsterType {
		DRAGON,
		GOBLIN,
		OGRE,
		ORC,
		SKELETON,
		TROLL,
		VAMPIRE,
		ZOMBIE,
		MAX_MONSTER_TYPES
	};

private:
	MonsterType m_mtype;
	std::string m_name;
	std::string m_roar;
	int m_hitPoints;

public:
	Monster(MonsterType mtype = MonsterType::SKELETON, std::string name = "Bones", std::string roar = "*rattle*", int hitpoints = 4)
		:
		m_mtype{ mtype },
		m_name{ name },
		m_roar{ roar },
		m_hitPoints{ hitpoints }
	{}

	std::string getTypeString();
	void print();

};

