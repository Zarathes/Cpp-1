#include "room.h"
#include <iostream>
#include "ReadTextFile.h"

#include <vector>


class Generator{
public:
	Generator(int d, int w, int h);
	bool createDungeon();
	Room* getStartRoom();
private:
	std::vector<std::string> size;
	std::vector<std::string> roomType;
	std::vector<std::string> state;
	std::vector<std::string> furniture;
	std::vector<std::string> lightning;
	std::vector<std::string> enemies;

	int mapLevel;

	int depth;
	int width;
	int height;

	Room* startRoom;
	ReadTextFile read;
	
	std::vector< std::vector< std::vector<Room> > > dungeon;
	std::string createDescription();
	std::vector<Enemy*> createEnemies();
	std::vector<Exits> createExit(int width, int height);
};