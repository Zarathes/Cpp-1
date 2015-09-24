#include <iostream>
#include <map>
#include <list>
#include "enemy.h"
#include "item.h"
#include "trap.h"

class room{
public:
	std::string getDescription();


private:
	std::string description;
	std::map<std::string, room> neighbors;
	std::list<enemy> enemies;
	std::list<item> items;
	Trap trap;
};