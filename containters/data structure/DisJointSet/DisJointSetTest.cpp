#include<iostream>
#include"Maze.hpp"
using namespace std;

int main(){
	Maze m(5,5,1,1,5,5);
	m.createMaze();
	m.show();
	
	return 0;
}
