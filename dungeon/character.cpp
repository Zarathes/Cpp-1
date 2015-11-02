#include "stdafx.h"
#include "Character.h"

using std::cout;
using std::endl;

using std::string;


Character::Character(string n)
	: name(n)
{
}

int Character::getLifePoints(){
	return Character::lifePoints;
}