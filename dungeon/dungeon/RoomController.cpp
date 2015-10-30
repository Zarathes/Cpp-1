#include "stdafx.h"
#include "RoomController.h"

using std::cout;
using std::cin;
using std::endl;
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include <cstdio>


RoomController::RoomController() {
	read = *new ReadTextFile();
	state = read.readFile("../state.txt");
	furniture = read.readFile("../furniture.txt");
	lightning = read.readFile("../lightning.txt");
	size = read.readFile("../size.txt");
}

bool RoomController::createDungeon(const int level, const int width){
	if (level <= 1000 && width <= 1000){
		for (int currentLevel = 1; currentLevel <= level; currentLevel++){
			for (int currentWidth = 1; currentWidth <= width; currentWidth++){
				Room room = *new Room();
				room.setDescription(createDescription());
				rooms[currentLevel][currentWidth] = room;
			}
			connect(level, width);
		}







		return true;
	}
	return false;
}

std::string RoomController::createDescription(){
	std::string sizeInput = read.randomNize(size);
	std::string furnitureInput = read.randomNize(furniture);
	std::string lightningInput = read.randomNize(lightning);
	std::string stateInput = read.randomNize(state);

	cout << "Make description" << endl;
	std::string descr = "Welcome you are in a ";
	descr += sizeInput;
	descr += " size room. The room has ";
	descr += furnitureInput;
	descr += " The room is ";
	descr += stateInput;
	descr += " and ";
	descr += lightningInput;
	
	cout << descr << endl;

	return descr;
}

void RoomController::connect(int level, int width){
	if (level > 1){
		//bepaal random getal bij width
		//zet daar trapup
		//bepaal new randomgetal die niet hetzelfde is als strapup
		//doe trapdown
	}
}