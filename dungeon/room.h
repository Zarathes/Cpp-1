#ifndef __room__
#define __room__

#include <iostream>
#include <map>
#include <vector>

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

	void setDescription(std::string newDescr);
	void printDescription();
	void enteringRoom();
	void setNeighbours(Exits exit, Room room);
	void setEnemies(std::vector<Enemy*> newEnemies);
	void deleteEnemy(Enemy enemy);
	void setItems(std::vector<Item> newItems);
	Room getExit(Exits exit);

	bool isVisited();

	std::map<int, std::pair<TYPES::ACTION_LIST, std::string>> getCommands();

	void SetCommand(TYPES::ACTION_LIST command);
	void Execute();

	~Room();

private:
	int level;
	bool visited = true;

	std::string description;
	std::map<Exits, Room> neighbors;
	std::vector<Enemy*> enemies;
	std::vector<Item> items;
	Trap trap;

	TYPES::ACTION_LIST currentCommand;
};


#endif
