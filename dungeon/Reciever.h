#ifndef __reciever__
#define __reciever__

#include "Commands.h"

class Reciever {
public:
	virtual void SetCommand(TYPES::ACTION_LIST command) =0;
	virtual void Execute() =0;
};

#endif