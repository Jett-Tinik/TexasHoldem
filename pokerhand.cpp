#include <array>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int counter = 0;

struct Card {
	string name;
	string suit;
	int value;

	Card(string suit, int value) {
		// TODO: Error checking logic to see if suit is one of the acceptable suits, and value is within a valid range
		if (suit.compare("Spades") != 0 && suit.compare("Hearts") != 0 && suit.compare("Clubs") != 0 && suit.compare ("Diamonds") != 0) {
			cout << "N/A suit" << endl;
			/*put in correct suit, if this is an input*/
		}
		this->suit = suit;
		if (value < 2 || value > 15) {
			cout << "N/A value" << endl;
			/*put in correct value, if this is an input*/
		}
		this->value = value;

		// name logic ---> checked above --> use hash map for this
		string nums[13] = {"Two",   "Three", "Four", "Five", "Six",
							"Seven", "Eight", "Nine", "Ten",  "Jack",
							"Queen", "King",  "Ace"};
		this->name = nums[value-2] + " of " + suit;
	}
};

class Player {
	public:
		Card* playercards[2];  // Array for holding 2 cards

	Player() {
		// Initialize the player with empty cards
		for (int i = 0; i < 2; i++) {
			playercards[i] = nullptr;
		}
	}
};

class Deck{
	public:
		array<Card*, 52> cards;

	Deck() {
		srand(time(0));
		shuffle();
		position = 0;
	}

	void shuffle() {
		string suit[4] = {"Spades", "Clubs", "Hearts", "Diamonds"};
		cards.fill(nullptr);
		int i;
		for (int a = 0; a < 4; a++) {
			for (int b = 2; b <= 14; b++) {
				i = rand() % 52;
				while (true) {
					if (cards[i] == nullptr) {
						cards[i] = new Card(suit[a], b);
						break;
					}
					i = (i + 1) % 52;
				}
			}
		}
	}

  // TODO: Make a deal function
  // Card deal() { return; }
	private:
		int position;
};

class Table {
	public:
		Card* tablecards[5];

	Table(Deck deck) {
		for (int k = 0; k < 5; k++) {
			tablecards[k] = deck.cards[counter];
            counter++;
        }
	}
};

vector <Player> Deal(Deck undealt, vector <Player> players) {  // feed in players in the future
    for (int i = 0; i < players.size(); i++) {
        for (int j = 0; j < 2; j++) {
            players[i].playercards[j] = undealt.cards[counter];
            counter++;
        }
	}
   	return players;
};
