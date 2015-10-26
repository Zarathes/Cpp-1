#include "stdafx.h"
#include "InfestedRoomState.h"
#include "ClearedRoomState.h"

InfestedRoomState::InfestedRoomState() {
}

void InfestedRoomState::goNext(Client context) {
	context.setState(new ClearedRoomState());
	delete this;
}

InfestedRoomState::~InfestedRoomState() {
}
