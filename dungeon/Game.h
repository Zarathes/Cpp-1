#ifndef __game__
#define __game__
#include <iostream>
#include <map>

#include "Room.h"
#include "hero.h"

class Game
{
public:
	Game();
	~Game();
private:
	bool running;

	int inputNumber(std::string question);
	
	bool generateDungeon();
	void start();

	Hero *hero;

	std::map<int , std::pair<TYPES::ACTION_LIST, std::string>> commands;
	void printCommands();
	void handelCommand();
};

#endif
