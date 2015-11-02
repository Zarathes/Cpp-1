#include "stdafx.h"
#include "Enemy.h"

using std::string;

Enemy::Enemy(string name) 
	: Character(name)
{

}

string Enemy::getDescription(){
	return Enemy::description;
}

void Enemy::showStatistics(){

}



void Enemy::SetCommand(TYPES::ACTION_LIST command){
	currentCommand = command;
}
void Enemy::Execute(){

}
