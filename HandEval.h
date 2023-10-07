#include "pokerhand.h"
#include <map>

using namespace std;

// Defining a global dictionary that matches string ranks with values
map<string, int> card_vals = {
    {"Two", 2},
    {"Three", 3},
    {"Four", 4},
    {"Five", 5},
    {"Six", 6},
    {"Seven", 7},
    {"Eight", 8},
    {"Nine", 9},
    {"Ten", 10},
    {"Jack", 11},
    {"Queen", 12},
    {"King", 13},
    {"Ace", 14}
};

// Function to evaluate the quantity of ranks and strength of the hand
vector<int> Quantity(CombinedHand hand) {
    int rank_array[13] = {0}; // Two to Ace
    for (int i = 0; i < 7; i++) {
        rank_array[card_vals[hand.combinedcards[i]->rank] - 2]++;
    }

    // Check for a flush
    int hearts = 0;
    int spades = 0;
    int diamonds = 0;
    int clubs = 0;
    for (int i = 0; i < 7; i++) {
        if (hand.combinedcards[i]->suit == "Hearts")
            hearts++;
        if (hand.combinedcards[i]->suit == "Spades")
            spades++;
        if (hand.combinedcards[i]->suit == "Diamonds")
            diamonds++;
        if (hand.combinedcards[i]->suit == "Clubs")
            clubs++;
    }
    bool isFlush = max({hearts, spades, diamonds, clubs}) >= 5;
    if (isFlush)
        return vector<int>{6};          

    // Check for a straight
    for (int i = 0; i < 9; i++) { // Start from index 0 to 8
        bool isStraight = true;
        for (int j = i; j < i + 5; j++) {
            if (rank_array[j] == 0) {
                isStraight = false;
                break;
            }
        }
        if (isStraight)
            return vector<int>{5, i + 6}; // Straight
    }

    int maxRank = *max_element(rank_array, rank_array + 13);
    int rank_location = 2 + distance(rank_array, max_element(rank_array, rank_array + 13));
    
    if (maxRank == 4)
        return vector<int>{8, rank_location}; // Four of a Kind
    else if (maxRank == 3) {
        int tripsRank = rank_location;
        int pairRank = -1;
        for (int i = 0; i < 13; i++) {
            if (rank_array[i] == 2) {
                pairRank = i + 2;
                break;
            }
        }
        if (pairRank != -1)
            return vector<int>{7, tripsRank, pairRank}; // Full House
        else
            return vector<int>{4, tripsRank}; // Three of a Kind
    } else if (maxRank == 2) {
    int highPairRank = -1;
    int lowPairRank = -1;
    for (int i = 12; i >= 0; i--) {
        if (rank_array[i] == 2) {
            if (highPairRank == -1) {
                highPairRank = i + 2;
            } else if (lowPairRank == -1) {
                lowPairRank = i + 2;
                break; // Exit the loop after finding the second pair (no three pair)
            }
        }
    }
    if (highPairRank != -1 && lowPairRank != -1)
        return vector<int>{3, highPairRank, lowPairRank}; // Two Pair
    else
        return vector<int>{2, rank_location}; // One Pair
    } else {
        // For High Card, find the highest rank among the cards
    int highCardRank = -1;
    for (int i = 12; i >= 0; i--) {
        if (rank_array[i] > 0) {
            highCardRank = i + 2;
            break; // Exit the loop after finding the highest rank
         }
    }
        return vector<int>{1, highCardRank}; // High Card
    }
}

//#include "pokerhand.h"

//using namespace std;
//combined cards array of strings (King of Spades, Queen of Diamonds)
//Qaunitity of ranks, quanity of suits,

//make GLOBAL dictionary that matches string with value
// (ex. "10" -> 10)

