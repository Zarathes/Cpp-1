#ifndef __hero__
#define __hero__


#include <iostream>
#include <vector>
#include "Character.h"
#include "Room.h"
#include "Equipable.h"
#include "Consumable.h"

class Hero: public Character{
public:
	Hero();

	Room getCurrentRoom();
	void showStatistics();
	void showBag();

	void SetCommand(TYPES::ACTION_LIST command);
	void Execute();
private:
	int experiancePoints;
	int perceptionPoints;
	std::vector<Consumable> consumable;
	std::vector<Equipable> equipment;
	Room currentRoom;
};

#endif