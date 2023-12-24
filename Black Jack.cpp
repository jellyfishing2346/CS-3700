// Faizan Khan
// Younes Taib


#include <iostream>
#include <ctime>
using namespace std;

// Setting up info for a black jack player
class blackJack
{
	public:
		void shuffleCards(bool []);
		void printCards(int);
		void printHands(int [], const int);
		int retrieveCards(bool []);
		int handScores(int [], const int);
		void printHandNScore(int [], const int, int[], const int);
};

// Shuffle the cards
void blackJack::shuffleCards(bool cardsDealing[])
{
	// Go through the index of the cards, check for non-existing cards 
	for (int index = 0; index < 52; index++)
	{
		cardsDealing[index] = false;
	}
}

// Determine the card's rank and its suit
void blackJack::printCards(int numberOfCards)
{
	// Calculate the rank by getting the remainder of the number of cards
	const int cardRank = (numberOfCards % 13);
	
	// If the rank is 0, print Ace which is A
	if (cardRank == 0)
	{
		cout << " Ace ";
	}
	// If the rank is less than 9, increase the rank by 1
	else if (cardRank < 9)
	{
		cout << cardRank + 1;
	}
	// If the rank equals 9,
	else if (cardRank == 9)
	{
		cout << " Toke ";
	}
	// If the rank equals 10, print J for Jack
	else if (cardRank == 10)
	{
		cout <<  " Jack ";
	}
	// If the rank is 11, print Q for Queen
	else if (cardRank == 11)
	{
		cout << " Queen ";
	}
	// Otherwise for the rank print King
	else
	{
		cout << " King ";
	}
	
	// The card suit is to divide the number of cards by 13
	const int cardSuit = (numberOfCards/13);
	
	// If the suit is 0, print C for cut
	if (cardSuit == 0)
	{
		cout << " Cut ";
	}
	// If the suit is 1, print D for double/double down
	else if (cardSuit == 1)
	{
		cout << " Double ";
	}
	// If the suit is 2, print H for hit
	else if (cardSuit == 2)
	{
		cout << " Hit ";
	}
	// Else print S for stand
	else
	{
		cout << " Stand ";
	}
}

// Print the cards that have the player has requested a hand 
void blackJack::printHands(int hands[], const int countingCards)
{
	// Go through the count of cards
	for (int index = 0; index < countingCards; index++)
	{
		// Find the next card in the deck of cards, the print the next card
		const int nextCard = hands[index];
		printCards(nextCard);
		cout << " ";
	}
	cout << endl; 
}

// Retrieve the cards from the deck
int blackJack::retrieveCards(bool inCardDeck[])
{
	// See if the card selected in the deck is true, otherwise default its -1 
 	bool deckOfCards = true;
	int  newCard = -1;
	
	// Randomly generate the new card with the entire deck of cards
	do
	{
		newCard = (rand() % 52 + 1);
		
		// If the new card is not the deck set it to false as its non-existing
		if (!inCardDeck[newCard])
		{
			deckOfCards = false;
		}
	}
	while (deckOfCards);

	// Return the existing new card
	return newCard;
}


// Get the house scores by retrieve the deck of cards in hands and the # count
int blackJack::handScores(int hands[], const int countingCards)
{
	// Set the aces and scores to 0 at the start
	int numOfAces = 0;
	int numScores = 0;
	
	// Go through the index of counting the cards thats being in the deck
	for (int index = 0; index < countingCards; ++index)
	{
		// Retrieve the next card in the deck for choosing a hand and its rank 
		const int nextCard = hands[index];
		const int nextRank = (nextCard % 13);
		// If the rank is 0, then increment the aces and score before retrieving
		if (nextRank == 0)
		{
			++numOfAces;
			++numScores;
		}
		// If nextRank < 9 then calculate scores to itself then the rank + 1
		else if (nextRank < 9)
		{
			numScores = numScores + (nextRank + 1);
		}
		// Otherwise increase the scores by 10
		else
		{
			numScores = numScores + 10; 
		}
	}	
	// If the aces > 0 && scores < 12 decrement aces and add scores to 10
	while (numOfAces > 0 && numScores < 12)
	{
		--numOfAces;
		numScores = numScores + 10; 
	}
	// Return the scores
	return numScores;
}

// Print the hand scores and count for player and house
void blackJack::printHandNScore(int hands[], const int hcCount, int pHand[], 
								const int playingCount)
{
	cout << "House(AI)'s Hand Score: " << handScores(hands, hcCount);
	cout << "-------------------------------" << endl;
	printHands(hands, hcCount);
	cout << "Player's Hand Score: " << handScores(hands, playingCount);
	cout << "-------------------------------" << endl;
	printHands(hands, playingCount);
	cout << endl; 
}

