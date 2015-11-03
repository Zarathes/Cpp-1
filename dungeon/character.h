#ifndef __character__
#define __character__

#include <iostream>
#include <string>

#include "Client.h"
#include "Reciever.h"
#include <iostream>
#include <map>

class Character: public Client, public Reciever
{

public:
	Character(std::string name);
	Character(std::string name, int attackPoints, int lifePoints);
	int getLifePoints();
	void showStatistics();
	void underAttack(int points);
	bool living();
//	std::map<int, std::pair<TYPES::ACTION_LIST, std::string>> getCommands();

//	void SetCommand(TYPES::ACTION_LIST command);
//	void Execute();

protected:
	std::string name;
	int level;
	int lifePoints;
	int attackPower;
	int defencePower;
	TYPES::ACTION_LIST currentCommand;
	bool alive = true;
	
};

#endif