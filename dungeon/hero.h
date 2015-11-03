#ifndef __hero__
#define __hero__

#include "character.h"
#include "room.h"
#include <vector>
#include <stack>

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
	std::vector<Consumable*> consumable;
	std::vector<Equipable*> equipment;
	std::stack<Room*> rooms;
	void fight();

	void getItems();
	Room *currentRoom;
};

#endif