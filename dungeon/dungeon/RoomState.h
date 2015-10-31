#ifndef __room_state__
#define __room_state__

#include <iostream>
#include <map>

#include "State.h"
#include "Commands.h"

class RoomState : public State
{
public:
	virtual std::map<int, std::pair<TYPES::ACTION_LIST, std::string>> getCommands() = 0;
	virtual void goNext(Client* context) { std::cout << "RoomState::goNext undefined"; };
};

#endif

