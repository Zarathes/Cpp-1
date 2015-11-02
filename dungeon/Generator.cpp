#include "stdafx.h"
#include "Generator.h"
#include "Stairs.h"

using std::cout;
using std::cin;
using std::endl;
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include <cstdio>


Generator::Generator() {
	read = *new ReadTextFile();
	state = read.readFile("config/state.txt");
	furniture = read.readFile("config/furniture.txt");
	lightning = read.readFile("config/lightning.txt");
	size = read.readFile("config/size.txt");
}

bool Generator::createDungeon(int newLevel, int totalRooms){
	level = newLevel;	

	std::list<int> numbers;
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(4);
	numbers.push_back(5);
	numbers.push_back(6);
	numbers.push_back(7);
	numbers.push_back(8);
	numbers.push_back(9);
	numbers.push_back(10);

	subset_sum(numbers, totalRooms);

	getchar();

	mapLevel = 0;
	if (level <= 1000 && width <= 1000 && level > 0 && width > 0){
		for (int currentLevel = 1; currentLevel <= level; currentLevel++){
			mapLevel++;
			for (int currentWidth = 1; currentWidth <= width; currentWidth++){
				Room *room = new Room();
				room->setLevel(level);
				room->setDescription(createDescription());
				rooms[mapLevel][currentWidth] = room;
		
			}
			
			mapLevel = connect(mapLevel);
		}
		//showMap();
		return true;
	}
	return false;
}

std::vector<Room>* Generator::makeRow(){
	std::vector<Room>* roomsNew = new std::vector<Room>();
	for (int currentWidth = 1; currentWidth <= width; currentWidth++){
		Room *room = new Room();
		room->setLevel(level);
		room->setDescription(createDescription());
		//roomsNew[currentWidth] = room;
	}

	connect(2);
	return roomsNew;
}

std::string Generator::createDescription(){
	std::string sizeInput = read.randomNize(size);
	std::string furnitureInput = read.randomNize(furniture);
	std::string lightningInput = read.randomNize(lightning);
	std::string stateInput = read.randomNize(state);

//	cout << "Make description" << endl;
	std::string descr = "Welcome you are in a ";
	descr += sizeInput;
	descr += " size room. The room has ";
	descr += furnitureInput;
	descr += " The room is ";
	descr += stateInput;
	descr += " and ";
	descr += lightningInput;
	
//	cout << descr << endl;

	return descr;
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

void Generator::subset_sum_recursive(std::list<int> numbers, int target, std::list<int> partial)
{
	int s = 0;
	for (std::list<int>::const_iterator cit = partial.begin(); cit != partial.end(); cit++)
	{
		s += *cit;
	}
	if (s == target)
	{
		std::cout << "sum([";

		for (std::list<int>::const_iterator cit = partial.begin(); cit != partial.end(); cit++)
		{
			std::cout << *cit << ",";
		}
		std::cout << "])=" << target << std::endl;
	}
	if (s >= target)
		return;
	int n;
	for (std::list<int>::const_iterator ai = numbers.begin(); ai != numbers.end(); ai++)
	{
		n = *ai;
		std::list<int> remaining;
		for (std::list<int>::const_iterator aj = ai; aj != numbers.end(); aj++)
		{
			if (aj == ai)continue;
			remaining.push_back(*aj);
		}
		std::list<int> partial_rec = partial;
		partial_rec.push_back(n);
		subset_sum_recursive(remaining, target, partial_rec);

	}
}

void Generator::subset_sum(std::list<int> numbers, int target)
{
	subset_sum_recursive(numbers, target, std::list<int>());
}