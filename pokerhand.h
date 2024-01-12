#ifndef POKERHAND_H
#define POKERHAND_H

#include <array>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Card {
	string name;
	string suit;
    string rank;
	int value;
    //if(name has King then associate it with 3)

	Card(string suit, int value) {  
		// TODO: Error checking logic to see if suit is one of the acceptable suits, and value is within a valid range
		if (suit.compare("Spades") != 0 && suit.compare("Hearts") != 0 && suit.compare("Clubs") != 0 && suit.compare ("Diamonds") != 0) {
			cout << "N/A suit" << endl;
            exit(EXIT_FAILURE);
            /*put in correct suit, if this is an input*/
		}
		this->suit = suit;
		if (value < 2 || value > 15) {
			cout << "N/A value" << endl;
            exit(EXIT_FAILURE);
            /*put in correct value, if this is an input*/
		}
		this->value = value;

		// name logic ---> checked above --> use hash map for this ll
		string nums[13] = {"Two", "Three", "Four", "Five", "Six",
							"Seven", "Eight", "Nine", "Ten", "Jack",
							"Queen", "King", "Ace"};
        rank = nums[value-2];
		this->name = rank + " of " + suit;
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

struct Table {
    Card* tablecards[5];
    Table(Deck deck, int counter) {
        for (int k = 0; k < 5; k++) {
            tablecards[k] = deck.cards[counter];
            counter++;
        }
    }
};

vector <Player> Deal(Deck undealt, vector <Player> players) {  // feed in players in the future
    int counter = 0;
    for (int j = 0; j < 2; j++) {
        for (size_t i = 0; i < players.size(); i++) {
            players[i].playercards[j] = undealt.cards[counter];
            counter++;
        }
	}
   	return players;
};

class CombinedHand {
	public:
	Card* combinedcards[7];  // Array for holding 2 cards

	CombinedHand() {
	// Initialize the player with empty cards
		for (int k = 0; k < 7; k++) {
			combinedcards[k] = nullptr;
		}
	}
};

CombinedHand Combine(Table table, Player player) {
	CombinedHand ch = CombinedHand();

	for (int i = 0; i < 7; i++) {
		if (i < 2) {
		    ch.combinedcards[i] = player.playercards[i];
		} else {
		    ch.combinedcards[i] = table.tablecards[i - 2];
		}
	}
	//CardSort(combinedhand.combinedcards)
	//cout << ch.combinedcards[0]->name << endl;
	return ch;
}

#endif /* POKERHAND_H */