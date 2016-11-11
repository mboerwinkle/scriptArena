#ifndef ACTOR_H
#define ACTOR_H
#include "map.h"
#include "stack.h"
class Stack;
class Actor{
public:
	Actor(Map* myMap, int x, int y, int z);
	int pos[3];
	char dir = '>';
	void tick();
	Map* myMap;
private:
	Stack* mem;
	void exec(char c);
	void move();
	void enforceBounds();

	void add();
};
#endif
