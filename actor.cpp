#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"
#include "actor.h"
#include "charTypes.h"
Actor::Actor(Map* myMap, int x, int y, int z){
	pos[0] = x;
	pos[1] = y;
	pos[2] = z;
	this->myMap = myMap;
	mem = new Stack(this);
	printf("Actor created at %d %d %d on \"%c\"\n", x, y, z, myMap->get(pos));
}
void Actor::tick(){//executes, then moves.
	char c = myMap->get(pos);
	//execute
	if(isDir(c)){
		dir = c;
	}else if(isNum(c)){
		mem->push((int)(c-48));
	}else if(isReg(c)){
		mem->push(c);
	}else if(isExec(c)){
		exec(c);
	}
	//move
	move();//FIXME moves happen regardless of whether or not a command changed the position.
	enforceBounds();
}
void Actor::exec(char c){
	switch(c){
	case '+':
		add();
		break;
	case 'K':
		printf("killed %d\n", mem->pop().read());
		break;
	default:
		puts("exec call failed");
	}
}
void Actor::add(){
		int one = mem->pop().read();
		Obj two = mem->pop();
		two.write(two.read()+one);
		mem->push(two);	
}
void Actor::move(){
	switch(dir){
	case 'A':
		pos[1]--;
		break;
	case 'V':
		pos[1]++;
		break;
	case '<':
		pos[0]--;
		break;
	case '>':
		pos[0]++;
		break;
	case 'U':
		pos[2]--;
		break;
	case 'D':
		pos[2]++;
		break;
	default:
		printf("Failed movement direction \"%c\"\n", dir);
	}
}
void Actor::enforceBounds(){
	for(int temp = 0; temp < 3; temp++){
		while(pos[temp] < 0){//we have such safe out-of-bounds handling here in case of bad teleports or skips.
			pos[temp]+=LEN;
		}
		while(pos[temp] >= LEN){
			pos[temp]-=LEN;
		}
	}
}
