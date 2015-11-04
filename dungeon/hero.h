#ifndef __hero__
#define __hero__

#include "character.h"
#include "room.h"
#include <vector>
#include <stack>
#include "Talisman.h"
#include "Granate.h"
#include "ZilverenCompass.h"

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
	void setDungeon(std::vector< std::vector< std::vector<Room> > > newDungeon);
private:
	int experiancePoints;
	int perceptionPoints;
	int level;
	std::vector< std::vector< std::vector<Room> > > dungeon;

	void useCompass();
	void useGranate();
	void useTalisman();
	void checkLevel();
	std::vector<Consumable*> consumable;
	std::vector<Equipable*> equipment;
	std::stack<Room*> rooms;
	void fight();

	int currentLevel;

	ZilverenCompass compass;
	Granate granate;
	Talisman talisman;
	void getItems();
	Room *currentRoom;
};

#endif