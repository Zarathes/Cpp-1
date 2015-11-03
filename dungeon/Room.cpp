#include "stdafx.h"
#include "Room.h"

#include "State.h"
#include "UnvisitedRoomState.h"
#include "InfestedRoomState.h"
#include "ClearedRoomState.h"

using namespace std;

Room::Room() {
	currentState = new UnvisitedRoomState();
}

void Room::setDescription(std::string newDescr) {
	description = newDescr;
}

void Room::printDescription(){
	cout << description << endl;
}

void Room::enteringRoom(){
	
	if (enemies.empty()){
		currentState = new ClearedRoomState();
		printDescription();
		if (items.empty()){
			cout << "No items" << endl;
		}
		else{
			cout << "The room has the following items: " << endl;
			for (auto item : items){
				cout << item->getName() << endl;
			}
		}
		cout << "This room has an exit to:" << endl;
		std::map<Exits, std::pair<std::string, Room*>>::iterator temp = neighbors.begin();

		while (temp != neighbors.end()){
			switch (temp->first) {
			case 0:
				cout << "North" << endl;
				break;
			case 1:
				cout << "East" << endl;
				break;
			case 2:
				cout << "South" << endl;
				break;
			case 3:
				cout << "West" << endl;
				break;
			}
			++temp;
		}


	}
	else{
		currentState = new InfestedRoomState();
		cout << "In this room are enemies:" << endl;
		for (int i = 0; i < enemies.size(); i++){
			cout << enemies[i]->getName() << "  " << enemies[i]->getLifePoints() << endl;
		}
	}
}

void Room::setNeighbours(Exits exit, pair<string, Room*> room) {
	neighbors[exit] = room;
}


map<Exits, pair<string, Room*>> Room::getNeighbours() {
	return neighbors;
}

void Room::setEnemies(std::vector<Enemy*> newEnemies) {
	enemies = newEnemies;
}

void Room::deleteEnemy(Enemy enemy) {
	//enemies.erase(std::remove(enemies.begin(), enemies.end(), enemy), enemies.end());
}

void Room::setItems(std::vector<Item*> newItems) {
	items = newItems;
}

std::vector<Item*> Room::getItems(){
	return items;
}


Room* Room::getNeighbour(Exits exit) {
	return neighbors[exit].second;
}

bool Room::isVisited() {
	if (currentState == new UnvisitedRoomState){
		return false;
	}
	return true;
}

void Room::fight(){
	//hero attack
	//enemy attacks
	//new menu for choosing

	for (int i = 0; i < enemies.size(); i++){
		//int x = enemies[i].attack();
	}

	if (enemies.empty()){
		currentState->goNext(this);
	}
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
	}
}

Room::~Room() {
//	delete currentState;
}