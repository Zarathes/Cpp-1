#include "stdafx.h"
#include "Room.h"

void Room::setDescription(std::string newDescr){
	description = newDescr;
}

std::string Room::getDescription(){
	return description;
}

void Room::setNeighbours(Exits exit, Room room){
	neighbors[exit] = room;
}

void Room::addEnemy(Enemy enemy){
	enemies.push_back(enemy);
}

void Room::deleteEnemy(Enemy enemy){
	//enemies.erase(std::remove(enemies.begin(), enemies.end(), enemy), enemies.end());
}

void Room::addItem(Item item){
	items.push_back(item);
}