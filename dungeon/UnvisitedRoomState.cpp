#include "stdafx.h"
#include "UnvisitedRoomState.h"

#include "InfestedRoomState.h"

using namespace std;

UnvisitedRoomState::UnvisitedRoomState(){
	cout << "Entering UnvisitedRoomState" << endl;
}

void UnvisitedRoomState::goNext(Client* context) {
	context->setState(new InfestedRoomState());
	delete this;
}

std::map<int, pair<TYPES::ACTION_LIST, string>> UnvisitedRoomState::getCommands() {
	std::map<int, pair<TYPES::ACTION_LIST, string>> commands = std::map<int, pair<TYPES::ACTION_LIST, string>>();
	commands.insert(pair<int, pair<TYPES::ACTION_LIST, string>>(1, pair<TYPES::ACTION_LIST, string>(TYPES::ACTION_LIST::FIGHT, "Fight")));
	return commands;
}

UnvisitedRoomState::~UnvisitedRoomState(){
}
