#ifndef __unvisited_room_state__
#define __unvisited_room_state__

#include "State.h"

class UnvisitedRoomState : public State{
	public:
		UnvisitedRoomState();

		void goNext(Client context);

		~UnvisitedRoomState();
};

#endif

