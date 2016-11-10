#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

Map::Map(char* filename){
	FILE* fp = fopen(filename, "r");
	dat = (char*)calloc(LEN*LEN*LEN, sizeof(char));
	memset(dat, 0, LEN*LEN*LEN);
	for(int x = 0; x < 26; x++){
		fscanf(fp, "%d\n", &(reg[x]));
	}
	char input[LEN+3];
	for(int z = 0; z < LEN; z++){
		printf("loading level %d\n", z);
		for(int y = 0; y < LEN; y++){
			if(fgets(input, LEN+2, fp)){
				if(strcmp("@\n", input) == 0){
					break;
				}
				if(strcmp("@@@\n", input) == 0){
					return;
				}
				strncpy(xptr(y, z), input, strlen(input)-1);
			}else break;
		}
	}
}
char Map::get(int x, int y, int z){
	return dat[LEN*LEN*z+LEN*y+x];
}
char Map::get(int* c){
	return dat[LEN*LEN*c[2]+LEN*c[1]+c[0]];
}
void Map::printLayer(int layer){
	printf("Begin layer %d\n", layer);
	char out[LEN+1];
	for(int y = 0; y<LEN; y++){
		strncpy(out, xptr(y, layer), LEN);
		out[LEN] = 0;
		if(strlen(out)!=0){
			printf("%s\n", out);
		}
	}
	printf("End layer %d\n", layer);
}
char* Map::xptr(int y, int z){
	return dat+(LEN*LEN*z+LEN*y);
}
