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

void fightMonster();

enum class GameStatus {
	IN_PROGRESS,
	PLAYER_WON,
	PLAYER_DIED
};

int main()
{
	GameStatus status{ GameStatus::IN_PROGRESS };

	std::string playerName{};

	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // get rid of first result

	std::cout << "What is your name? ";
	std::cin >> playerName;
	Player player(playerName);
	std::cout << "Welcome, " << player.getName() << "." << std::endl;

	while (status == GameStatus::IN_PROGRESS) {
		Monster currMonster = Monster::getRandomMonster();
		std::cout << "You have encountered a " << currMonster.getName() << " (" << currMonster.getSymbol() << ")" << std::endl;

		status = fightMonster(player, currMonster);


	}




	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}


GameStatus fightMonster(Player& player, Monster& monster) {
	char response;
	bool inFight = true;

	while (inFight) {
		std::cout << "(r)un or (f)ight: ";
		std::cin >> response;

		if ('r' == response) {
			//run
			if (1 == getRandomNumber(0, 1)) {
				//you got away
				inFight = false;
				return GameStatus::IN_PROGRESS;
			}
			else {
				//you didnt get away
				std::cout << "You failed to flee" << std::endl;
				std::cout << "The " << monster.getName() << "hit you for " << monster.getDamage() << " damage" << std::endl;
				player.reduceHealth(monster.getDamage());
				if (player.getHealth() <= 0) {
					inFight = false;
					return GameStatus::PLAYER_DIED;
				}
			}
		}
		else if ('f' == response) {
			//fight
			std::cout << "You hit the " << monster.getName() << " for " << player.getDamage << " damage" << std::endl;
			monster.reduceHealth(player.getDamage());
			if (monster.getHealth() <= 0) {
				//level up
				player.levelUp();
				player.addGold(monster.getGold());
				std::cout << "You killed the " << monster.getName() << std::endl;
				std::cout << "You are now on level " << player.getLevel() << std::endl;
				std::cout << "You now have " << player.getGold() << " gold" << std::endl;
				inFight = false;
				return GameStatus::IN_PROGRESS;
			}
			std::cout << "The " << monster.getName() << "hit you for " << monster.getDamage() << " damage" << std::endl;
			player.reduceHealth(monster.getDamage());
			if (player.getHealth() <= 0) {
				inFight = false;
				return GameStatus::PLAYER_DIED;
			}
		}
		else {
			//invalid response
			std::cout << "Invalid entry" << std::endl;
		}
	}
}






