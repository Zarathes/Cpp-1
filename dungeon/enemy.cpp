#include "stdafx.h"
#include "Enemy.h"

using std::string;

Enemy::Enemy(string description) 
	: Character(description)
{

}

string Enemy::getName(){
	return name;
}

string Enemy::getDescription(){
	return Enemy::description;
}

void Enemy::showStatistics(){

}

int Enemy::attack(){

}

void Enemy::SetCommand(TYPES::ACTION_LIST command){
	currentCommand = command;
}
void Enemy::Execute(){

}
