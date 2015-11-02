#include "Character.h"
#include <iostream>

class Enemy: public Character{
public:
	std::string getDescription();
	void showStatistics();


	void SetCommand(TYPES::ACTION_LIST command);
	void Execute();
private:
	std::string description;
};