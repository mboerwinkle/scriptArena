#ifndef OBJ_H
#define OBJ_H
#include "stack.h"
class Stack;
class Obj{
public:
	Obj(Stack* myStack, int val);
	Obj(Stack* myStack, char reg);
	void write(int val);
	int read();
private:
	int* ptrFromRef(char ref);
	Stack* myStack;
	bool isRef;
	char reg;
	int value;
};
#endif
