#include "room.h"
#include <iostream>
#include "ReadTextFile.h"

#include <vector>


class Generator{
public:
	Generator();
	bool createDungeon(int levels, int width, int height);
	Room* getStartRoom();
	void showMap();
private:
	std::vector<std::string> size;
	std::vector<std::string> roomType;
	std::vector<std::string> state;
	std::vector<std::string> furniture;
	std::vector<std::string> lightning;
	std::vector<std::string> enemies;
	std::vector<std::string> attackPointsEnemy;
	std::vector<std::string> lifePointsEnemy;

	int level;
	int mapLevel;
	int width;
	int height;
	Room* startRoom;
	ReadTextFile read;
	
	Room *rooms[1000][1000];
	std::string createDescription();
	std::vector<Enemy*> createEnemies();
	int connect(int currentLevel);
};