#ifndef __state__
#define __state__

#include <iostream>
#include <map>
#include <string>

#include "Client.h"
#include "Commands.h"

class State{
	public:
		virtual void goNext(Client* context) { std::cout << "Client::goNext undefined"; };
		virtual std::map<int, std::pair<TYPES::ACTION_LIST, std::string>> getCommands() =0;
		virtual ~State(){};
};

#endif
