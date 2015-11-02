#ifndef __room__
#define __room__

#include <iostream>
#include <map>
<<<<<<< HEAD:dungeon/room.h
#include <vector>
=======
#include <list>

#include "Client.h"
#include "Reciever.h"

>>>>>>> refs/remotes/origin/StatePattern:dungeon/room.h
#include "Enemy.h"
#include "Item.h"
#include "Trap.h"
#include "Exits.cpp"

class Room : public Client, public Reciever {
public:
<<<<<<< HEAD:dungeon/room.h
	void setDescription(std::string newDescr);
	std::string getDescription();
	void setNeighbours(Exits exit, Room room);
	void setEnemies(std::vector<Enemy> newEnemies);
	void deleteEnemy(Enemy enemy);
	void setItems(std::vector<Item> newItems);
	Room getExit(Exits exit);
	int level;
	bool visited = true;
=======
	Room();

	std::string getDescription();
	void setNeighbours(Exits exit, Room room);

	std::map<int, std::pair<TYPES::ACTION_LIST, std::string>> getCommands();

	void ExecuteCommand(Room reciever, TYPES::ACTION_LIST command);

	void SetCommand(TYPES::ACTION_LIST command);
	void Execute();

	~Room();
>>>>>>> refs/remotes/origin/StatePattern:dungeon/room.h
private:
	std::string description;
	std::map<Exits, Room> neighbors;
	std::vector<Enemy> enemies;
	std::vector<Item> items;
	Trap trap;

	TYPES::ACTION_LIST currentCommand;
};


#endif
