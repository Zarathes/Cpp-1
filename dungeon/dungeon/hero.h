#include "character.h";
#include <iostream>

class hero: character{
public:
	int getExperiancePoints();
	int getPerceptionPoints();
	list<item> getInventory();
	room getCurrentRoom();

private:
	int experiancePoints;
	int perceptionPoints;
	list<item> inventory;
	list<equipable> equipment;
	room currentRoom;
};