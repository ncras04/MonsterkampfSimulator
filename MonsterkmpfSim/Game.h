#pragma once

#include <memory>
#include "Monster.h"

class Game
{

public:

	int round;
	int winner;

	std::shared_ptr<Monster> monster_1, monster_2;
	std::shared_ptr<Monster> order[2];

	int GameInit();
	int GameLoop();
	int GameEnd();

	int SortBattleOrder();

	static int GetNumberInput(int _min, int _max);

};

