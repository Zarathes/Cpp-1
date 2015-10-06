#include "stdafx.h"
#include "Room.h"

using namespace std;

std::string Room::getDescription(){
	return Room::description;
}

void Room::setNeighbours(Exits exit, Room room){
	//neighbors.insert(exit, room);
}