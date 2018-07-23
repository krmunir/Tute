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


//Create a public member function named dealCard(), which should return a const reference to the current card and advance the index. shuffleDeck() should also be updated to reset m_cardIndex (since if you shuffle the deck, you’ll start dealing from the top of the deck again).

class Deck{
private:
	std::array<Card,52> m_deck;
	int m_cardIndex;

public:
	 Deck();
	 void printDeck();
	 void shuffleDeck();
	 const Card& dealCard();

private:
	static void swapCard(Card &a, Card &b);
	static int getRandomNumber(int min, int max);
	 
};