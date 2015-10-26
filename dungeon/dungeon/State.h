#ifndef __state__
#define __state__

#include <iostream>
#include "Client.h"

class State{
	public:
		virtual void goNext(Client context) { std::cout << "Client::goNext undefined"; };
		virtual ~State(){};
};

#endif
