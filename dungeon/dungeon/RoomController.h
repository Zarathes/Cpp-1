#include "room.h"
#include <iostream>


class RoomController{
public:
	bool createDungeon(const int level, const int width);
	void showMap();
	void cheatMap();
private:
	Room rooms[1000][1000];

	std::string createDescription();
	void connect(int level);
};