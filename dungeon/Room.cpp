#include "stdafx.h"
#include "Room.h"

#include "State.h"
#include "UnvisitedRoomState.h"

using namespace std;

Room::Room() {
	currentState = new UnvisitedRoomState();
}

void Room::setDescription(std::string newDescr) {
	description = newDescr;
}

void Room::setNeighbours(Exits exit, Room room) {
	neighbors[exit] = room;
}

void Room::setEnemies(std::vector<Enemy> newEnemies) {
	enemies = newEnemies;
}

void Room::deleteEnemy(Enemy enemy) {
	//enemies.erase(std::remove(enemies.begin(), enemies.end(), enemy), enemies.end());
}

void Room::setItems(std::vector<Item> newItems) {
	items = newItems;
}

Room Room::getExit(Exits exit) {
	return neighbors[exit];
}

bool Room::isVisited() {
	return visited;
}

std::map<int, pair<TYPES::ACTION_LIST, string>> Room::getCommands()
{
	return currentState->getCommands();
}

void Room::SetCommand(TYPES::ACTION_LIST action)
{
	currentCommand = action;
}

void Room::Execute()
{
	switch (currentCommand) {
		case TYPES::ACTION_LIST::FIGHT:
			cout << "You are looking for a fight" << endl;
			currentState->goNext(this);
			break;
		case TYPES::ACTION_LIST::RUN:
			cout << "You are trying to run away, coward!" << endl;
			break;
		case TYPES::ACTION_LIST::SEE_BAG:
			cout << "You left your bag at home, idot!" << endl;
			break;
		case TYPES::ACTION_LIST::REST:
			cout << "You are not tired." << endl;
			break;
		case TYPES::ACTION_LIST::VIEW_MAP:
			cout << "You did not bring a map." << endl;
			break;
		case TYPES::ACTION_LIST::VIEW_HERO:
			cout << "You are no hero." << endl;
			break;
		case TYPES::ACTION_LIST::CHANGE_ROOM:
			cout << "You can't do that right now." << endl;
			break;
	}
}

Room::~Room() {
//	delete currentState;
}