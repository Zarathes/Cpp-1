#include "character.h"
#include <iostream>
#include <list>
#include "room.h"
#include "item.h"
#include "equipable.h"

class hero: character{
public:
	int getExperiancePoints();
	int getPerceptionPoints();
	std::list<item> getInventory();
	std::list<equipable> getEquipment();
	room getCurrentRoom();

private:
	int experiancePoints;
	int perceptionPoints;
	std::list<item> inventory;
	std::list<equipable> equipment;
	room currentRoom;
};