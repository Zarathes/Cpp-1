#ifndef __infested_room_state__
#define __infested_room_state__

#include "RoomState.h"

class InfestedRoomState : public State {
public:
	InfestedRoomState();
	
	std::map<int, std::pair<TYPES::ACTION_LIST, std::string>> getCommands();

	void goNext(Client* context);

	const char* classname() { return "InfestedRoomState"; }
	~InfestedRoomState();
};

#endif

