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
	void tick();
	void stck_pushVal(int v);
	void stck_pushRef(char r);
	void writeRef(char ref, int val);
	int evalRef(char ref);
	value stck_popVal();
	bool stck_isRef();
	int stck_popInt();
	
	
	void exec(char c);
	void move();
	void enforceBounds();
	int reg[26];
	std::vector<value> stack;
	Map* myMap;
private:
};
#endif
