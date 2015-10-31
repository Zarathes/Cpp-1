#ifndef __command__
#define __command__

#include "Reciever.h"
#include <string>

class Command
{
protected:
	Reciever *reciever;
	char description;

public:
	Command(Reciever *reciever, std::string description)
		:reciever(reciever)
	{
	}

	virtual void Execute() = 0;
};

#endif