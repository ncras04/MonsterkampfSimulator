#ifndef GAME_H
#define GAME_H

#include "Monster.h"

class Game
{

public:

	int m_round;
	int m_winner;

	std::shared_ptr<Monster> m_monster_1, m_monster_2;
	std::shared_ptr<Monster> m_battleorder[2];

	int GameInit();
	int GameLoop();
	int GameEnd();

private:

	int SortBattleOrder();

	inline bool CheckDrawPossibility()
	{
		return (m_monster_1->GetAttack() <= m_monster_2->GetDefense() &&
				m_monster_2->GetAttack() <= m_monster_1->GetDefense());
	}
};


#endif // !GAME_H

