#include "stdafx.h"
#include "RoomController.h"
#include "ReadTextFile.h"
using std::cout;
using std::cin;
using std::endl;
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <cstdio>


RoomController::RoomController() {
	read = *new ReadTextFile();
	state = read.readFile("Room\state.txt");
}

bool RoomController::createDungeon(const int level, const int width){
	if (level <= 1000 && width <= 1000){

		for (int currentLevel = 1; currentLevel <= level; currentLevel++){
			for (int currentWidth = 1; currentWidth <= width; currentWidth++){
				Room room = *new Room();
				room.setDescription(createDescription());
			//	room.addEnemy(*new Enemy());
				rooms[currentLevel][currentWidth] = room;
				//generate random kamer
				//zet vijanden in kamer of niet
			}

			//random getal waar trap moet komen omhoog en waar trap moet komen omlaag
		}







		return true;
	}
	return false;
}

std::string RoomController::createDescription(){
	std::string descr = "Welcome in room";


/*	std::vector<std::string> state = read.readFile("Room\state.txt");
	std::vector<std::string> furniture = read.readFile("Room\furniture.txt");
	std::vector<std::string> lightning = read.readFile("Room\lightning.txt");
	std::vector<std::string> size = read.readFile("Room\size.txt");
	*/
//std::string input = 	read.randomNize(size);

	cout << "Input an action." << endl;
	/*for (std::vector<std::string>::const_iterator i = size.begin(); i != size.end(); ++i)
		std::cout << *i << ' ';
		*/


   // std::string result = read.randomNize(options);
	descr += "helloo";
	return descr;
}