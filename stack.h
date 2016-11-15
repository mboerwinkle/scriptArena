#ifndef STACK_H
#define STACK_H
#include <vector>
#include "obj.h"
#include "actor.h"
class Actor;
class Obj;
class Stack{
public:
	Stack(Actor* myActor);
	int reg[26];
	void push(Obj in);
	void push(char reg);
	void push(int val);
	int len();
	Obj pop();
	Obj read(int idx);
	Actor* myActor;

	//operations
	void add();
	void subtract();
	void multiply();
	void divide();
	void modulo();
	void power();
	void increment();
	void equals();
	void andOp();
	void xorOp();
	void orOp();
	void stdinput();
	void teleport();
	void skip();

	//tests (turn left or right)
	bool testIf();
	int testCompare();
	bool testGreater();
	bool testLess();
	bool testEqual();
private:
	std::vector<Obj> data;
};
#endif
