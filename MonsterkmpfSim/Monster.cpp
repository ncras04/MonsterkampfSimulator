#include "Game.h"
#include "Monster.h"

std::shared_ptr<Monster> Monster::CreateMonster(std::string _order)
{
	std::string name;
	EMonstertype type;

	system("cls");

	std::cout << "Waehle einen Namen fuer dein " << _order << " Monster:\n";
	std::getline(std::cin, name);

	
	std::cout << "\nWaehle einen HP Wert:";
	int hp = Game::GetNumberInput(1, 100);

	std::cout << "\nWaehle einen ATK Wert:";
	int atk = Game::GetNumberInput(1, 100);

	std::cout << "\nWaehle einen DEF Wert:";
	int def = Game::GetNumberInput(1, 100);

	std::cout << "\nWaehle einen SPD Wert:";
	int spd = Game::GetNumberInput(1, 100);

	std::cout << "\nWaehle eine Monsterrasse aus: \n1 = Tiger, 2 = Baer, 3 = Kroko, 4 = Pikachu";
	int monstertype = Game::GetNumberInput(1, 4) - 1;
	type = (EMonstertype)monstertype;

	std::cin.get();
	return std::make_shared<Monster>(name, hp, atk, def, spd, type);
}

Monster::Monster(std::string _name, int _hp, int _atk, int _def, int _spd, EMonstertype _type)
{
	m_name = _name;
	m_health = _hp;
	m_attack = _atk;
	m_defense = _def;
	m_speed = _spd;
	m_type = _type;
}

bool Monster::Attack(const std::shared_ptr<Monster>& _defender)
{
	float damage = m_attack - _defender->GetDefense();

	if (damage < 0)
		damage = 0;

	std::cout << "\n";
	std::cout << GetName() << " attackiert " <<
		_defender->GetName() << "!";

	_defender->SetDamage(damage);

	std::cin.get();
	std::cout << "\n";
	std::cout << _defender->GetName() << " verliert " << damage << " HP!";

	std::cin.get();

	return _defender->GetHealth() <= 0;
}
