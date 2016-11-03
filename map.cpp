#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

Map::Map(Map& clone){
	memcpy(this.dat, clone.dat, LEN*LEN*LEN);
}
Map::Map(char* filename){
	FILE* fp = fopen(filename, "r");
	memset(dat, 0, LEN*LEN*LEN);
	for(int x = 0; x < 26; x++){
		scanf(fp, "%d", reg[x]);
	}
	char input[LEN+3];
	for(int z = 0; z < LEN; z++){
		for(int y = 0; y < LEN; y++){
			if(fgets(input, LEN+2, fp)){
				memcpy(xptr(y, z), input, strlen(input)-1);
			}else break;
		}
	}
}
