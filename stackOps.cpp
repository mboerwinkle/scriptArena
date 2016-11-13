#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stack.h"
void Stack::add(){
	int one = pop().read();
	Obj two = pop();
	two.write(two.read()+one);
	push(two);
}
void Stack::subtract(){
	int one = pop().read();
	Obj two = pop();
	two.write(two.read()-one);
	push(two);
}
void Stack::multiply(){
	int one = pop().read();
	Obj two = pop();
	two.write(two.read()*one);
	push(two);
}
void Stack::divide(){
	int one = pop().read();
	Obj two = pop();
	if(one == 0){
		puts("Cancelled operation of divide by 0");
		push(two);
		return;
	}
	two.write(two.read()/one);
	push(two);
}
void Stack::modulo(){
	int one = pop().read();
	Obj two = pop();
	if(one == 0){
		puts("Cancelled operation of modulo by 0");
		push(two);
		return;
	}
	two.write(two.read()%one);
	push(two);
}
void Stack::power(){
	int one = pop().read();
	Obj two = pop();
	two.write(pow(two.read(),one));
	push(two);
}
void Stack::increment(){
	Obj one = pop();
	one.write(one.read()+1);
	push(one);
}
void Stack::equals(){
	Obj one = pop();
	one.write(pop().read());
	push(one);
}
void Stack::andOp(){
	int one = pop().read();
	Obj two = pop();
	two.write(two.read()&one);
	push(two);
}
void Stack::xorOp(){
	int one = pop().read();
	Obj two = pop();
	two.write(two.read()^one);
	push(two);
}
void Stack::orOp(){
	int one = pop().read();
	Obj two = pop();
	two.write(two.read()|one);
	push(two);
}
bool Stack::testEqual(){
	return pop().read() == pop().read();
}
