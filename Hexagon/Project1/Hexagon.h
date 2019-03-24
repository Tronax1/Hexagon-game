#pragma once
#ifndef HEXAGON
#define HEXAGON

struct vertex {
	int position_x;
	int position_y;
};
class Hexagon {
	
private:
	int graph[6][6];
	char UI[9][9];
	vertex table[6];
public:
	Hexagon();
	bool game_over();
	void add_edge(int i, int j);
	void modify_state(int i, int j);
	void show_state();
};
#endif 

