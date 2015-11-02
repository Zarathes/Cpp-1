#ifndef __cleared_room_state__
#define __cleared_room_state__

#include "RoomState.h"

class ClearedRoomState : public RoomState {
public:
	ClearedRoomState();

	std::map<int, std::pair<TYPES::ACTION_LIST, std::string>> getCommands();

	~ClearedRoomState();
};

#endif

