#include "stdafx.h"
#include "Character.h"

using std::cout;
using std::endl;

using std::string;


Character::Character(string n)
	: name(n)
{
}

Character::Character(string n, int attackPower, int lifePoints)
: name(n), attackPower(attackPower), lifePoints(lifePoints)
{
}

int Character::getLifePoints(){
	return Character::lifePoints;
}