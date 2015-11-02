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
