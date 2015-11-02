#include "stdafx.h"
#include "Hero.h"

int Hero::getExperiancePoints(){
	return Hero::experiancePoints;
}

int Hero::getPerceptionPoints(){
	return Hero::perceptionPoints;
}

std::list<Item> Hero::getInventory(){
	return Hero::inventory;
}

std::list<Equipable> Hero::getEquipment(){
	return Hero::equipment;
}

Room Hero::getCurrentRoom(){
	return Hero::currentRoom;
}