#include <iostream>
#include "Hexagon.h"

using namespace std;

int main(){
	bool play = true;
	int option;
	Hexagon board;
	board.show_state();
	while (play) {	
		int i, j;
		cin >> i;
		cin >> j;
		board.add_edge(i, j);
		board.modify_state(i, j);
		board.show_state();
		cout << "Press 0 to keep playing" << endl;
		cin >> option;
		if (option != 0)
			play = false;
	}
	return 0;
}