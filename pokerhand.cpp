using namespace std;
#include <array>
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

struct Card {
  string suit;
  int value;
  string name;

  Card(string suit, int value) {
    // TODO: Error checking logic to see if suit is one of the acceptable suits, and value is within a valid range
    if (suit.compare("Spades") != 0 && suit.compare("Hearts") != 0 && suit.compare("Clubs") != 0 && suit.compare ("Diamonds") != 0) {
      cout << "N/A suit" << endl;
/*put in correct suit, if this is an input*/
    }
    this->suit = suit;
    if (value <2 || value >15) {
      cout << "N/A value" << endl;
      /*put in correct value, if this is an input*/
    }
    this->value = value;

    // name logic ---> checked above
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

class Table{
   string tablecards[4];
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

vector <Player> Deal(Deck undealt, vector <Player> players) {  // feed in players in the future
   for (int j = 0; j < 2; j++) {
     for (int i = 0; i < players.size(); i++) {
       players[i].playercards[j] = undealt.cards[i];
       if (players[i].playercards[j] != nullptr) {
         cout << "D:" << players[i].playercards[j]->name << endl;
       }
     }
   }
   return players;
}

int main() { 
  Deck deck = Deck();
  for (int i = 0; i < 52; i++) cout << deck.cards[i]-> name << endl;
  cout << "\n\n\n\n";
  Player player1 = Player();
  Player player2 = Player();
  Player player3 = Player();
  vector<Player> playerlist;
  playerlist.push_back(player1);
  playerlist.push_back(player2);
  playerlist.push_back(player3);
  if (player1.playercards[0] != nullptr) {
     cout << player1.playercards[0]->name << endl;
  }
  playerlist = Deal(deck,playerlist);
  if (playerlist[0].playercards[0] != nullptr) {
     cout << player1.playercards[0]->name << endl;
  }
  // for ()

 }
