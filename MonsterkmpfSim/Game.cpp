#include "Game.h"

int Game::GameInit()
{
	std::cout << "Welcome to Monsterkampf Simulator!";
	std::cin.get();

	monster_1 = Monster::CreateMonster("erstes");
	monster_2 = Monster::CreateMonster("zweites");

	SortBattleOrder();

	return 0;
}

int Game::GameLoop()
{
	int activePlayer = 0;

	do
	{
		system("cls");
		std::cout << "Runde " << ++round;

		if (order[activePlayer]->Attack(order[1 - activePlayer]))
		{
			winner = activePlayer;
			break;
		}

		activePlayer = 1 - activePlayer;

	} while (true);

	return 0;

}

int Game::GameEnd()
{
	std::cout << "\n";
	std::cout << order[winner]->GetName() << " hat innerhalb "
			<< round << " Runden gewonnen!";

	return 0;
}

int Game::SortBattleOrder()
{
	if (monster_1->GetSpeed() >= monster_2->GetSpeed())
	{
		order[0] = monster_1;
		order[1] = monster_2;
	}
	else
	{
		order[0] = monster_2;
		order[1] = monster_1;
	}

	return 0;
}

int Game::GetNumberInput(int _min, int _max)
{
	int input = 0;

	do
	{
		std::cout << "\nWaehle eine Nummer zwischen " << _min << " und " << _max << "\n";

		std::cin >> input;

		if (input >= _min && input <= _max)
			return input;
		else
			std::cout << "Eingabe ist ungueltig.";

	} while (true);
}
