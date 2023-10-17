#pragma once
#include <string>
#include <vector>

//class to define the monsters
class Monster
{
	std::string Race;
	int Att;
	int Def;
	int Hp;
	int Speed;

public:
	//constructor of all the monsters
	Monster(std::string _race, int _att, int _def, int _hp, int _speed);


	//different effects that the monsters can do
	int InfflictDamage(Monster& x);
	int Parry();
	int ResetDef();
	int Heal();
	int InflictCritDmg(Monster& y);

	//differents methods to do stuff like refering to a private stat
	void Display();
	int GetDef() { return Def; }
	int GetHp() { return Hp; }
	std::string GetRace() { return Race; }
	int GetSpeed() { return Speed; }
};
