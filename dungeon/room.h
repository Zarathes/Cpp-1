#ifndef __room__
#define __room__

#include <iostream>
#include <map>
#include <vector>

#include <list>

#include "Client.h"
#include "Reciever.h"

#include "Enemy.h"
#include "Consumable.h"
#include "Equipable.h"
#include "Trap.h"
#include "Exits.cpp"

class Room : public Client, public Reciever {
public:	
	Room();

	void setDescription(std::string newDescr);
	void printDescription();
	void enteringRoom();
	void setNeighbours(Exits exit, std::pair<std::string, Room*> room);
	void setEnemies(std::vector<Enemy*> newEnemies);
	void deleteEnemy(Enemy enemy);
	int getDepth();
	void setDepth(int d);
	void setEquipableItems(std::vector<Equipable*> newItems);
	void setConsumableItems(std::vector<Consumable*> newItems);
	std::vector<Equipable*> getEquipableItems();
	std::vector<Consumable*> getConsumableItems();
	Room* getNeighbour(Exits exit);
	std::map<Exits, std::pair<std::string, Room*>> getNeighbours();

	int fight();
	int attackEnemies(int attackPoints);

	bool isVisited();

	std::map<int, std::pair<TYPES::ACTION_LIST, std::string>> getCommands();

	void SetCommand(TYPES::ACTION_LIST command);
	void Execute();

	~Room();

private:
	int level;
	bool visited = true;

	int depth;
	std::string description;
	std::map<Exits, std::pair<std::string, Room*>> neighbors;
	std::vector<Enemy*> enemies;
	std::vector<Equipable*> equipableItems;
	std::vector<Consumable*> consumableItems;
	Trap trap;

	TYPES::ACTION_LIST currentCommand;
};


#endif
