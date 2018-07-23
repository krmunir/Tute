#pragma once

#include<array>

class Card
{
public:
	enum CardSuit
	{
		SUIT_CLUB,
		SUIT_DIAMOND,
		SUIT_HEART,
		SUIT_SPADE,
		MAX_SUITS
	};
	enum CardRank
	{
		RANK_2,
		RANK_3,
		RANK_4,
		RANK_5,
		RANK_6,
		RANK_7,
		RANK_8,
		RANK_9,
		RANK_10,
		RANK_JACK,
		RANK_QUEEN,
		RANK_KING,
		RANK_ACE,
		MAX_RANKS
	};

private:
	CardSuit m_suit;
	CardRank m_rank;

public:
	Card(CardRank rank=CardRank::RANK_QUEEN, CardSuit suit=CardSuit::SUIT_HEART) : m_suit{ suit }, m_rank{ rank } {}
	void printCard() const;
	int getCardValue() const;
	friend class Deck;
};


//4b) Okay, now let’s work on a Deck class.The deck needs to hold 52 cards, so use a private std::array member to create a fixed array of 52 cards named m_deck.Second, create a constructor that takes no parameters and initializes m_deck with one of each card(modify the code from the original main() function).Inside the initialization loop, create an anonymous Card object and assign it to your deck element.Third, move printDeck into the Deck class as a public member.Fourth, move getRandomNumber() and swapCard() into the Deck class as a private static members(they’re just helper functions, so they don’t need access to *this).Fifth, move shuffleDeck into the class as a public member.

class Deck{
private:
	std::array<Card,52> m_deck;

public:
	 Deck();
	 void printDeck();
	 void shuffleDeck();

private:
	static void swapCard(Card &a, Card &b);
	static int getRandomNumber(int min, int max);
	 
};