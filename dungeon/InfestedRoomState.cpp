#include "stdafx.h"
#include "InfestedRoomState.h"
#include "ClearedRoomState.h"

using namespace std;

InfestedRoomState::InfestedRoomState() {
}

void InfestedRoomState::goNext(Client* context) {
	context->setState(new ClearedRoomState());
	delete this;
}

std::map<int, pair<TYPES::ACTION_LIST, string>> InfestedRoomState::getCommands() {
	std::map<int, pair<TYPES::ACTION_LIST, string>> commands = std::map<int, pair<TYPES::ACTION_LIST, string>>();
	commands.insert(pair<int, pair<TYPES::ACTION_LIST, string>>(1, pair<TYPES::ACTION_LIST, string>(TYPES::ACTION_LIST::FIGHT, "Fight")));
	commands.insert(pair<int, pair<TYPES::ACTION_LIST, string>>(2, pair<TYPES::ACTION_LIST, string>(TYPES::ACTION_LIST::RUN, "Run")));
	commands.insert(pair<int, pair<TYPES::ACTION_LIST, string>>(3, pair<TYPES::ACTION_LIST, string>(TYPES::ACTION_LIST::VIEW_HERO, "View Hero")));
	commands.insert(pair<int, pair<TYPES::ACTION_LIST, string>>(4, pair<TYPES::ACTION_LIST, string>(TYPES::ACTION_LIST::SEE_BAG, "See Bag")));
	commands.insert(pair<int, pair<TYPES::ACTION_LIST, string>>(5, pair<TYPES::ACTION_LIST, string>(TYPES::ACTION_LIST::VIEW_MAP, "View Map")));
	commands.insert(pair<int, pair<TYPES::ACTION_LIST, string>>(6, pair<TYPES::ACTION_LIST, string>(TYPES::ACTION_LIST::GRANATE, "Granate")));
	return commands;
}

InfestedRoomState::~InfestedRoomState() {
}
