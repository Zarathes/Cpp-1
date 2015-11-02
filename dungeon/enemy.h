#include "Character.h"
#include <iostream>

class Enemy: public Character{
public:
	Enemy(std::string name);
	std::string getDescription();
	std::string getName();
	void showStatistics();
	int attack();

	void SetCommand(TYPES::ACTION_LIST command);
	void Execute();
private:
	std::string description;
	int lifePoints;
};