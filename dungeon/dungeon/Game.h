#pragma once
#include <iostream>
#include <map>

class Game
{
public:
	Game();
	~Game();
private:
	bool running;
	std::map<int, std::string> actions;
	
	void start();

	void printActions();
	std::string readAction();

	void handelAction(std::string action);
};

