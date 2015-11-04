#include "stdafx.h"
#include "Generator.h"
#include "Stairs.h"
#include "State.h"


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
#include <list>

#include "Exits.h"


Generator::Generator(int d, int w, int h) 
	: dungeon(depth, vector<vector<Room>>(height, vector<Room>(width, Room()))), depth(d), width(w), height(h)
{
	read = *new ReadTextFile();
	size = read.readFile("config/size.txt");
	roomType = read.readFile("config/roomType.txt");
	state = read.readFile("config/state.txt");
	furniture = read.readFile("config/furniture.txt");
	lightning = read.readFile("config/lightning.txt");

	enemies = read.readFile("config/enemies.txt");
	attackPointsEnemy = read.readFile("config/attackPoints.txt");
	lifePointsEnemy = read.readFile("config/lifePoints.txt");
	
	equipableNames = read.readFile("config/EquipableNames.txt");
	consumbableNames = read.readFile("config/ConsumableNames.txt");
	attackPointsItem = read.readFile("config/itemPoints.txt");

	traps = read.readFile("config/TrapNames.txt");
	trapDescription = read.readFile("config/TrapDescription.txt");
}

bool Generator::createDungeon(){
	//depth
	for (auto &a : dungeon) {
		// width
		for (auto &b : a) {
			// height
			for (auto &c : b) {
				c.setDescription(createDescription());
				c.setEnemies(createEnemies());
				c.setConsumableItems(createConsumableItems());
				c.setEquipableItems(createEquipableItems());
				c.setTrap(createTrap());
			}
		}
	}

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
				Room *current = &dungeon[z][y][x];
				current->setDepth(z);
				vector<Exits> exits = createExit(y, x);
				for (Exits i : exits) {
					Room *neighbor;
					switch (i) {
					case Exits::NORTH:
						neighbor = &dungeon[z][y - 1][x];

						current->setNeighbours(Exits::NORTH, std::pair<string, Room*> ("North", neighbor));
						neighbor->setNeighbours(Exits::SOUTH, std::pair<string, Room*>("South", current));
						break;					
					case Exits::EAST:
						neighbor = &dungeon[z][y][x + 1];

						current->setNeighbours(Exits::EAST, std::pair<string, Room*>("East", neighbor));
						neighbor->setNeighbours(Exits::WEST, std::pair<string, Room*>("West", current));
						break;					
					case Exits::SOUTH:
						neighbor = &dungeon[z][y + 1][x];

						current->setNeighbours(Exits::SOUTH, std::pair<string, Room*>("South", neighbor));
						neighbor->setNeighbours(Exits::NORTH, std::pair<string, Room*>("North", current));
						break;				
					case Exits::WEST:
						neighbor = &dungeon[z][y][x - 1];

						current->setNeighbours(Exits::WEST, std::pair<string, Room*>("West", neighbor));
						neighbor->setNeighbours(Exits::EAST, std::pair<string, Room*>("East", current));
						break;
					}
				}
			}
		}
	}

	int randomStartY = rand() % (height)+0;
	int randomStartX = rand() % (width)+0;

	std::vector<Enemy*> empty;
	startRoom = &dungeon[0][randomStartY][randomStartX];
	startRoom->setEnemies(empty);
	startRoom->setTrap(nullptr);

	while (endRoom == startRoom || endRoom == nullptr){
		randomStartY = rand() % (height)+0;
		randomStartX = rand() % (width)+0;

		endRoom = &dungeon[depth - 1][randomStartY][randomStartX];
	}

	for (auto &neigh : endRoom->getNeighbours()){
		neigh.second.second->setEnemies(createEndEnemy());
	}
	endRoom->setEnemies(empty);

	//Stairs
	if (dungeon.size() > 1) {
		for (size_t z = 0; z < dungeon.size(); z++)
		{
			if (z != dungeon.size()-1) {
				int randomWidthUp = rand() % (height) + 0;
				int randomHeightUp = rand() % (width) + 0;
				int randomWidthDown = rand() % (height) + 0;
				int randomHeightDown = rand() % (width) + 0;


				Room *current = &dungeon[z][randomWidthUp][randomHeightUp];

				while (current == startRoom || current == endRoom){
					randomWidthUp = rand() % (height - 1 + 1) + 0;
					randomHeightUp = rand() % (width - 1 + 1) + 0;
					current = &dungeon[z][randomWidthUp][randomHeightUp];
				}

				Room *neighbor = &dungeon[z+1][randomWidthDown][randomHeightDown];
				current->setNeighbours(Exits::UP, std::pair<string, Room*>("Up", neighbor));
				neighbor->setNeighbours(Exits::DOWN, std::pair<string, Room*>("Down", current));
			}
		}
	}

	return true;
}

vector<Exits> Generator::createExit(int y, int x) {
	std::vector<Exits> possibleExits;
	std::vector<Exits> actiualExits;

	if (y > 0) {
		possibleExits.push_back(Exits::NORTH);
	}
	if (y < height-1) {
		possibleExits.push_back(Exits::SOUTH);
	}
	if (x > 0) {
		possibleExits.push_back(Exits::WEST);
	}
	if (x < width-1) {
		possibleExits.push_back(Exits::EAST);
	}

	int randNum = 1 + (rand() % (int)(possibleExits.size()));

	for (int i = 0; i < randNum; i++) {
		int randExit = 0 + (rand() % (int)(possibleExits.size()-1 - 0 + 1));

		actiualExits.push_back(possibleExits[randExit]);

		possibleExits.erase(possibleExits.begin() + randExit);
	}
	
	return actiualExits;
}

