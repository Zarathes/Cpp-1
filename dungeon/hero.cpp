#include "stdafx.h"
#include "Hero.h"
#include <iostream>
#include <string>
#include <map>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::map;
using std::pair;

//exceptions
using std::invalid_argument;
using std::out_of_range;

Hero::Hero() : Character("Hero"){
	rooms = std::stack<Room*>();
	lifePoints = 250;
	alive = true;
}

void Hero::insertCurrentRoom(Room *room){	
	rooms.push(room);
	currentRoom = room;
	currentRoom->enteringRoom();
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
		for (Equipable* eq : equipment){
			cout << eq->getName() << endl;
		}
	}
	
	cout << "Consumable: " << endl;
	if (consumable.empty()){
		cout << "No inventory" << endl;
	}
	else{
		for (Consumable* cons : consumable){
			cout << cons->getName() << endl;
		}
	}
	
	cout << "" << endl;
}

void Hero::handelRoomChange()
{
	int current = 1;

	map<Exits, pair<string, Room*>> neighbors = currentRoom->getNeighbours();

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


	cout << "Choose a direction :" << endl;

	string input;
	int command;
	getline(cin, input);

	std::string::size_type rest;
	try {
		command = std::stoi(input, &rest);
		if (neighbors.find((Exits)command) != neighbors.end()) {
			for (auto const& a : neighbors)
			{
				if (a.first == command) {
					currentRoom = a.second.second;
					currentRoom->enteringRoom();
				}
			}
		}
		else {
			throw invalid_argument("No valid Action");
		}
	}
	catch (const invalid_argument& ia) {
		cout << "Invalid arguments: " << ia.what() << endl;
	}
	catch (const out_of_range& oor) {
		cout << "Out of Range Error: " << oor.what() << endl;
	}
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
	for (auto item : currentRoom->getConsumableItems()){
		consumable.push_back(item);		
		cout << "Added " << item->getName() << " to your bag" << endl;
	}
	for (auto item : currentRoom->getEquipableItems()){
		equipment.push_back(item);
		cout << "Added " << item->getName() << " to your bag" << endl;
	}
	currentRoom->setConsumableItems(currentRoom->getConsumableItems().clear());

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
	case TYPES::ACTION_LIST::CHANGE_ROOM:
		handelRoomChange();
		break;
	}
}