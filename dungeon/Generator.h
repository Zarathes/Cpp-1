#include "room.h"
#include <iostream>
#include "ReadTextFile.h"

#include <vector>


class Generator{
public:
	Generator();
	bool createDungeon(int levels, int roomsPerLevel);
	Room* getStartRoom();
	void showMap();
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
	
	std::vector<Room>* makeRow();
	Room *rooms[1000][1000];
	std::string createDescription();
	int connect(int currentLevel);

	void subset_sum(std::list<int> numbers, int target);
	void subset_sum_recursive(std::list<int> numbers, int target, std::list<int> partial);
};