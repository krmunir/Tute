#pragma once

#include <iostream>
#include <string>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()


int getRandomNumber(int min, int max);

//First create the Creature class.Creatures have 5 attributes : A name(std::string), a symbol(a char), an amount of health(int), the amount of damage they do per attack(int), and the amount of gold they are carrying(int).Implement these as class members.Write a full set of getters(a get function for each member).Add three other functions : void reduceHealth(int) reduces the Creature's health by an integer amount. bool isDead() returns true when the Creature's health is 0 or less. void addGold(int) adds gold to the Creature.


class Creature {
protected:
	std::string m_name;
	char m_symbol;
	int m_health;
	int m_damage;
	int m_gold;

public:
	Creature(std::string name, char symbol, int health, int damage, int gold) : m_name{ name }, m_symbol{ symbol }, m_health{ health }, m_damage{ damage }, m_gold{ gold } {}
	
	std::string getName() { return m_name; }
	char getSymbol() { return m_symbol; }
	int getHealth() { return m_health; }
	int getDamage() { return m_damage; }
	int getGold() { return m_gold; }
	void reduceHealth(int hits) { m_health -= hits; }
	bool isDead() { if (m_health <= 0)  return true; else return false; }
	void addGold(int gold) { m_gold += gold; }
};


//Now we're going to create the Player class. The Player class inherits from Creature. Player has one additional member, the player's level, which starts at 1. The player has a custom name(entered by the user), uses symbol '@', has 10 health, does 1 damage to start, and has no gold.Write a function called levelUp() that increases the player's level and damage by 1. Also write a getter for the level member. Finally, write a function called hasWon() that returns true if the player has reached level 20.
//
//Write a new main() function that asks the user for their name and produces the output as follows :
//
//Enter your name : Alex
//Welcome, Alex.
//You have 10 health and are carrying 0 gold.
class Player :public Creature {
private:
	int m_level;
public:
	Player(std::string name) :m_level{ 1 }, Creature(name, '@', 10, 1, 0){}
	void levelUp() { ++m_level; ++m_damage; }
	int getLevel() { return m_level; }
	bool hasWon() { return (m_level >= 20) ?  true :  false; }
};

//Next up is the Monster class.Monster also inherits from Creature.Monsters have no non - inherited member variables.
//
//First, write an empty Monster class inheriting from Creature, and then add an enum inside the Monster class named Type that contains enumerators for the 3 monsters that we'll have in this game: DRAGON, ORC, and SLIME (you'll also want a MAX_TYPES enumerator, as that will come in handy in a bit).
class Monster : public Creature {
private:
public:
	enum Type {
		DRAGON,
		ORC,
		SLIME,
		MAX_TYPES
	};
	struct MonsterData {
		std::string name;
		char symbol;
		int health;
		int damage;
		int gold;
	};
	static MonsterData monsterData[MAX_TYPES];

	//m_name{ name }, m_symbol{ symbol }, m_health{ health }, m_damage{ damage }, m_gold{ gold } {}
	Monster(Type type) : Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].health, monsterData[type].damage, monsterData[type].gold) {}

	//add a static function to Monster named getRandomMonster(). This function should pick a random number between 0 and MAX_TYPES-1 and return a monster (by value) with that Type (you'll need to static_cast the int to a Type to pass it to the Monster constructor).
	static Monster getRandomMonster() {
		Type monsType{};
		monsType = static_cast<Type>(getRandomNumber(0, MAX_TYPES - 1));
		return Monster{ monsType };
	}

};



//Step 1: Create a struct type inside Monster named MonsterData. This struct should have a member for each attribute (name, symbol, health, damage, and gold).
//Step 2: Declare an array of that struct as a static member of the class named monsterData(declare this like a normal array member, and then add the word static before it).
//Step 3 : Add the following code outside of the class.This is the definition for our lookup table :
//
//Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
//{
//	{ "dragon", 'D', 20, 4, 100 },
//{ "orc", 'o', 4, 2, 25 },
//{ "slime", 's', 1, 1, 10 }
//};
//Now we can index this array to lookup any values we need!For example, to get a Dragon's gold, we can access monsterData[DRAGON].gold.

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 }
};

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
																				 // evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
