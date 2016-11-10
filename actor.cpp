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
	memcpy(reg, myMap->reg, 26);
	printf("Actor created at %d %d %d on \"%c\"\n", x, y, z, myMap->get(pos));
}
void Actor::tick(){//executes, then moves.
	char c = myMap->get(pos);
	//execute
	if(isDir(c)){
		dir = c;
	}else if(isNum(c)){
		stck_pushVal(c-48);
	}else if(isReg(c)){
		stck_pushRef(c);
	}else if(isExec(c)){
		exec(c);
	}
	//move
	move();//FIXME moves happen regardless of whether or not a command changed the position.
	enforceBounds();
}
void Actor::exec(char c){
	int addition;
	value base;
	switch(c){
	case '+':
		addition = stck_popInt();
		base = stck_popVal();
		if(base.ref){//result written to base
			writeRef(base.reg, evalRef(base.reg)+addition);
		}else{//result written to stack
			stck_pushVal(base.val+addition);
		}
		break;
	case 'K':
		printf("killed %d\n", stck_popInt());
		break;
	default:
		puts("exec call failed");
	}
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
int Actor::stck_popInt(){
	value val = stack.back();
	int ret;
	if(val.ref){
		ret = evalRef(val.reg);
	}else{
		ret = val.val;
	}
	stack.pop_back();
	return ret;
}
bool Actor::stck_isRef(){
	return stack.back().reg;
}
value Actor::stck_popVal(){
	value ret = stack.back();
	stack.pop_back();
	return ret;
}
void Actor::writeRef(char ref, int val){
	if(ref >= 97 && ref <= 122){//a-z
		reg[ref-97] = val;
	}
	if(ref >= 88 && ref <= 90){//XYZ
		pos[ref-88] = val;
	}
}
int Actor::evalRef(char ref){
	if(ref >= 97 && ref <= 122){//a-z
		return reg[ref-97];
	}
	if(ref >= 88 && ref <= 90){//XYZ
		return pos[ref-88];
	}
	return 0;
}
void Actor::stck_pushVal(int v){
	value val;
	val.ref = false;
	val.val = v;
	stack.push_back(val);
}
void Actor::stck_pushRef(char r){
	value val;
	val.ref = true;
	val.reg = r;
	stack.push_back(val);
}
