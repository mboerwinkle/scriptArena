#ifndef ACTOR_H
#define ACTOR_H
#include <vector>
#include "map.h"
#include "value.h"
class Actor{
public:
	int pos[3];
	char dir = '>';
	Actor(Map* myMap, int x, int y, int z);
	int reg[26];
	std::vector<value> stack;
	Map* myMap;
private:
};
#endif
