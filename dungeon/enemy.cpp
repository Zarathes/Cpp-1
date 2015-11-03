#include "stdafx.h"
#include "Enemy.h"
using std::cout;
using std::cin;
using std::endl;

using std::string;

Enemy::Enemy(string name, int attackPoints, int lifePoints) 
	: Character(name, attackPoints, lifePoints)
{

}

string Enemy::getName(){
	return name;
}

string Enemy::getDescription(){
	return Enemy::description;
}

void Enemy::showStatistics(){
	cout << name << " statistics " << endl;
	cout << "Life points: " << lifePoints << endl;
	cout << "" << endl;
}

int Enemy::attack(){
	return attackPower;
}

void Enemy::SetCommand(TYPES::ACTION_LIST command){
	currentCommand = command;
}
void Enemy::Execute(){

}
