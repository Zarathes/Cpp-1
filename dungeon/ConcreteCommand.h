#include "stdafx.h"
#include "Command.h"

class FightCommand : public Command
{
public:
	FightCommand(Reciever *reciever)
		: Command(reciever, "Fight")
	{

	}

	void Execute()
	{
		reciever->SetCommand(TYPES::ACTION_LIST::FIGHT);
		reciever->Execute();
	}
};	

class RunCommand : public Command
{
public:
	RunCommand(Reciever *reciever)
		: Command(reciever, "Run")
	{

	}

	void Execute()
	{
		reciever->SetCommand(TYPES::ACTION_LIST::RUN);
		reciever->Execute();
	}
};

class GetItemsCommand : public Command
{
public:
	GetItemsCommand(Reciever *reciever)
		: Command(reciever, "Get Items")
	{

	}

	void Execute()
	{
		reciever->SetCommand(TYPES::ACTION_LIST::GET_ITEMS);
		reciever->Execute();
	}
};

class SeeBagCommand : public Command
{
public:
	SeeBagCommand(Reciever *reciever)
		: Command(reciever, "See Bag")
	{

	}

	void Execute()
	{
		reciever->SetCommand(TYPES::ACTION_LIST::SEE_BAG);
		reciever->Execute();
	}
};

class RestCommand : public Command
{
public:
	RestCommand(Reciever *reciever)
		: Command(reciever, "Rest")
	{

	}

	void Execute()
	{
		reciever->SetCommand(TYPES::ACTION_LIST::REST);
		reciever->Execute();
	}
};

class ViewMapCommand : public Command
{
public:
	ViewMapCommand(Reciever *reciever)
		: Command(reciever, "View Map")
	{

	}

	void Execute()
	{
		reciever->SetCommand(TYPES::ACTION_LIST::VIEW_MAP);
		reciever->Execute();
	}
};

class ViewHeroCommand : public Command
{
public:
	ViewHeroCommand(Reciever *reciever)
		: Command(reciever, "View Hero")
	{

	}

	void Execute()
	{
		reciever->SetCommand(TYPES::ACTION_LIST::VIEW_HERO);
		reciever->Execute();
	}
};

class ChangeRoomCommand : public Command
{
public:
	ChangeRoomCommand(Reciever *reciever)
		: Command(reciever, "Change Room")
	{

	}

	void Execute()
	{
		reciever->SetCommand(TYPES::ACTION_LIST::CHANGE_ROOM);
		reciever->Execute();
	}
};

class TalismanCommand : public Command
{
public:
	TalismanCommand(Reciever *reciever)
		: Command(reciever, "Change Room")
	{

	}

	void Execute()
	{
		reciever->SetCommand(TYPES::ACTION_LIST::TALISMAN);
		reciever->Execute();
	}
};

class GranateCommand : public Command
{
public:
	GranateCommand(Reciever *reciever)
		: Command(reciever, "Change Room")
	{

	}

	void Execute()
	{
		reciever->SetCommand(TYPES::ACTION_LIST::GRANATE);
		reciever->Execute();
	}
};

class CompassCommand : public Command
{
public:
	CompassCommand(Reciever *reciever)
		: Command(reciever, "Change Room")
	{

	}

	void Execute()
	{
		reciever->SetCommand(TYPES::ACTION_LIST::COMPASS);
		reciever->Execute();
	}
};