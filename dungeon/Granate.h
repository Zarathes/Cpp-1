#ifndef __Granate__
#define __Granate__

#include <iostream>
#include <vector>
#include <string>
#include "room.h"

class Granate {
public:
	std::string getName();
	void use(Room* currentRoom);
	void setDungeon(std::vector< std::vector< std::vector<Room> > > newDungeon);
private:
	std::vector< std::vector< std::vector<Room> > > dungeon;
};

#endif