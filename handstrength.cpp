#include "pokerhand.h"
#include "HandEval.h"

int main() {
	Deck deck = Deck();
	for (int i = 0; i < 52; i++) {
		cout << deck.cards[i]->name << endl;
	}
	cout << "\n\n\n\n";

	vector<Player> playerlist;
	int num_players = 3;
	for (int i = 0; i < num_players; i++) {
		playerlist.push_back(Player());
	}
	playerlist = Deal(deck, playerlist);   
    cout << "\n" << endl;


    Table table = Table(deck, num_players*2);
    cout << table.tablecards[0]->name << endl;
    cout << table.tablecards[1]->name << endl;
    cout << table.tablecards[2]->name << endl;
    cout << table.tablecards[3]->name << endl;
    cout << table.tablecards[4]->name << endl;
    cout << "\n" << endl;

    //  Can dynamically create player variables at the very end of this project
    CombinedHand chp1 = CombinedHand();
    chp1 = Combine(table, playerlist[0]);
    for (int i = 0; i < 7; i++) {
        cout << chp1.combinedcards[i]->name << endl;
	}

    vector<int> flush = is_flush(chp1);
    vector<int> straight = is_straight(chp1);
    vector<int> combs = combinations(chp1);

    // Check the size of the result vector to determine how many values to display
    int flushSize = flush.size();
    for (int i = 0; i < flushSize; i++) {
    cout << flush[i] << " ";
    }
    cout << endl;  

    int straightSize = straight.size();
    for (int i = 0; i < straightSize; i++) {
    cout << straight[i] << " ";
    }
    cout << endl;  

    int combsSize = combs.size();
    for (int i = 0; i < combsSize; i++) {
    cout << combs[i] << " ";
    }
    cout << endl;  

}