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

Room Room::getExit(Exits exit){
	return neighbors[exit];
}

void Room::setEnemies(std::vector<Enemy> newEnemies){
	enemies = newEnemies;
}

void Room::deleteEnemy(Enemy enemy){
	//enemies.erase(std::remove(enemies.begin(), enemies.end(), enemy), enemies.end());
}

void Room::setItems(std::vector<Item> newItems){
	items = newItems;
}