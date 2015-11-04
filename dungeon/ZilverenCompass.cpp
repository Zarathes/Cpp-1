#include "stdafx.h"
#include "ZilverenCompass.h"
using std::cout;
using std::cin;
using std::endl;


std::string ZilverenCompass::getName(){
	return "Zilveren Compass";
}

void ZilverenCompass::setDungeon(std::vector< std::vector< std::vector<Room> > > newDungeon){
	dungeon = newDungeon;
}

void ZilverenCompass::use(Room* currentRoom){
	//hoeveel kamers is de trap omhoog
	int steps = -1;
	int enemies = 0;
	std::vector<Room*> visited;
	std::vector<Room*> route;
	Room* current = currentRoom;

	route.push_back(currentRoom);
	bool foundUp = false;

	while (!route.empty() && !foundUp){
		steps++;
		Room* room = route.back();
		route.pop_back();

		visited.push_back(room);
		for (auto const& a : room->getNeighbours())
		{
			if (a.first == Exits::UP){
				foundUp = true;
				break;
			}
			else if (std::find(visited.begin(), visited.end(), a.second.second) == visited.end() && std::find(route.begin(), route.end(), a.second.second) == route.end()){
				route.push_back(a.second.second);
			}
		}
	}
	//voor elke kamer op niveu level van kamer
	cout << "The stairs up are " << steps << " steps away" << endl;
}