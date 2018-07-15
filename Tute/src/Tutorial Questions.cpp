#include <algorithm> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>

enum class rank {
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE,
	MAX_RANKS
};

enum class suit {
	HEARTS,
	DIAMONDS,
	CLUBS,
	SPADES,
	MAX_SUITS
};

struct card
{
	suit cardSuit;
	rank cardRank;
};

void printCard(const card &c);
void initialiseDeck(std::array<card, 52> &deck);
void printDeck(const std::array<card,52> &deck);
void swapCard(card &card1, card &card2);
void shuffleDeck(std::array<card, 52> &deck);
int getCardValue(const card &c);

int main()
{
	
	std::array<card, 52> deck;

	initialiseDeck(deck);

	/*for (int i = 0; i < 52; ++i)
	{
		printCard(deck[i]);
		std::cout << " ";
	}*/

	printDeck(deck);

	shuffleDeck(deck);

	std::cout << std::endl << std::endl;
	printDeck(deck);

	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}

void printCard(const card &c) {
	switch (c.cardRank)
	{
	case rank::TWO:
		std::cout << "2";
		break;
	case rank::THREE:
		std::cout << "3";
		break;
	case rank::FOUR:
		std::cout << "4";
		break;
	case rank::FIVE:
		std::cout << "5";
		break;
	case rank::SIX:
		std::cout << "6";
		break;
	case rank::SEVEN:
		std::cout << "7";
		break;
	case rank::EIGHT:
		std::cout << "8";
		break;
	case rank::NINE:
		std::cout << "9";
		break;
	case rank::TEN:
		std::cout << "10";
		break;
	case rank::JACK:
		std::cout << "J";
		break;
	case rank::QUEEN:
		std::cout << "Q";
		break;
	case rank::KING:
		std::cout << "K";
		break;
	case rank::ACE:
		std::cout << "A";
		break;
	default:
		std::cout << "Unknown Rank ";
		break;
	}
	
	switch (c.cardSuit)
	{
	case suit::HEARTS:
		std::cout << "H";
		break;
	case suit::DIAMONDS:
		std::cout << "D";
		break;
	case suit::CLUBS:
		std::cout << "C";
		break;
	case suit::SPADES:
		std::cout << "S";
		break;
	default:
		std::cout << "Unknown Suit ";
		break;
	}


}

void initialiseDeck(std::array<card, 52> &deck){
	suit s;
	rank r;

	int maxSuits = static_cast<int> (suit::MAX_SUITS);
	int maxRanks = static_cast<int> (rank::MAX_RANKS);

	//loop through 4 suits
	for (int i = 0; i < maxSuits; ++i)
	{
		//loop through 13 ranks per suit
		for (int j = 0; j < maxRanks; ++j)
		{
			s = static_cast<suit> (i);
			r = static_cast<rank> (j);
			deck[(13 * i) + j].cardSuit = s;
			deck[(13 * i) + j].cardRank = r;
		}
	}
}

void printDeck(const std::array<card, 52> &deck)
{
	for (card c : deck) {
		printCard(c);
		std::cout << " ";
	}



}

void swapCard(card &card1, card &card2)
{
	card temp{};

	temp = card2;
	card2 = card1;
	card1 = temp;
}

void shuffleDeck(std::array<card, 52> &deck)
{
	//set seed for random number generator
	//std::srand(static_cast<unsigned int> (std::time(0)));
	//std::srand(std::time(0));
	std::srand(77777);

	std::rand();
	for (int i = 0; i < 52; ++i)
	{
		int randNum = (std::rand() % 53);
		swapCard(deck[i], deck[randNum]);
	}

}

int getCardValue(const card &c)
{
	switch (c.cardRank)
	{
	default:
		break;
	}
	return 0;
}




