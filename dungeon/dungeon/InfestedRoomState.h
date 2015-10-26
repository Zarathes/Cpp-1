#ifndef __infested_room_state__
#define __infested_room_state__

#include "State.h"

class InfestedRoomState : public State {
public:
	InfestedRoomState();

	void goNext(Client context);

	~InfestedRoomState();
};

#endif

