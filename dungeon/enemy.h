#include "Character.h"
#include <iostream>

class Enemy: public Character{
public:
	Enemy(std::string name);
	std::string getDescription();
private:
	std::string description;
};