// Main function
int main()
{
	char playerOptions;

	// Prompt the user to enter a choice for the black jack game in our casino
	cout << "Hello, player welcome to Empire City Casino!" << endl;
	cout << "Want to play blackJack (y/n)";
	cin  >> playerOptions;
	
	// If they selected yes(y), then the game will run
	while (playerOptions == 'y')
	{
	// Create a random number generator
	time_t cardDealing;
	time(&cardDealing);
	srand(cardDealing);

	// Black jack data(deck, house cards, player cards, count # of cards) 
	bool dealTheCards[52];
	int countHouseCards = 0;
	int houseHands[12];
	int countPlayerCards = 0;
	int playerHands[12];
	blackJack user; 

	// Call the cards to be shuffled for both player and house, (count = 2)
	user.shuffleCards(dealTheCards);
	playerHands[0] = user.retrieveCards(dealTheCards);
	houseHands[0] = user.retrieveCards(dealTheCards);
	playerHands[1] = user.retrieveCards(dealTheCards);
	houseHands[1] = user.retrieveCards(dealTheCards);
	countHouseCards = 2;
	countPlayerCards = 2; 

	// Hands section
	cout << "             Hands                  " << endl;
	cout << "------------------------------------" << endl;
	cout << endl;

	// Player options and if they want a hit or a stand
	bool playerHits = true;

	// The player scores stores the # of their counts and the hands they took
	int pScore = user.handScores(playerHands, countPlayerCards);

	// Show the house and player's hands in a continuous loop
	do
	{
		// Count the house's cards
		cout << "House(AI)'s Hand" << endl;
		cout << "House(AI): ";
		user.printCards(countHouseCards);
		cout << endl;

		// Count the player's hand and its cards
		cout << "Player's Hand " 
			 << user.handScores(playerHands, countPlayerCards) 
			 << endl; 
		user.printCards(countPlayerCards);
		user.printHands(playerHands, countPlayerCards);
		
		// Ask the player if they want a hit(extra card) or stand(no card)
		cout << "Hit or Stay (H/S): ";
		cin  >> playerOptions;
		
		// If the player chooses a hit retrieve a card and add to their deck	
		if (playerOptions == 'H')
		{
			playerHands[countPlayerCards] = user.retrieveCards(dealTheCards);
			++countPlayerCards; 
		}

		// If they pick stand keep the count of their cards whatever they have
		else if (playerOptions == 'S')
		{
			playerHits = false;
		}

		// Otherwise the choice is not valid 
		else
		{
			cout << "The choice entered is not valid! Try again!";
		}
		cout << endl; 

		// Retrieve the player's total hand scores
		pScore = user.handScores(playerHands, countPlayerCards);
	
		// If the player gets 21, they win the game
		if (pScore == 21)
		{
			cout << "The Player wins the Game!" << endl; 
		}
	
		// If the player gets greater than 21, then the house wins
		else if (pScore > 21)
		{
			cout << "The House(AI) wins the Game!" << endl;
			user.printHandNScore(houseHands, countHouseCards, playerHands, 
						 	     countPlayerCards);
		}
	
		// If the player gets less than 21, then evaluate the following
		else if (pScore < 21)
		{
			
			int hScore = user.handScores(houseHands, countHouseCards);
			
			// Get the cards of the house if they have less than 17
			while (hScore < 17)
			{
				houseHands[countHouseCards] = user.retrieveCards(dealTheCards);
				++countHouseCards;
				hScore = user.handScores(houseHands, countHouseCards);
			}

			// If the house goes over 21, then the player wins the game
			bool houseBusts = (hScore > 21);
			if (houseBusts)
			{
				cout << "The Player wins the Game!" << endl;
				user.printHandNScore(houseHands, countHouseCards, playerHands, 
								     countPlayerCards);
			}

			// if the pscore > hscore or pscore < 21, the player wins 
			else if (pScore > hScore && pScore < 21)
			{
				cout << "The Player wins the Game!" << endl;
			}

			// Otherwise evaluate the other conditions
			else
			{
				// If the player score is qual to house score, its a tie
				if (pScore == hScore)
				{
				  cout << "Tie(Push)!" << endl;
				  user.printHandNScore(houseHands, countHouseCards, playerHands, 
									countPlayerCards);
				}
				// If the player score is greater than house score, player wins
				else if (pScore > hScore)
				{
				  cout << "The Player wins the Game!" << endl;
			  	  user.printHandNScore(houseHands, countHouseCards, playerHands,
									 countPlayerCards);
			    }
				// Otherwise the house wins
			    else
			    {
				 cout << "The House(AI) wins the Game!" << endl; 
				 user.printHandNScore(houseHands, countHouseCards, playerHands, 
									 countPlayerCards);
			    }
			}	
	}
	

	}

	// Keep looping if the the player's score and hits is less than 22
	while (playerHits && pScore < 22);
	}

	// Otherwise print the exit message
	if (playerOptions == 'n')
	{
		cout << "Have a good day and tell a friend about our casino!" << endl;
	}	
    // Otherwise the choice is not valid
	else
	{
		cout << "The choice entered is not valid! Try again!" << endl;
	}
	system("PAUSE");
	return 0; 
}