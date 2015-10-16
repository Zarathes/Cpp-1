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

	while (running) {
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
	int actionCount = actions.size();
	for (auto const& a : actions)
	{
		if (current == actionCount) {
			cout << a.first << ": " << a.second << endl;
		}
		else {
			cout << a.first << ": " << a.second << " | ";
		}

		current++;
	}
}

void Game::handelAction(string input)
{
	std::string::size_type rest;

	try {
		int action = std::stoi(input, &rest);
		if (actions.find(action) != actions.end()) {
			cout << "Your action is: " << action << ": " << actions[action] << "." << endl;
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
