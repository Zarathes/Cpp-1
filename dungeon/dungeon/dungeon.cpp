// dungeon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define _CRTDBG_MAP_ALLOC	
#include <stdlib.h>
#include <crtdbg.h>
#include "Game.h"


int _tmain(int argc, _TCHAR* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Game g = Game();
/*Game* trol = new Game();
	delete trol;*/
	return 0;
}

