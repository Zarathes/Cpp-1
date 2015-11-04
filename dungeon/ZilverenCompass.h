#ifndef __compass__
#define __compass__

#include <iostream>
#include <vector>
#include <string>
#include "room.h"

class ZilverenCompass{
public:
	std::string getName();
	void use(Room* currentRoom);
	void setDungeon(std::vector< std::vector< std::vector<Room> > > newDungeon);
private:
	std::vector< std::vector< std::vector<Room> > > dungeon;
};

#endif