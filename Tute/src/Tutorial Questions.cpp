#include <utility> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>
#include <array>
#include <cassert>
#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()

#include "Card.h"


/*


struct Card
{
	CardRank rank;
	CardSuit suit;
};








char getPlayerChoice()
{
	std::cout << "(h) to hit, or (s) to stand: ";
	char choice;
	do
	{
		std::cin >> choice;
	} while (choice != 'h' && choice != 's');

	return choice;
}

bool playBlackjack(const std::array<Card, 52> deck)
{
	// Set up the initial game state
	const Card *cardPtr = &deck[0];

	int playerTotal = 0;
	int dealerTotal = 0;

	// Deal the dealer one card
	dealerTotal += getCardValue(*cardPtr++);
	std::cout << "The dealer is showing: " << dealerTotal << '\n';

	// Deal the player two cards
	playerTotal += getCardValue(*cardPtr++);
	playerTotal += getCardValue(*cardPtr++);

	// Player goes first
	while (1)
	{
		std::cout << "You have: " << playerTotal << '\n';
		char choice = getPlayerChoice();
		if (choice == 's')
			break;

		playerTotal += getCardValue(*cardPtr++);

		// See if the player busted
		if (playerTotal > 21)
			return false;
	}

	// If player hasn't busted, dealer goes until he has at least 17 points
	while (dealerTotal < 17)
	{
		dealerTotal += getCardValue(*cardPtr++);
		std::cout << "The dealer now has: " << dealerTotal << '\n';
	}

	// If dealer busted, player wins
	if (dealerTotal > 21)
		return true;

	return (playerTotal > dealerTotal);
}

*/

int main()
{
/*
	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // if using visual studio, discard first random value

	std::array<card, 52> deck;


	shuffledeck(deck);

	if (playblackjack(deck))
		std::cout << "you win!\n";
	else
		std::cout << "you lose!\n";

*/

	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // If using Visual Studio, discard first random value

	Deck deck;
	deck.printDeck();
	deck.shuffleDeck();
	deck.printDeck();

	
	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}



