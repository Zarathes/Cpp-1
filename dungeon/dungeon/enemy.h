#include "Character.h"
#include <iostream>

class Enemy: public Character{
public:
	std::string getDescription();
private:
	std::string description;
};