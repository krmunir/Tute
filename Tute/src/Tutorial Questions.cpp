#include <utility> // for std::swap, use <utility> instead if C++11
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

enum class gameResult {
	PLAYER_WINS,
	DEALER_WINS,
	GAME_IN_PROGRESS
};

enum class play {
	HIT,
	STAND
} response;


void printCard(const card &c);
void initialiseDeck(std::array<card, 52> &deck);
void printDeck(const std::array<card,52> &deck);
void swapCard(card &card1, card &card2);
void shuffleDeck(std::array<card, 52> &deck);
int getCardValue(const card &c);
gameResult playBlackjack(std::array<card, 52> &deck);
//void dealCard(std::array<card, 52> &deck, card *deckCardPtr, )
play hitOrStand();

int playerScore{ 0 };
int dealerScore{ 0 };


int main()
{
	
	std::array<card, 52> deck;
	gameResult result{ gameResult::GAME_IN_PROGRESS };
	initialiseDeck(deck);
	shuffleDeck(deck);

	result = playBlackjack(deck);
	switch (result)
	{
	case gameResult::PLAYER_WINS:
		std::cout << "You win!";
		break;
	case gameResult::DEALER_WINS:
		std::cout << "Dealer wins!";
		break;
	default:
		std::cout << "Unknown result????";
		break;
	}

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
	std::srand(static_cast<unsigned int> (std::time(0)));
	//std::srand(std::time(0));
	//std::srand(77777);

	std::rand();
	for (int i = 0; i < 52; ++i)
	{
		int randNum = (std::rand() % 52);
		swapCard(deck[i], deck[randNum]);
	}

}

int getCardValue(const card &c)
{
	switch (c.cardRank)
	{
	case rank::TWO:
		return 2;
	case rank::THREE:
		return 3;
	case rank::FOUR:
		return 4;
	case rank::FIVE:
		return 5;
	case rank::SIX:
		return 6;
	case rank::SEVEN:
		return 7;
	case rank::EIGHT:
		return 8;
	case rank::NINE:
		return 9;
	case rank::TEN:
	case rank::JACK:
	case rank::QUEEN:
	case rank::KING:
		return 10;
	case rank::ACE:
		return 11;
	case rank::MAX_RANKS:
	default:
		return 0;
	}
}

gameResult playBlackjack(std::array<card, 52> &deck)
{
	card *deckCardPtr { &deck[0] };
	gameResult gameStatus{ gameResult::GAME_IN_PROGRESS };

	//dealer gets one card
	dealerScore += getCardValue(*deckCardPtr);
	++deckCardPtr;

	//player gets two cards
	playerScore += getCardValue(*deckCardPtr);
	++deckCardPtr;
	playerScore += getCardValue(*deckCardPtr);
	++deckCardPtr;


	do
	{
		//ask player if he wants to hit or stand
		response = hitOrStand();

		switch (response)
		{
		case play::HIT:
			playerScore += getCardValue(*deckCardPtr);
			++deckCardPtr;
			if (playerScore>21	)
			{
				std::cout << "Your score is over 21." << std::endl;
				return gameResult::DEALER_WINS;
			}
			else
			{
				if (dealerScore<17)
				{
					//dealer picks a card
					dealerScore += getCardValue(*deckCardPtr);
					++deckCardPtr;
					if (dealerScore > 21)
					{
						std::cout << "Dealer's score is over 21." << std::endl;
						return gameResult::PLAYER_WINS;
					}
				}
				else {
					std::cout << "Dealer stands." << std::endl;
					std::cout << "Dealer's score: " << dealerScore << std::endl;
					std::cout << "Player's score: " << playerScore << std::endl;
					if (playerScore > dealerScore)
						return gameResult::PLAYER_WINS;
					else
						return gameResult::DEALER_WINS;
				}

			}
			break;
		case play::STAND:
			std::cout << "Player stands." << std::endl;
			std::cout << "Dealer's score: " << dealerScore << std::endl;
			std::cout << "Player's score: " << playerScore << std::endl;
			if (playerScore > dealerScore)
				return gameResult::PLAYER_WINS;
			else
				return gameResult::DEALER_WINS;
		}

	} while (gameStatus==gameResult::GAME_IN_PROGRESS);
}

play hitOrStand()
{
	char input{};

	do
	{
		//check hit or stand
		std::cout << "Dealer's score is " << dealerScore<<std::endl;
		std::cout << "Your score is " << playerScore<<std::endl;
		std::cout << "Do you want to (h)it or (s)tand? ";
		std::cin >> input;
		switch (input)
		{
		case 'h':
			std::cin.ignore(32767, '\n');
			return play::HIT;
			break;
		case 's':
			std::cin.ignore(32767, '\n');
			return play::STAND;
			break;
		default:
			input = 0;
			break;
		}

	} while (!input);
}




