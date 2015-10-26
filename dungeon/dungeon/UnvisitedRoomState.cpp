#include "stdafx.h"
#include "UnvisitedRoomState.h"

#include "InfestedRoomState.h"

UnvisitedRoomState::UnvisitedRoomState(){
}

void UnvisitedRoomState::goNext(Client context) {
	context.setState(new InfestedRoomState());
	delete this;
}

UnvisitedRoomState::~UnvisitedRoomState(){
}
