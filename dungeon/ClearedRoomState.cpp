#include "stdafx.h"
#include "ClearedRoomState.h"

using namespace std;

ClearedRoomState::ClearedRoomState() {
	cout << "Entering ClearedRoomState" << endl;
}

std::map<int, pair<TYPES::ACTION_LIST, string>> ClearedRoomState::getCommands() {
	std::map<int, pair<TYPES::ACTION_LIST, string>> commands = std::map<int, pair<TYPES::ACTION_LIST, string>>();
	commands.insert(pair<int, pair<TYPES::ACTION_LIST, string>>(1, pair<TYPES::ACTION_LIST, string>(TYPES::ACTION_LIST::REST, "Rest")));
	commands.insert(pair<int, pair<TYPES::ACTION_LIST, string>>(2, pair<TYPES::ACTION_LIST, string>(TYPES::ACTION_LIST::SEE_BAG, "See Bag")));
	commands.insert(pair<int, pair<TYPES::ACTION_LIST, string>>(3, pair<TYPES::ACTION_LIST, string>(TYPES::ACTION_LIST::VIEW_MAP, "View Map")));
	commands.insert(pair<int, pair<TYPES::ACTION_LIST, string>>(4, pair<TYPES::ACTION_LIST, string>(TYPES::ACTION_LIST::VIEW_HERO, "View Hero")));
	commands.insert(pair<int, pair<TYPES::ACTION_LIST, string>>(5, pair<TYPES::ACTION_LIST, string>(TYPES::ACTION_LIST::CHANGE_ROOM, "Change Room")));
	return commands;
}

ClearedRoomState::~ClearedRoomState() {
}
