#ifndef __trap__
#define __trap__

#include <iostream>

class Trap {
public:
	std::string getName();
	std::string getDescription();
private:
	std::string name;
	std::string description;
	int attackPower;
	int counterPerceptionPoints;
	//Trigger trigger;
};

#endif