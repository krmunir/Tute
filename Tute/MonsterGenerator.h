#pragma once

class Monster;

//Create a static MonsterGenerator class. Create a static function named generateMonster(). This should return a Monster. 
//For now, make it return anonymous Monster(Monster::SKELETON, “Bones”, “*rattle*”, 4);
class MonsterGenerator
{
public:
	static Monster generateMonster();
	static int getRandomNumber(int min, int max);

};



