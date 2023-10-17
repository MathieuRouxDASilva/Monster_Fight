#include "Monster.h"
#include <iostream>

//constructor thaat define what is a monster
Monster::Monster(std::string _race, int _att, int _def, int _hp, int _speed)
{
	Race = _race;
	Att = _att;
	Def = _def;
	Hp = _hp;
	Speed = _speed;
}

//method to inflict damage to another monster (reduce his health based on att/def)
int Monster::InfflictDamage(Monster& x)
{
	int Damage = Att - x.Def;
	return x.Hp -= Damage;
}

//method to increase the monster's def stat
int Monster::Parry()
{
	return Def += Def;
}

//method to display all the stats of your monster
void Monster::Display()
{
	std::cout << "-----------------------------\n\n";
	std::cout << "monster type : " << Race << "\n";
	std::cout << Hp << " hp left\n";
	std::cout << Att << " attack\n";
	std::cout << Def << " def\n";
	std::cout << Speed << " speed\n";
	std::cout << "-----------------------------\n\n";
}

//method to reset the def stat of your monster (to make sure that it is not too broken)
int Monster::ResetDef()
{
	return Def -= Def / 2;
}

//method to regen/add at least 5 % of your monster's max health
int Monster::Heal()
{
	int HpValue = 25 * 100 / Hp;
	return Hp += HpValue;
}

//method to calculate a crit attack
int Monster::InflictCritDmg(Monster& y)
{
	return y.Hp -= Att * (15 / 10);
}