/*map<string, int> card_vals = {
    {"Two", 2},
    {"Three", 3},
    {"Four", 4},
    {"Five", 5},
    {"Six", 6},
    {"Seven", 7},
    {"Eight", 8},
    {"Nine", 9},
    {"Ten", 10},
    {"Jack", 11},
    {"Queen", 12},
    {"King", 13},
    {"Ace", 14}
};

int is_flush(CombinedHand hand) {
    int hearts = 0;
    int spades = 0;
    int diamonds = 0;
    int clubs = 0;
    for (int i=0; i<7; i++){
        if (hand.combinedcards[i]-> suit == "Hearts")
            hearts++;
        if (hand.combinedcards[i]-> suit == "Spades")
            spades++;
        if (hand.combinedcards[i]-> suit == "Diamonds")
            diamonds++;
        if (hand.combinedcards[i]-> suit == "Clubs")
            clubs++;
    }
    if (max({hearts,spades,diamonds,clubs}) >= 5)
        return true;
    return false;
}

vector <int> Quantity(CombinedHand hand){
    int rank_array[13] = {0}; // two to ace
    for (int i=0; i<7; i++) {
        if (hand.combinedcards[i]-> rank == "Two")
            rank_array[0]++;
        if (hand.combinedcards[i]-> rank == "Three")
            rank_array[1]++;
        if (hand.combinedcards[i]-> rank == "Four")
            rank_array[2]++;
        if (hand.combinedcards[i]-> rank == "Five")
            rank_array[3]++;
        if (hand.combinedcards[i]-> rank == "Six")
            rank_array[4]++;
        if (hand.combinedcards[i]-> rank == "Seven")
            rank_array[5]++;
        if (hand.combinedcards[i]-> rank == "Eight")
            rank_array[6]++;
        if (hand.combinedcards[i]-> rank == "Nine")
            rank_array[7]++;
        if (hand.combinedcards[i]-> rank == "Ten")
            rank_array[8]++;
        if (hand.combinedcards[i]-> rank == "Jack")
            rank_array[9]++;
        if (hand.combinedcards[i]-> rank == "Queen")
            rank_array[10]++;
        if (hand.combinedcards[i]-> rank == "King")
            rank_array[11]++;
        if (hand.combinedcards[i]-> rank == "Ace")
            rank_array[12]++;
    }
    int maxRank = *max_element(rank_array, rank_array + 13);
    int rank_location = 2 + distance(rank_array, max_element(rank_array, rank_array + 13));
    if (maxRank == 4)
        return vector <int>{ 8 , rank_location};
    else if (maxRank == 3)
        return vector <int>{ 4 , rank_location};
    else if (maxRank == 2)
        return vector <int>{ 2 , rank_location};
    else
        return vector <int>{ 1, rank_location};
    return vector <int>{ 0 , 0};
};

vector<int> FullHouse(CombinedHand hand) {
    int rank_array[13] = {0}; // two to ace
    for (int i = 0; i < 7; i++) {
        if (hand.combinedcards[i]->rank == "Two")
            rank_array[0]++;
        if (hand.combinedcards[i]-> rank == "Three")
            rank_array[1]++;
        if (hand.combinedcards[i]-> rank == "Four")
            rank_array[2]++;
        if (hand.combinedcards[i]-> rank == "Five")
            rank_array[3]++;
        if (hand.combinedcards[i]-> rank == "Six")
            rank_array[4]++;
        if (hand.combinedcards[i]-> rank == "Seven")
            rank_array[5]++;
        if (hand.combinedcards[i]-> rank == "Eight")
            rank_array[6]++;
        if (hand.combinedcards[i]-> rank == "Nine")
            rank_array[7]++;
        if (hand.combinedcards[i]-> rank == "Ten")
            rank_array[8]++;
        if (hand.combinedcards[i]-> rank == "Jack")
            rank_array[9]++;
        if (hand.combinedcards[i]-> rank == "Queen")
            rank_array[10]++;
        if (hand.combinedcards[i]-> rank == "King")
            rank_array[11]++;
        if (hand.combinedcards[i]-> rank == "Ace")
            rank_array[12]++;
    }
    
    int tripsRank = -1;
    int pairRank = -1;

    for (int i = 0; i < 13; i++) {
        if (rank_array[i] == 3) {
            tripsRank = i + 2; // Convert index to rank (2 to Ace)
        } else if (rank_array[i] == 2) {
            pairRank = i + 2; // Convert index to rank (2 to Ace)
        }
    }

    if (tripsRank != -1 && pairRank != -1) {
        return vector<int>{7, tripsRank, pairRank}; // Full House
    } else {
        return vector<int>{0, 0}; // Not a Full House
    }
}

   
// return vector [strength(trips)][what cards with trips]

*/

