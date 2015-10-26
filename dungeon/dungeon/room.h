#ifndef __room__
#define __room__

#include <iostream>
#include <map>
#include <list>
#include "Enemy.h"
#include "Item.h"
#include "Trap.h"
#include "Exits.cpp"

class Room{
public:
	std::string getDescription();
	void setNeighbours(Exits exit, Room room);
	void addEnemy(Enemy enemy);
	void addItem(Item item);
private:
	std::string description;
	std::map<Exits, Room> neighbors;
	std::list<Enemy> enemies;
	std::list<Item> items;
	Trap trap;
};


#endif
