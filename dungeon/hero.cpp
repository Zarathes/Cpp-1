#include "stdafx.h"
#include "Hero.h"
using std::cout;
using std::cin;
using std::endl;
#include <iostream>
#include <string>



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
	cout << "This is in your bag " << endl;
	cout << "Equipment: " << endl;
	if (equipment.empty()){
		cout << "No equipment" << endl;
	}
	else{
		for (Equipable eq : equipment){
			cout << eq.getName() << endl;
		}
	}
	
	cout << "Consumable: " << endl;
	if (consumable.empty()){
		cout << "No inventory" << endl;
	}
	else{
		for (Consumable cons : consumable){
			cout << cons.getName() << endl;
		}
	}
	
	cout << "" << endl;
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