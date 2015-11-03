#include "Character.h"
#include <iostream>

class Enemy: public Character{
public:
	Enemy(std::string description, int attackPoints, int lifePoints);
	std::string getDescription();
	std::string getName();
	void showStatistics();
	void underAttack(int points);
	bool living();
	int attack();

	void SetCommand(TYPES::ACTION_LIST command);
	void Execute();
private:
	std::string description;
	int lifePoints;
};