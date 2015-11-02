#ifndef __unvisited_room_state__
#define __unvisited_room_state__

#include "RoomState.h"

class UnvisitedRoomState : public State{
public:
	UnvisitedRoomState();

	void goNext(Client* context);
	std::map<int, std::pair<TYPES::ACTION_LIST, std::string>> getCommands();

	~UnvisitedRoomState();

};

#endif

