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
	int tick();
	Map* myMap;
private:
	Stack* mem;
	int exec(char c);
	void move();
	void enforceBounds();
};
#endif
