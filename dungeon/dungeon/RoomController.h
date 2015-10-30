#include "room.h"
#include <iostream>
#include "ReadTextFile.h"

#include <vector>


class RoomController{
public:
	RoomController();
	bool createDungeon(const int newLevel, const int newWidth);
	void showMap();
	void cheatMap();
private:
	std::vector<std::string> state;
	std::vector<std::string> furniture;
	std::vector<std::string> lightning;
	std::vector<std::string> size;
	int level;
	int mapLevel;
	int width;
	Room* startRoom;
	ReadTextFile read;

	Room *rooms[1000][1000];
	std::string createDescription();
	int connect(int currentLevel);
};