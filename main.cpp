#include <stdio.h>
#include <stdlib.h>
#include "actor.h"
#include "map.h"

int main(int argc, char** argv){
	printf("%d\n", argc);
	if(argc < 2){
		printf("What map file to open?\n");
		return 1;
	}
	Map newMap(argv[1]);
	newMap.printLayer(0);
	Actor me(&newMap, 0, 0, 0);
	while(true){
		getchar();
		me.tick();
	}
}