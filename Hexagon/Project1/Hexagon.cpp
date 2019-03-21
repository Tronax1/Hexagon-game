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
	int min = std::min(i, j);
	int max = std::max(i, j);
	if (table[i].position_x == table[j].position_x) {
		for (int k = table[min].position_y + 1; k < table[max].position_y; k++) {
			UI[table[min].position_x][k] = '-';
		}
	}
	if (table[i].position_y == table[j].position_y) {
		for (int k = table[min].position_x + 1; k < table[max].position_x; k++) {
			UI[k][table[min].position_y] = '|';
		}
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