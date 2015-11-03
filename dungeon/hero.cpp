#include "stdafx.h"
#include "Hero.h"
using std::cout;
using std::cin;
using std::endl;
#include <iostream>
#include <string>

Hero::Hero() : Character("Hero"){
	rooms = std::stack<Room*>();
	lifePoints = 250;
	alive = true;
}

void Hero::insertCurrentRoom(Room *room){
	rooms.push(room);
	currentRoom = room;
}

Room* Hero::getCurrentRoom(){
	return Hero::currentRoom;
}

void Hero::showStatistics(){
	cout << "Hero statistics " << endl;
	cout << "Live points: " << lifePoints << endl;
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

void Hero::underAttack(int points){
	lifePoints -= points;
	if (lifePoints <= 0){
		alive = false;
	}
	//check alive
}

bool Hero::living(){
	return alive;
}

void Hero::run(){
	if (rooms.size() > 1){
		rooms.pop();
		currentRoom = rooms.top();		
	}
	else{
		cout << "No room to run in" << endl;
	}
}

void Hero::getItems(){
	//get items en doe ze in bag
	for (auto item : currentRoom->getItems()){
		cout << "Added " << item->getName() << " to your bag" << endl;
	}
}

void Hero::Execute(){
	switch (currentCommand) {
	case TYPES::ACTION_LIST::VIEW_HERO:
		showStatistics();
		break;
	case TYPES::ACTION_LIST::SEE_BAG:
		showBag();
		break;
	case TYPES::ACTION_LIST::RUN:
		run();
		break;
	case TYPES::ACTION_LIST::GET_ITEMS:
		getItems();
		break;
	}
}