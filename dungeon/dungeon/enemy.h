#include "character.h"
#include <iostream>

class enemy: public character{
public:
	std::string getDescription();
private:
	std::string description;
};