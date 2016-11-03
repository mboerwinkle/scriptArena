#ifndef MAP_H
#define MAP_H
#define LEN 256
class Map{
public:
	Map(Map clone);
	Map(char* filename);
	char dat[LEN*LEN*LEN];
	char* xptr(int y, int z);
private:
};
#endif
