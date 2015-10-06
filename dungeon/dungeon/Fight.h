#ifndef __fight__
#define __fight__

#include "Hero.h"
#include "Enemy.h"
#include<list>

class Fight{
private:
	Hero hero;
	std::list<Enemy> enemies;
};

#endif