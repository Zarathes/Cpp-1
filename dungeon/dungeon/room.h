#ifndef __room__
#define __room__

#include <iostream>
#include <map>
#include <list>

#include "Client.h"
#include "Reciever.h"

#include "Enemy.h"
#include "Item.h"
#include "Trap.h"
#include "Exits.cpp"

class Room : public Client, public Reciever {
public:
	Room();

	std::string getDescription();
	void setNeighbours(Exits exit, Room room);

	std::map<int, std::pair<TYPES::ACTION_LIST, std::string>> getCommands();

	void ExecuteCommand(Room reciever, TYPES::ACTION_LIST command);

	void SetCommand(TYPES::ACTION_LIST command);
	void Execute();

	~Room();
private:
	std::string description;
	std::map<Exits, Room> neighbors;
	std::list<Enemy> enemies;
	std::list<Item> items;
	Trap trap;

	TYPES::ACTION_LIST currentCommand;
};


#endif
