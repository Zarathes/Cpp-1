#ifndef __game__
#define __game__
#include <iostream>
#include <map>

#include "Room.h"
class Game
{
public:
	Game();
	~Game();
private:
	bool running;
<<<<<<< HEAD:dungeon/Game.h
	std::map<int, std::string> actions;
	
	void start();
=======

	Room *currentRoom;

	std::map<int , std::pair<TYPES::ACTION_LIST, std::string>> commands;
>>>>>>> refs/remotes/origin/StatePattern:dungeon/Game.h

	void printActions();
	std::string readAction();

	void handelAction(std::string action);
};

#endif
