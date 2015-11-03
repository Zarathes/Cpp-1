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
			for (int i = 0; i < consumableItems.size(); i++){
				cout << consumableItems[i]->getName() << endl;
			}
		}

		if (equipableItems.empty()){
			cout << "No equipable items" << endl;
		}
		else{
			cout << "The room has the following equipable items: " << endl;
			for (int i = 0; i < equipableItems.size(); i++){
				cout << equipableItems[i]->getName() << endl;
			}
		}

		cout << "This room has an exit to:" << endl;
		std::map<Exits, std::pair<std::string, Room*>>::iterator temp = neighbors.begin();

		while (temp != neighbors.end()){
			cout << temp->second.first << endl;			
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

int Room::attackEnemies(int attackPoints){
	int experiencepoints = 0;
	for (int i = 0; i < enemies.size(); i++){
		enemies[i]->underAttack(attackPoints);
		if (!enemies[i]->living()){
			cout << "You defeated " << enemies[i]->getName() << endl;
			//delete enemie
			delete enemies[i];
			enemies.erase(enemies.begin()+i);
			experiencepoints += 5;
		}
	}
	return experiencepoints;
}

int Room::fight(){
	int attackpoints = 0;

	for (int i = 0; i < enemies.size(); i++){
		attackpoints += enemies[i]->attack();
	}
	return attackpoints;
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