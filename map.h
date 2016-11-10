#ifndef MAP_H
#define MAP_H
#define LEN 256
class Map{
public:
	Map(char* filename);
	int reg[26];
	char* dat;
	char* xptr(int y, int z);
	char get(int x, int y, int z);
	char get(int* c);
	void printLayer(int layer);
private:
};
#endif
