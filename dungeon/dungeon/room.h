#ifndef __room__
#define __room__

#include <iostream>
#include <map>
#include <vector>
#include "Enemy.h"
#include "Item.h"
#include "Trap.h"
#include "Exits.cpp"

class Room{
public:
	void setDescription(std::string newDescr);
	std::string getDescription();
	void setNeighbours(Exits exit, Room room);
	void addEnemy(Enemy enemy);
	void deleteEnemy(Enemy enemy);
	void addItem(Item item);
private:
	std::string description;
	std::map<Exits, Room> neighbors;
	std::vector<Enemy> enemies;
	std::vector<Item> items;
	Trap trap;
};


#endif
