#include "stdafx.h"
#include "Generator.h"
#include "Stairs.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include <cstdio>

#include "Exits.h"


Generator::Generator() {
	read = *new ReadTextFile();
	size = read.readFile("config/size.txt");
	roomType = read.readFile("config/roomType.txt");
	state = read.readFile("config/state.txt");
	furniture = read.readFile("config/furniture.txt");
	lightning = read.readFile("config/lightning.txt");
	enemies = read.readFile("config/enemies.txt");
}

bool Generator::createDungeon(int depth, int width, int height){
	level = depth;	
	width = width;
	height = height;	

	vector< vector< vector<Room*> > > dungeon(depth, vector<vector<Room*>>(width, vector<Room*>(height, new Room())));

	//depth
	for (auto &a : dungeon) {
		// width
		for (auto &b : a) {
			// height
			for (auto &c : b) {
				Room *temp = (Room*)c;
				temp->setDescription(createDescription());
				temp->setEnemies(createEnemies());
			}
		}
	}

	startRoom = dungeon[0][0][0];

	//Corridors
	//depth
	for (size_t z = 0; z < dungeon.size(); z++)
	{
		//width
		for (size_t y = 0; y < dungeon[z].size(); y++)
		{
			//height
			for (size_t x = 0; x < dungeon[z][y].size(); x++)
			{
				Room *temp = dungeon[z][y][x];

			}
		}
	}

	return true;
}

string Generator::createDescription(){
	string sizeInput = read.randomNize(size);
	string roomInput = read.randomNize(roomType);
	string furnitureInput = read.randomNize(furniture);
	string lightningInput = read.randomNize(lightning);
	string stateInput = read.randomNize(state);

//	cout << "Make description" << endl;
	string descr = "Description: ";
	descr += "You Are in a " + sizeInput + " " + roomInput + ". ";
	descr += "The "+ roomInput +" has " + furnitureInput +". ";
	descr += "The room is " + stateInput +" and " + lightningInput + ".";
	
//	cout << descr << endl;

	return descr;
}

vector<Enemy*> Generator::createEnemies() {
	vector<Enemy*> infestation;

	int randNum = rand() % (4 - -1 + 1) + -1;

	for (int i = 0; i < randNum; i++) {
		string enemiesInput = read.randomNize(enemies);
		infestation.push_back(new Enemy(enemiesInput));
	}

	return infestation;
}

int Generator::connect(int currentLevel){
	for (int currentWidth = 1; currentWidth <= width; currentWidth++){
		if (currentWidth != width){
			rooms[currentLevel][currentWidth]->setNeighbours(EAST, *rooms[currentLevel][currentWidth + 1]);
		}
		if (currentWidth > 1){
			rooms[currentLevel][currentWidth]->setNeighbours(WEST, *rooms[currentLevel][currentWidth - 1]);
		}
	}
	if (currentLevel > 1){
	/*	int stairsUpRandom = rand() % width;
		int stairsDownRandom = rand() % width;
		while (stairsDownRandom == stairsUpRandom){
			stairsDownRandom = rand() % width;
		}

		Stairs stairsUp = Stairs();
		Stairs stairsDown = Stairs();
		

		rooms[currentLevel][stairsUpRandom]->setNeighbours(NORTH, stairsUp);
		rooms[currentLevel-1][stairsDownRandom]->setNeighbours(SOUTH,  stairsDown);*/
		//bepaal random getal bij width
		//zet daar trapup
		//bepaal new randomgetal die niet hetzelfde is als strapup
		//doe trapdown
		//en doe currentlevel+1
	}
	else{
		int randomIndex = rand() % width;
		startRoom = rooms[currentLevel][randomIndex];
	}

	return currentLevel;
}

void Generator::showMap(){
	for (int currentLevel = mapLevel; currentLevel > 0; currentLevel--){
		for (int currentWidth = 1; currentWidth <= width; currentWidth++){
			Room *currentRoom = rooms[currentLevel][currentWidth];

		/*	if (&currentRoom->getExit(WEST) != nullptr){
				printf(" - ");
			}
			else{
				printf("   ");
			}*/


			if (currentRoom == startRoom){				
				printf("   s   ");				
			}else if (currentRoom->isVisited()){
				printf("   r   ");
			}else{
				printf("   .   ");
			}

		/*	if (&currentRoom->getExit(EAST) != nullptr){
				printf(" - ");
			}
			else{
				printf("   ");
			}*/
		}
		cout<< ""<< endl;
	}
}

Room* Generator::getStartRoom() {
	return startRoom;
}