#include "stdafx.h"
#include "Client.h"
#include "State.h"

Client::Client() : currentState(nullptr){
}

void Client::goNext(){
	currentState->goNext(this);
}

void Client::setState(State *s){
	currentState = s;
}

State* Client::getState(){
	return currentState;
}

Client::~Client(){
}
