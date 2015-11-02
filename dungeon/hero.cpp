#include "stdafx.h"
#include "Hero.h"
using std::cout;
using std::cin;
using std::endl;

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

void Hero::showStatistics(){
	cout << "Hero statistics " << endl;
	cout << "Experiance points: " << experiancePoints << endl;
	cout << "Perception points: " << perceptionPoints << endl;
	cout << "" << endl;
}

void Hero::showBag(){
	cout << "show bag" << endl;
}

void Hero::SetCommand(TYPES::ACTION_LIST command){
	currentCommand = command;
}

void Hero::Execute(){
	switch (currentCommand) {
	case TYPES::ACTION_LIST::VIEW_HERO:
		showStatistics();
		break;
	case TYPES::ACTION_LIST::SEE_BAG:
		showBag();
		break;
	}
}