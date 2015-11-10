#include "stdafx.h"
#include "Trap.h"

#include <string>

using std::string;

Trap::Trap(string name, string description, int attackPower, int counterPerception)
	: name(name), description(description), attackPower(attackPower), counterPerceptionPoints(counterPerception)
{

}

string Trap::getName() {
	return name;
}

string Trap::getDescription() {
	return description;
}

int Trap::getPerceptionLevel() {
	return counterPerceptionPoints;
}

int Trap::getAttackPower() {
	std::cout << description << std::endl;
	return attackPower;
}