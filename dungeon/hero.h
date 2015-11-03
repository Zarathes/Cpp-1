#ifndef __hero__
#define __hero__


#include <iostream>
#include <vector>
#include <stack>
#include "Character.h"
#include "Room.h"

class Hero: public Character{
public:
	Hero();
	
	void handelRoomChange();
	void insertCurrentRoom(Room *room);
	Room* getCurrentRoom();
	void showStatistics();
	void showBag();
	void underAttack(int points);
	void run();
	bool living();
	void SetCommand(TYPES::ACTION_LIST command);
	void Execute();
private:
	int experiancePoints;
	int perceptionPoints;
	bool alive;
	std::vector<Consumable*> consumable;
	std::vector<Equipable*> equipment;
	std::stack<Room*> rooms;

	int currentLevel;

	void getItems();
	Room *currentRoom;
};

#endif