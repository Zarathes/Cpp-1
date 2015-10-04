#include <iostream>
#include <map>
#include <list>
#include "Enemy.h"
#include "Item.h"
#include "Trap.h"

class Room{
public:
	std::string getDescription();


private:
	std::string description;
	std::map<std::string, Room> neighbors;
	std::list<Enemy> enemies;
	std::list<Item> items;
	Trap trap;
};