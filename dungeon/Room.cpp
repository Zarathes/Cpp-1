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
		if (consumableItems.empty()){
			cout << "No consumable items" << endl;
		}
		else{
			cout << "The room has the following consumable items: " << endl;
			for (auto item : consumableItems){
				cout << item->getName() << endl;
			}
		}

		if (equipableItems.empty()){
			cout << "No equipable items" << endl;
		}
		else{
			cout << "The room has the following equipable items: " << endl;
			for (auto item : equipableItems){
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

void Room::setEnemies(std::vector<Enemy*> newEnemies) {
	enemies = newEnemies;
}

void Room::deleteEnemy(Enemy enemy) {
	//enemies.erase(std::remove(enemies.begin(), enemies.end(), enemy), enemies.end());
}

void Room::setEquipableItems(std::vector<Equipable*> newItems) {
	equipableItems = newItems;
}

void Room::setConsumableItems(std::vector<Consumable*> newItems) {
	consumableItems = newItems;
}

std::vector<Equipable*> Room::getEquipableItems(){
	return equipableItems;
}

std::vector<Consumable*> Room::getConsumableItems(){
	return consumableItems;
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
		case TYPES::ACTION_LIST::CHANGE_ROOM:
			handelRoomChange();
			break;
	}
}

int Room::inputNumber(string question) {
	cout << question << endl;

	string input;
	int output;
	getline(cin, input);

	std::string::size_type rest;

	try {
		output = std::stoi(input, &rest);
	}
	catch (const invalid_argument& ia) {
		cout << "Invalid arguments: " << ia.what() << endl;
		return inputNumber(question);
	}
	catch (const out_of_range& oor) {
		cout << "Out of Range Error: " << oor.what() << endl;
		return inputNumber(question);
	}

	return output;
}

void Room::handelRoomChange()
{
	int current = 1;

	int index = neighbors.size();
	for (auto const& a : neighbors)
	{
		if (current == index) {
			cout << a.first << ": " << a.second.first << endl;
		}
		else {
			cout << a.first << ": " << a.second.first << " | ";
		}

		current++;
	}

	int command = inputNumber("Choose a direction:");

	try {
		if (neighbors.find((Exits)command) != neighbors.end()) {
			for (auto const& a : neighbors)
			{
				if (a.first == command) {
					//this = a.second.second;
				}
			}
		}
		else {
			throw invalid_argument("No valid Action");
		}
	}
	catch (const invalid_argument& ia) {
		cout << "Invalid arguments: " << ia.what() << endl;
		handelRoomChange();
	}
}

Room::~Room() {
//	delete currentState;
}