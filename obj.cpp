#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "obj.h"
Obj::Obj(Stack* myStack, int value){
	isRef = false;
	this->myStack = myStack;
	this->value = value;
}
Obj::Obj(Stack* myStack, char reg){
	isRef = true;
	this->myStack = myStack;
	this->reg = reg;
}
void Obj::write(int val){
	if(isRef){
		*ptrFromRef(reg) = val;
	}else{
		value = val;
	}
}
int Obj::read(){
	if(isRef){
		return *ptrFromRef(reg);
	}else{
		return value;
	}
}
int* Obj::ptrFromRef(char ref){
	if(ref >= 97 && ref <= 122){//a-z
		return &(myStack->reg[ref-97]);
	}else if(ref >= 88 && ref <= 90){//XYZ
		return &(myStack->myActor->pos[ref-88]);
	}else{
		printf("Could not evaluate reference \'%c\'\n", ref);
		return NULL;
	}
}
