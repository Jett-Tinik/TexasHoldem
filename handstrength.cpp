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

    CombinedHand ch = CombinedHand();
    ch = Combine(table, playerlist[0]);
    for (int i = 0; i < 7; i++) {
        cout << ch.combinedcards[i]->name << endl;
	}
	//cout << ch.combinedcards[0]->name << endl;
    
    vector<int> result = Quantity(ch);

    // Check the size of the result vector to determine how many values to display
    int resultSize = result.size();
    for (int i = 0; i < resultSize; i++) {
    cout << result[i] << " ";
    }
    cout << endl;  
}