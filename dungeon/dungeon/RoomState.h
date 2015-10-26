#ifndef __room_state__
#define __room_state__

#include <iostream>
#include "State.h"

class RoomState : public State
{
public:
	virtual void goNext(Client context) { std::cout << "RoomState::goNext undefined"; };
};

#endif

