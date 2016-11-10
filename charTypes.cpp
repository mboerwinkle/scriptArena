#include <stdlib.h>
#include <stdio.h>
#include "charTypes.h"

bool isDir(char i){
	if(i == 'A'||i == 'V'||i == '<'||i == '>'||i == 'U'||i == 'D') return true;
	return false;
}
bool isNum(char i){
	if(i >= '0' && i <= '9') return true;
	return false;
}
bool isReg(char i){
	if((i >= 'a' && i <= 'z')||(i >= 'X' && i <= 'Z')) return true;
	return false;
}
bool isExec(char i){
	if(i == '+' || i == '-' || i == '/' || i == '*' || i == '%' || i == 'P' || i == '=' || i == 'I'
	|| i == 'S' || i == 'T'
	|| i == '&' || i == '|' || i == '^'
	|| i == 'G' || i == 'L' || i == 'E' || i == 'C' || i == ':'
	|| i == 'K'
	|| i == 'O') return true;
	return false;
}
