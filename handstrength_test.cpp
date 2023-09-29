/* go down the hand strenghts from Straight flush to high card
 */
using namespace std;
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <array>
#include <cstdlib>
#include <iostream>
#include <string>

const string ranks = "23456789TJQKA";
const string suits = "CDHS";

// Function to evaluate a poker hand
string evaluatePokerHand(const vector<string>& playerHand,
                         const vector<string>& communityCards) {
  // Combine player's hole cards and community cards
  vector<string> combinedHand = playerHand;
  combinedHand.insert(combinedHand.end(), communityCards.begin(),
                      communityCards.end());

  // Sort the combined hand by rank
  sort(combinedHand.begin(), combinedHand.end(),
       [](const string& a, const string& b) {
         return ranks.find(a[0]) < ranks.find(b[0]);
       });

  // Count the frequency of each rank
  map<char, int> rankCount;
  for (const string& card : combinedHand) {
    rankCount[card[0]]++;
  }

  // Check for specific hand combinations
  bool isFlush = true;
  bool isStraight = true;

  // Check for flush
  for (int i = 1; i < 7; ++i) {
    if (combinedHand[i][1] != combinedHand[0][1]) {
      isFlush = false;
      break;
    }
  }

  // Check for straight
  for (int i = 1; i < 7; ++i) {
    if (ranks.find(combinedHand[i][0]) !=
        ranks.find(combinedHand[i - 1][0]) + 1) {
      isStraight = false;
      break;
    }
  }

  // Evaluate the hand based on the highest possible combination
  if (isFlush && isStraight) {
    return "Straight Flush";
  } else if (rankCount.rbegin()->second == 4) {
    return "Four of a Kind";
  } else if (rankCount.rbegin()->second == 3 &&
             next(rankCount.rbegin())->second == 2) {
    return "Full House";
  } else if (isFlush) {
    return "Flush";
  } else if (isStraight) {
    return "Straight";
  } else if (rankCount.rbegin()->second == 3) {
    return "Three of a Kind";
  } else if (rankCount.rbegin()->second == 2 && rankCount.size() == 3) {
    return "Two Pair";
  } else if (rankCount.rbegin()->second == 2) {
    return "One Pair";
  } else {
    return "High Card";
  }
}

int main() {
  // Example player's hole cards and community cards
  vector<string> playerHand = {"AC", "AD"};
  vector<string> communityCards = {"2H", "3D", "4S", "5C", "6H"};

  // Evaluate the player's hand
  string result = evaluatePokerHand(playerHand, communityCards);

  // Output the result
  cout << "Player's Hole Cards: " << playerHand[0] << " " << playerHand[1]
       << endl;
  cout << "Community Cards: ";
  for (const string& card : communityCards) {
    cout << card << " ";
  }
  cout << endl;
  cout << "Hand Rank: " << result << endl;

  return 0;
}