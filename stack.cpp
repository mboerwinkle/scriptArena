#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
Stack::Stack(Actor* myActor){
	memcpy(reg, myActor->myMap->reg, 26);
}
void Stack::push(Obj in){
	data.push_back(in);
}
void Stack::push(char reg){
	data.push_back(Obj(this, reg));
}
void Stack::push(int val){
	data.push_back(Obj(this, val));
}
Obj Stack::pop(){
	Obj ret = data.back();
	data.pop_back();
	return ret;
}
Obj Stack::read(int idx){
	return data[data.size()-1-idx];
}
