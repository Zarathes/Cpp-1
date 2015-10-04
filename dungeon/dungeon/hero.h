#include <iostream>
#include <list>
#include "Character.h"
#include "Room.h"
#include "Item.h"
#include "Equipable.h"

class Hero: Character{
public:
	int getExperiancePoints();
	int getPerceptionPoints();
	std::list<Item> getInventory();
	std::list<Equipable> getEquipment();
	Room getCurrentRoom();

private:
	int experiancePoints;
	int perceptionPoints;
	std::list<Item> inventory;
	std::list<Equipable> equipment;
	Room currentRoom;
};