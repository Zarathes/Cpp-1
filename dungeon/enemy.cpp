#include "stdafx.h"
#include "Enemy.h"

std::string Enemy::getDescription(){
	return Enemy::description;
}

void Enemy::showStatistics(){

}



void Enemy::SetCommand(TYPES::ACTION_LIST command){
	currentCommand = command;
}
void Enemy::Execute(){

}
