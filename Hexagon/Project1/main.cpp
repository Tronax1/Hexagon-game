#include <iostream>
#include "Hexagon.h"

using namespace std;

int main(){
	bool game_over = false;
	int option;
	Hexagon board;
	board.show_state();
	while (!game_over) {
		cout << "Enter the starting and ending vertex"<<endl;
		int i, j;
		cin >> i;
		cin >> j;
		board.add_edge(i, j);
		board.modify_state(i, j);
		board.show_state();
		game_over = board.game_over();
	}
	cout << "Game over"<<endl;
	return 0;
}