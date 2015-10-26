#include "stdafx.h"
#include "Room.h"

std::string Room::getDescription(){
	return description;
}

void Room::setNeighbours(Exits exit, Room room){
	neighbors[exit] = room;
}