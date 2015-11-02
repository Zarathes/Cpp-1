#include "stdafx.h"
#include "Game.h"

using std::map;
using std::pair;

#include <string>
using std::string;

using std::getline;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "RoomController.h"
#include "ConcreteCommand.h"

//exceptions
using std::invalid_argument;
using std::out_of_range;


Game::Game() : running{ true }
{
	actions = map<int, string>();

	actions.insert(pair<int, string>(1, string("Fight")));
	actions.insert(pair<int, string>(2, string("Run")));
	actions.insert(pair<int, string>(3, string("See Bag")));
	actions.insert(pair<int, string>(4, string("Rest")));
	actions.insert(pair<int, string>(5, string("View Map")));
	actions.insert(pair<int, string>(6, string("View Hero")));
	actions.insert(pair<int, string>(7, string("Change Room")));
	actions.insert(pair<int, string>(8, string("Stairs Up")));
	actions.insert(pair<int, string>(9, string("Stairs Down")));
	start();
}

Game::~Game()
{
}

void Game::start(){
	RoomController *roomController = new RoomController();
	cout << "How many levels should the dungeon have?" << endl;
	string  levelString;
	getline(cin, levelString);
	cout << "How many rooms in a level should the dungeon have?" << endl;
	string widthString;
	getline(cin, widthString);
	std::string::size_type rest;
	int level = std::stoi(levelString, &rest);
	int width = std::stoi(widthString, &rest);
	
	currentRoom = new Room();
	if (roomController->createDungeon(level, width)){
		while (running) {
			commands = currentRoom->getCommands();
			handelAction(readAction());
		}
	}
	else{
		cout << "Enter numbers above 0 and under 500" << endl;
		start();
	}
}

string Game::readAction()
{
	string input;

	cout << "Input an action." << endl;
	printActions();
	getline(cin, input);

	return input;
}

void Game::printActions()
{
	int current = 1;

	int index = commands.size();
	for (auto const& a : commands)
	{
		if (current == index) {
			cout << a.first << ": " << a.second.second << endl;
		}
		else {
			cout << a.first << ": " << a.second.second << " | ";
		}

		current++;
	}
}

void Game::handelAction(string input)
{
	std::string::size_type rest;

	try {
		int command = std::stoi(input, &rest);
		if (commands.find(command) != commands.end()) {
			cout << "Your action is: " << command << ": " << commands[command].second << "." << endl;

			switch (commands[command].first) {
			case TYPES::ACTION_LIST::FIGHT:
				FightCommand(currentRoom).Execute();
				break;
			case TYPES::ACTION_LIST::RUN:
				RunCommand(currentRoom).Execute();
				break;
			case TYPES::ACTION_LIST::SEE_BAG:
				SeeBagCommand(currentRoom).Execute();
				break;
			case TYPES::ACTION_LIST::REST:
				RestCommand(currentRoom).Execute();
				break;
			case TYPES::ACTION_LIST::VIEW_MAP:
				ViewMapCommand(currentRoom).Execute();
				break;
			case TYPES::ACTION_LIST::VIEW_HERO:
				ViewHeroCommand(currentRoom).Execute();
				break;
			case TYPES::ACTION_LIST::CHANGE_ROOM:
				ChangeRoomCommand(currentRoom).Execute();
				break;
			}

			//cout << "Remaining characters: " << input.substr(rest) << "." << endl;
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
