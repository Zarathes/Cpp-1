#ifndef __trap__
#define __trap__

#include <iostream>

class Trap {
public:
	Trap();
	Trap(std::string name);
	std::string getName();
	std::string getDescription();
	int attack();
	int getPerception();
private:
	std::string name;
	std::string description;
	int attackPower;
	int counterPerceptionPoints;
};

#endif