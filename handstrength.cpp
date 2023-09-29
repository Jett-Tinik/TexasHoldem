#include "pokerhand.cpp"

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

    Table table = Table(deck);
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
}