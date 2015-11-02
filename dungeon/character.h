#ifndef __character__
#define __character__

#include <iostream>

class Character{

public:
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