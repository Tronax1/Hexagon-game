#include <iostream>
#include <algorithm>
#include "Hexagon.h"



Hexagon::Hexagon() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			graph[i][j] = -1;
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			UI[i][j] = ' ';
		}
	}
	UI[0][2] = '0';
	UI[0][6] = '1';
	UI[4][0] = '5';
	UI[4][8] = '2';
	UI[8][2] = '4';
	UI[8][6] = '3';
	table[0].position_x = 0;
	table[0].position_y = 2;
	table[1].position_x = 0;
	table[1].position_y = 6;
	table[2].position_x = 4;
	table[2].position_y = 8;
	table[3].position_x = 8;
	table[3].position_y = 6;
	table[4].position_x = 8;
	table[4].position_y = 2;
	table[5].position_x = 4;
	table[5].position_y = 0;
}
void Hexagon::add_edge(int i, int j){
	graph[i][j] = 0;
	graph[j][i] = 0;
}
void Hexagon::modify_state(int i, int j) {
	if (table[i].position_x == table[j].position_x) {
		int min = std::min(table[i].position_y, table[j].position_y);
		int max = std::max(table[i].position_y, table[j].position_y);
		for (int k = min + 1; k < max; k++) {
			UI[table[i].position_x][k] = '*';
		}
	}
	if (table[i].position_y == table[j].position_y) {
		int min = std::min(table[i].position_x, table[j].position_x);
		int max = std::max(table[i].position_x, table[j].position_x);
		for (int k = min + 1; k < max; k++) {
			UI[k][table[i].position_y] = '*';
		}
	}
	int min = std::min(i, j);
	int max = std::max(i,j);
	if (min == 0 && max == 5) {
		UI[1][1] = '*';
		UI[2][1] = '*';
		UI[3][1] = '*';
	}
	if (min == 4 && max == 5) {
		UI[5][1] = '*';
		UI[6][1] = '*';
		UI[7][1] = '*';
	}
	if (min == 1 && max == 2) {
		UI[1][7] = '*';
		UI[2][7] = '*';
		UI[3][7] = '*';
	}
	if (min == 2 && max == 3) {
		UI[5][7] = '*';
		UI[6][7] = '*';
		UI[7][7] = '*';
	}
	if (min == 3 && max == 5) {
		UI[4][1] = '*';
		UI[5][2] = '*';
		UI[6][3] = '*';
		UI[7][4] = '*';
		UI[8][5] = '*';
	}
	if (min == 1 && max == 5) {
		UI[4][1] = '*';
		UI[3][2] = '*';
		UI[2][3] = '*';
		UI[1][4] = '*';
		UI[0][5] = '*';
	}
	if (min == 2 && max == 4) {
		UI[8][3] = '*';
		UI[7][4] = '*';
		UI[6][5] = '*';
		UI[5][6] = '*';
		UI[4][7] = '*';
	}
	if (min == 1 && max == 4) {
		UI[8][3] = '*';
		UI[7][4] = '*';
		UI[6][4] = '*';
		UI[5][4] = '*';
		UI[4][4] = '*';
		UI[3][4] = '*';
		UI[2][4] = '*';
		UI[1][5] = '*';
	}
	if (min == 0 && max == 3) {
		UI[8][5] = '*';
		UI[7][4] = '*';
		UI[6][4] = '*';
		UI[5][4] = '*';
		UI[4][4] = '*';
		UI[3][4] = '*';
		UI[2][4] = '*';
		UI[1][3] = '*';
	}
}
void Hexagon::show_state() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			std::cout << UI[i][j];
		}
		std::cout << std::endl;
	}
}