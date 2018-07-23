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



void printDeck(const std::array<Card, 52> deck)
{
	for (const auto &card : deck)
	{
		printCard(card);
		std::cout << ' ';
	}

	std::cout << '\n';
}

void swapCard(Card &a, Card &b)
{
	Card temp = a;
	a = b;
	b = temp;
}

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
																				 // evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void shuffleDeck(std::array<Card, 52> &deck)
{
	// Step through each card in the deck
	for (int index = 0; index < 52; ++index)
	{
		// Pick a random card, any card
		int swapIndex = getRandomNumber(0, 51);
		// Swap it with the current card
		swapCard(deck[index], deck[swapIndex]);
	}
}



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

	// we could initialize each card individually, but that would be a pain. let's use a loop.
	int card = 0;
	for (int suit = 0; suit < max_suits; ++suit)
		for (int rank = 0; rank < max_ranks; ++rank)
		{
			deck[card].suit = static_cast<cardsuit>(suit);
			deck[card].rank = static_cast<cardrank>(rank);
			++card;
		}

	shuffledeck(deck);

	if (playblackjack(deck))
		std::cout << "you win!\n";
	else
		std::cout << "you lose!\n";

*/

	const Card cardQueenHearts(Card::RANK_QUEEN, Card::SUIT_HEART);
	cardQueenHearts.printCard();
	std::cout << " has the value " << cardQueenHearts.getCardValue() << '\n';


	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}



