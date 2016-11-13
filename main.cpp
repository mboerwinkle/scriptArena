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
	Actor *me = new Actor(&newMap, 0, 0, 0);
	while(!me->tick()){
//		printf("%d %d STCK:%d\n", me->pos[0], me->pos[1], me->mem->len());
//		getchar();
	}
}
