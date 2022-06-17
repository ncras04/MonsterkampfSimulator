#ifndef MONSTER_H
#define MONSTER_H

#include "Monstertype.h"
#include <iostream>
#include <string>
#include <memory>

class Monster
{

public:

	inline int GetHealth() { return m_health; }
	inline int GetAttack() { return m_attack; }
	inline int GetDefense() { return m_defense; }
	inline int GetSpeed() { return m_speed; }
	inline EMonstertype GetType() { return m_type; }

	inline std::string GetName()
	{
		switch (m_type)
		{
		case EMonstertype::TIGER:
			return "Tiger " + m_name;
		case EMonstertype::BEAR:
			return "Baer " + m_name;
		case EMonstertype::CROC:
			return "Kroko " + m_name;
		case EMonstertype::PIKACHU:
			return "Pikachu " + m_name;
		default:
			return m_name;
		}
	}

	inline void SetDamage(int _damage) { m_health -= _damage; }

	static std::shared_ptr<Monster> CreateMonster(std::string _order);
	Monster(std::string _name, int _hp, int _atk, int _def, int _spd, EMonstertype _type);

	bool Attack(const std::shared_ptr<Monster>& _defender);

private:

	std::string m_name;
	int m_health;
	int m_attack;
	int m_defense;
	int m_speed;
	EMonstertype m_type;
};

#endif //MONSTER_H

