#include <iostream>
#include "Hexagon.h"

Hexagon::Hexagon() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			graph[i][j] = -1;
		}
	}
}
void Hexagon::add_edge(int i, int j){
	graph[i][j] = 0;
	graph[j][i] = 0;
}
void Hexagon::show_state() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			std::cout << graph[i][j]<<" ";
		}
		std::cout << std::endl;
	}
}