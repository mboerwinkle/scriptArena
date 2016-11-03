#ifndef ACTOR_H
#define ACTOR_H
#include "value.h"
class Actor{
public:
	int pos[3];
	Actor(Map* myMap, int x, int y, int z);
	int reg[26];
	std::vector[value] stack = {};
private:
};
#endif
