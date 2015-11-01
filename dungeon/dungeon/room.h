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
	void setEnemies(std::vector<Enemy> newEnemies);
	void deleteEnemy(Enemy enemy);
	void setItems(std::vector<Item> newItems);
	Room getExit(Exits exit);
	int level;
	bool visited = true;
private:
	std::string description;
	std::map<Exits, Room> neighbors;
	std::vector<Enemy> enemies;
	std::vector<Item> items;
	Trap trap;
};


#endif
