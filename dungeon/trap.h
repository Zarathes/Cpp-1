#ifndef __trap__
#define __trap__

#include <iostream>

class Trap {
public:
	Trap(std::string name, std::string descr, int attackPower, int counterPerception);
	std::string getName();
	std::string getDescription();
	int getPerceptionLevel();
	int getAttackPower();
private:
	std::string name;
	std::string description;
	int attackPower;
	int counterPerceptionPoints;
	//Trigger trigger;
};

#endif