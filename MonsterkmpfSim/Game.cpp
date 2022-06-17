#include "Game.h"

int Game::GameInit()
{
	std::cout << "Welcome to Monsterkampf Simulator!";
	std::cin.get();

	m_monster_1 = Monster::CreateMonster("erstes");
	m_monster_2 = Monster::CreateMonster("zweites");

	SortBattleOrder();

	return 0;
}

int Game::GameLoop()
{
	int activePlayer = 0;

	do
	{
		system("cls");
		std::cout << "< Runde " << ++m_round << " >\n";
		std::cout << m_monster_1->GetName() << ": " << m_monster_1->GetHealth() << " HP\n";
		std::cout << m_monster_2->GetName() << ": " << m_monster_2->GetHealth() << " HP\n";


		if (m_battleorder[activePlayer]->Attack(m_battleorder[1 - activePlayer]))
		{
			m_winner = activePlayer;
			break;
		}

		activePlayer = 1 - activePlayer;

	} while (true);

	return 0;

}

int Game::GameEnd()
{
	std::cout << "\n";
	std::cout << m_battleorder[m_winner]->GetName() << " hat innerhalb "
		<< m_round << " Runden gewonnen!";

	return 0;
}

int Game::SortBattleOrder()
{
	if (m_monster_1->GetSpeed() >= m_monster_2->GetSpeed())
	{
		m_battleorder[0] = m_monster_1;
		m_battleorder[1] = m_monster_2;
	}
	else
	{
		m_battleorder[0] = m_monster_2;
		m_battleorder[1] = m_monster_1;
	}

	return 0;
}

int Game::GetNumberInput(int _min, int _max)
{
	int input;
	std::string strInput;
	char* p;

	do
	{
		std::cout << "\nWaehle eine Nummer zwischen " << _min << " und " << _max << "\n";
		std::getline(std::cin, strInput);
		input = strtol(strInput.c_str(), &p, 10);

		if (*p)
			std::cout << "Deine Eingabe ist keine gueltige Zahl!";
		else if (input < _min || input > _max)
			std::cout << "Deine Eingabe ist ungueltig.";
		else
			return input;


	} while (true);

	return 0;
}

std::string Game::GetStringInput()
{
	std::string _input;

	std::getline(std::cin, _input);

	while (_input == "")
	{
		std::cout << "Deine Eingabe ist ungueltig.\n";
		std::cout << "Bitte gib einen gueltigen Namen ein:\n";
		std::getline(std::cin, _input);
	}

	return _input;
}
