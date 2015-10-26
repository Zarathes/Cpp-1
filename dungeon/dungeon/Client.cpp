#include "stdafx.h"
#include "Client.h"
#include "State.h"

Client::Client() : current(nullptr){
}

void Client::goNext(){
	current->goNext(*this);
}

void Client::setState(State *s){
	current = s;
}

Client::~Client(){
}
