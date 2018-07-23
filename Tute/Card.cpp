
#include <iostream>

#include "Card.h"

void Card::printCard() const
{
	switch (m_rank)
	{
	case RANK_2:		std::cout << '2'; break;
	case RANK_3:		std::cout << '3'; break;
	case RANK_4:		std::cout << '4'; break;
	case RANK_5:		std::cout << '5'; break;
	case RANK_6:		std::cout << '6'; break;
	case RANK_7:		std::cout << '7'; break;
	case RANK_8:		std::cout << '8'; break;
	case RANK_9:		std::cout << '9'; break;
	case RANK_10:		std::cout << 'T'; break;
	case RANK_JACK:		std::cout << 'J'; break;
	case RANK_QUEEN:	std::cout << 'Q'; break;
	case RANK_KING:		std::cout << 'K'; break;
	case RANK_ACE:		std::cout << 'A'; break;
	}

	switch (m_suit)
	{
	case SUIT_CLUB:		std::cout << 'C'; break;
	case SUIT_DIAMOND:	std::cout << 'D'; break;
	case SUIT_HEART:	std::cout << 'H'; break;
	case SUIT_SPADE:	std::cout << 'S'; break;
	}
}

int Card::getCardValue() const
{
	switch (m_rank)
	{
	case RANK_2:		return 2;
	case RANK_3:		return 3;
	case RANK_4:		return 4;
	case RANK_5:		return 5;
	case RANK_6:		return 6;
	case RANK_7:		return 7;
	case RANK_8:		return 8;
	case RANK_9:		return 9;
	case RANK_10:		return 10;
	case RANK_JACK:		return 10;
	case RANK_QUEEN:	return 10;
	case RANK_KING:		return 10;
	case RANK_ACE:		return 11;
	}

	return 0;
}

Deck::Deck() {
	// we could initialize each card individually, but that would be a pain. let's use a loop.
	int card = 0;
	for (int suit = 0; suit < Card::CardSuit::MAX_SUITS; ++suit)
		for (int rank = 0; rank < Card::CardRank::MAX_RANKS; ++rank)
		{
			m_deck[card].m_suit = static_cast<Card::CardSuit>(suit);
			m_deck[card].m_rank = static_cast<Card::CardRank>(rank);
			++card;
		}
	m_cardIndex = 0;
}

void Deck::printDeck()
{
	for (const auto &card : m_deck)
	{
		card.printCard();
		std::cout << ' ';
	}

	std::cout << '\n';
}

void Deck::swapCard(Card &a, Card &b)
{
	Card temp = a;
	a = b;
	b = temp;
}

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int Deck::getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
																				 // evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void Deck::shuffleDeck()
{
	// Step through each card in the deck
	for (int index = 0; index < 52; ++index)
	{
		// Pick a random card, any card
		int swapIndex = getRandomNumber(0, 51);
		// Swap it with the current card
		swapCard(m_deck[index], m_deck[swapIndex]);
	}
	m_cardIndex = 0;
}

const Card& Deck::dealCard() {
	return (m_deck[m_cardIndex++]);
}