string Generator::createDescription(){
	string sizeInput = read.randomNize(size);
	string roomInput = read.randomNize(roomType);
	string furnitureInput = read.randomNize(furniture);
	string lightningInput = read.randomNize(lightning);
	string stateInput = read.randomNize(state);

//	cout << "Make description" << endl;
	string descr = "Description: ";
	descr += "You are in a " + sizeInput + " " + roomInput + ". ";
	descr += "The "+ roomInput +" has " + furnitureInput +". ";
	descr += "The room is " + stateInput +" and " + lightningInput + ".";
	
//	cout << descr << endl;

	return descr;
}

vector<Enemy*> Generator::createEnemies() {
	vector<Enemy*> infestation;

	int randNum = rand() % (2 - -1 + 1) + -1;	

	for (int i = 0; i < randNum; i++) {
		string enemiesInput = read.randomNize(enemies);
		string lifePointsString = read.randomNize(lifePointsEnemy);
		string attackPointsString = read.randomNize(attackPointsEnemy);

		int lifePointsNew = atoi(lifePointsString.c_str());
		int attackPointsNew = atoi(attackPointsString.c_str());

		infestation.push_back(new Enemy(enemiesInput, attackPointsNew, lifePointsNew));
	}

	return infestation;
}

vector<Enemy*> Generator::createEndEnemy(){
	vector<Enemy*> infestation;

		string enemiesName = read.randomNize(read.readFile("config/endBossNames.txt"));
		string lifePointsString = read.randomNize(read.readFile("config/endBossLife.txt"));
		string attackPointsString = read.randomNize(read.readFile("config/endBossAttack.txt"));

		int lifePointsNew = atoi(lifePointsString.c_str());
		int attackPointsNew = atoi(attackPointsString.c_str());

		infestation.push_back(new Enemy(enemiesName, attackPointsNew, 50));

	return infestation;
}

vector<Consumable*> Generator::createConsumableItems() {
	vector<Consumable*> infestation;

	int randNumCons = rand() % (2 - -1 + 1) + -1;
	
	for (int i = 0; i < randNumCons; i++) {
		string consumable = read.randomNize(consumbableNames);
		string pointsString = read.randomNize(attackPointsItem);
		int attackPoints = atoi(pointsString.c_str());

		infestation.push_back(new Consumable(consumable, attackPoints));
	}	
	return infestation;
}

vector<Equipable*> Generator::createEquipableItems(){
	vector<Equipable*> infestation;
	int randNumEq = rand() % (2 - -1 + 1) + -1;

	for (int i = 0; i < randNumEq; i++) {

		string equipable = read.randomNize(equipableNames);
		string pointsString = read.randomNize(attackPointsItem);
		int attackPoints = atoi(pointsString.c_str());

		infestation.push_back(new Equipable(equipable, attackPoints));
	}
	return infestation;
}

Trap* Generator::createTrap() {
	int randNum = rand() % 5;

	if (randNum == 0) {
		string trapNameInput = read.randomNize(traps);
		string attackPointsString = read.randomNize(attackPointsEnemy);
		string perceptionPointsString = read.randomNize(attackPointsItem);

		string trapDescription = "Description: ";
		trapDescription += "You triggered a " + trapNameInput + " and were hit for " + attackPointsString + " damage.";
		return new Trap(trapNameInput, trapDescription, atoi(attackPointsString.c_str()), atoi(perceptionPointsString.c_str()));
	}

	return nullptr;
}

void Generator::showMap(int currentDepth) {
	string upStr;
	string middleStr;
	string downStr;

	//width
	for (size_t y = 0; y < dungeon[currentDepth].size(); y++)
	{
		//height
		for (size_t x = 0; x < dungeon[currentDepth][y].size(); x++)
		{
			Room *current = &dungeon[currentDepth][y][x];	
			middleStr += ". ";
			downStr += "  ";
			if(current->getState()->classname() != "UnvisitedRoomState"){
				if (current == startRoom) {
					middleStr.replace(middleStr.length() - 2, 1, "S");
				}
				else {
					middleStr.replace(middleStr.length() - 2, 1, "N");
				}

				for (auto const& a : current->getNeighbours())
				{
					switch (a.first) {
					case Exits::WEST:
						middleStr.replace(middleStr.length() - 3, 1, "-");
						break;
					case Exits::NORTH:
						upStr.replace(middleStr.length() - 2, 1, "|");
						break;
					case Exits::EAST:
						middleStr.replace(middleStr.length() - 1, 1, "-");
						break;
					case Exits::SOUTH:
						downStr.replace(middleStr.length() - 2, 1, "|");
						break;
					case Exits::UP:
						downStr.replace(downStr.length() - 2, 1, "|");
						middleStr.replace(middleStr.length() - 2, 1, "U");
						break;
					case Exits::DOWN:
						downStr.replace(downStr.length() - 2, 1, "|");
						middleStr.replace(middleStr.length() - 2, 1, "D");
						break;
					default:
						break;
					}
				}
			}
		}
		if (upStr.length()) {
			cout << upStr << endl;
		}
		cout << middleStr << endl;

		upStr = downStr;
		middleStr = "";
		downStr = "";
	}

	cout << "Legend:" << endl;
	cout << "|- : Corridor" << endl;
	cout << "S : Start Location" << endl;
	cout << "B : Boss" << endl;
	cout << "N : Normal Room" << endl;
	cout << "D : Stairs Down" << endl;
	cout << "U : Stairs Up" << endl;
	cout << ". : Unvisited" << endl;
}

Room* Generator::getStartRoom() {
	return startRoom;
}

Room* Generator::getEndRoom(){
	return endRoom;
}