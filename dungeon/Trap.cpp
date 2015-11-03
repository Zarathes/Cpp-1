#include "stdafx.h"
#include "trap.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

Trap::Trap(){

}

Trap::Trap(string name) 
	:name(name)
{
}

string Trap::getName(){
	return name;
}

int Trap::attack(){
//	cout << name << "" << endl;
	return attackPower;
}

int Trap::getPerception(){
	return 5;
}