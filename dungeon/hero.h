#ifndef __hero__
#define __hero__


#include <iostream>
#include <list>
#include "Character.h"
#include "Room.h"
#include "Item.h"
#include "Equipable.h"

class Hero: public Character{
public:
	int getExperiancePoints();
	int getPerceptionPoints();
	std::list<Item> getInventory();
	std::list<Equipable> getEquipment();
	Room getCurrentRoom();
	void showStatistics();
	void showBag();

	void SetCommand(TYPES::ACTION_LIST command);
	void Execute();
private:
	int experiancePoints;
	int perceptionPoints;
	std::list<Item> inventory;
	std::list<Equipable> equipment;
	Room currentRoom;
};

#endif