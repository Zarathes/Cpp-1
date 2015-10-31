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

//exceptions
using std::invalid_argument;
using std::out_of_range;

#include "ConcreteCommand.h"

Game::Game() : running{ true }
{
	currentRoom = new Room();

	while (running) {
		commands = currentRoom->getCommands();
		handelAction(readAction());
	}
}

Game::~Game()
{
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
