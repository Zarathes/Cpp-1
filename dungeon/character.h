#ifndef __character__
#define __character__

#include <iostream>
#include <string>

class Character{

public:
	Character(std::string name);
	int getLifePoints();
	
protected:
	std::string name;
	int level;
	int lifePoints;
	int attackPower;
	int defencePower;

private: 
	
};

#endif