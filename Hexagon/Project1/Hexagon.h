#pragma once
#ifndef HEXAGON
#define HEXAGON

class Hexagon {

private:
	int graph[6][6];
public:
	Hexagon();
	void add_edge(int i, int j);
	void show_state();
};
#endif 

