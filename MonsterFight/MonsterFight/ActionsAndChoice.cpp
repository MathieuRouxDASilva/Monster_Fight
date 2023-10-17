#include "ActionsAndChoice.h"
#include <iostream>
#include <random>

//variables + monster define
#pragma region Variables
int ProbabilityEnnemiMonster;
int Choice1;
int Choice2;
int Choice;
bool Alive = true;
int ParyRoundsPlayer = 0;
int ParyRoundsEnemy = 0;
char Play;
bool IsPlaying = true;
#pragma endregion
#pragma region MonsterCreation
std::vector<Monster> PlayableMonster
{
	Monster {"orc", 20, 15, 500, 2 },
	Monster { "gobelin", 40, 1, 340, 50 },
	Monster { "troll", 60, 18, 200, 20 },
	Monster { "secret powerfull dragon", 60, 18, 500, 51 },
};

Monster MonsterSelectedPlayer = PlayableMonster.at(Choice1);
Monster MonsterSelectedEnemy = PlayableMonster.at(Choice2);
#pragma endregion

//function to setprobability for the ennemy choice
void SetProbability()
{
	srand(time(NULL));

	ProbabilityEnnemiMonster = rand() % 6;
}

//function to reset the def stat
void ResetDef()
{
	if (ParyRoundsEnemy == 1)
	{
		MonsterSelectedEnemy.ResetDef();
		ParyRoundsEnemy = 0;
	}

	if (ParyRoundsPlayer == 1)
	{
		MonsterSelectedPlayer.ResetDef();
		ParyRoundsPlayer = 0;
	}
}

//function to display monsters stats
void DisplayStats()
{
	std::cout << "your stats :\n";
	MonsterSelectedPlayer.Display();
	std::cout << "enemy stats :\n";
	MonsterSelectedEnemy.Display();
}

//function to setupp who win
void Winner()
{
	if (MonsterSelectedEnemy.GetHp() <= 0)
	{
		std::cout << MonsterSelectedPlayer.GetRace() << " wins\n";
		std::cout << "you've unlock a new character, reload the programm and chose [3]\n\n";
		Alive = false;
	}
	else if (MonsterSelectedPlayer.GetHp() <= 0)
	{
		std::cout << MonsterSelectedEnemy.GetRace() << " wins\n";
		Alive = false;
	}
}

//function to set who hit first
void SpeedTie()
{
	if (MonsterSelectedPlayer.GetSpeed() >= MonsterSelectedEnemy.GetSpeed())
	{
		PlayerChoice(Choice);
		IsCrit();
		switch (Choice)
		{
		case 1:
			std::cout << MonsterSelectedPlayer.GetRace() << " parry\n\n";
			MonsterSelectedPlayer.Parry();
			ParyRoundsPlayer++;
			break;
		case 2:
			std::cout << MonsterSelectedPlayer.GetRace() << " heal\n\n";
			MonsterSelectedPlayer.Heal();
			break;
		case 0:
			std::cout << MonsterSelectedPlayer.GetRace() << " attack\n\n";

			if (IsCrit() == true)
			{
				MonsterSelectedPlayer.InflictCritDmg(MonsterSelectedEnemy);
				std::cout << MonsterSelectedPlayer.GetRace() << " did crit damage wow !!!\n\n";
			}
			else
			{
				MonsterSelectedPlayer.InfflictDamage(MonsterSelectedEnemy);
				std::cout << MonsterSelectedPlayer.GetRace() << " attack\n\n";
			}
			break;
		default:
			std::cout << "i'm sorry, i can't understand your choice\n";
			break;
		}

		IsCrit();
		switch (ProbabilityEnnemiMonster)
		{
		case 0:
			std::cout << MonsterSelectedEnemy.GetRace() << " parry\n\n";
			MonsterSelectedEnemy.Parry();
			ParyRoundsEnemy++;
			break;
		case 1:
			std::cout << MonsterSelectedEnemy.GetRace() << " parry\n\n";
			MonsterSelectedEnemy.Parry();
			ParyRoundsEnemy++;
			break;
		case 2:
			if (IsCrit() == true)
			{
				MonsterSelectedEnemy.InflictCritDmg(MonsterSelectedPlayer);
				std::cout << MonsterSelectedEnemy.GetRace() << " did crit damage wow !!!\n\n";
			}
			else
			{
				MonsterSelectedEnemy.InfflictDamage(MonsterSelectedPlayer);
				std::cout << MonsterSelectedEnemy.GetRace() << " attack\n\n";
			}
			break;
		case 3:
			if (IsCrit() == true)
			{
				MonsterSelectedEnemy.InflictCritDmg(MonsterSelectedPlayer);
				std::cout << MonsterSelectedEnemy.GetRace() << " did crit damage wow !!!\n\n";
			}
			else
			{
				MonsterSelectedEnemy.InfflictDamage(MonsterSelectedPlayer);
				std::cout << MonsterSelectedEnemy.GetRace() << " attack\n\n";
			}
			break;
		case 4:
			if (IsCrit() == true)
			{
				MonsterSelectedEnemy.InflictCritDmg(MonsterSelectedPlayer);
				std::cout << MonsterSelectedEnemy.GetRace() << " did crit damage wow !!!\n\n";
			}
			else
			{
				MonsterSelectedEnemy.InfflictDamage(MonsterSelectedPlayer);
				std::cout << MonsterSelectedEnemy.GetRace() << " attack\n\n";
			}
			break;
		case 5:
			std::cout << MonsterSelectedEnemy.GetRace() << " heal\n\n";
			MonsterSelectedEnemy.Heal();
			break;
		}
	}
	else if (MonsterSelectedPlayer.GetSpeed() <= MonsterSelectedEnemy.GetSpeed())
	{
		IsCrit();
		switch (ProbabilityEnnemiMonster)
		{
		case 0:
			std::cout << MonsterSelectedEnemy.GetRace() << " parry\n\n";
			MonsterSelectedEnemy.Parry();
			ParyRoundsEnemy++;
			break;
		case 1:
			std::cout << MonsterSelectedEnemy.GetRace() << " parry\n\n";
			MonsterSelectedEnemy.Parry();
			ParyRoundsEnemy++;
			break;
		case 2:
			if (IsCrit() == true)
			{
				MonsterSelectedEnemy.InflictCritDmg(MonsterSelectedPlayer);
				std::cout << MonsterSelectedEnemy.GetRace() << " did crit damage wow !!!\n\n";
			}
			else
			{
				MonsterSelectedEnemy.InfflictDamage(MonsterSelectedPlayer);
				std::cout << MonsterSelectedEnemy.GetRace() << " attack\n\n";
			}
			break;
		case 3:
			if (IsCrit() == true)
			{
				MonsterSelectedEnemy.InflictCritDmg(MonsterSelectedPlayer);
				std::cout << MonsterSelectedEnemy.GetRace() << " did crit damage wow !!!\n\n";
			}
			else
			{
				MonsterSelectedEnemy.InfflictDamage(MonsterSelectedPlayer);
				std::cout << MonsterSelectedEnemy.GetRace() << " attack\n\n";
			}
			break;
		case 4:
			if (IsCrit() == true)
			{
				MonsterSelectedEnemy.InflictCritDmg(MonsterSelectedPlayer);
				std::cout << MonsterSelectedEnemy.GetRace() << " did crit damage wow !!!\n\n";
			}
			else
			{
				MonsterSelectedEnemy.InfflictDamage(MonsterSelectedPlayer);
				std::cout << MonsterSelectedEnemy.GetRace() << " attack\n\n";
			}
			break;
		case 5:
			std::cout << MonsterSelectedEnemy.GetRace() << " heal\n\n";
			MonsterSelectedEnemy.Heal();
			break;
		}

		PlayerChoice(Choice);
		IsCrit();
		switch (Choice)
		{
		case 1:
			std::cout << MonsterSelectedPlayer.GetRace() << " parry\n\n";
			MonsterSelectedPlayer.Parry();
			ParyRoundsPlayer++;
			break;
		case 2:
			std::cout << MonsterSelectedPlayer.GetRace() << " heal\n\n";
			MonsterSelectedPlayer.Heal();
			break;
		case 0:
			if (IsCrit() == true)
			{
				MonsterSelectedPlayer.InflictCritDmg(MonsterSelectedEnemy);
				std::cout << MonsterSelectedPlayer.GetRace() << " did crit damage wow !!!\n\n";
			}
			else
			{
				MonsterSelectedPlayer.InfflictDamage(MonsterSelectedEnemy);
				std::cout << MonsterSelectedPlayer.GetRace() << " attack \n\n";
			}
			break;
		default:
			std::cout << "i'm sorry, i can't understand your choice\n";
			break;
		}
	}
}

//function to set which monster you chose for you and your enemy
void MonsterChoice(int& Choice1, int& Choice2)
{
	std::cout << "who is the first fighter ?\n\n";
	std::cout << "type in [0] for Roger the orc, [1] for Patrick the gobelin, [2] for Francois the troll ?\n\n";
	Choice1 = IsValid();

	std::cout << "who is the secound fighter ?\n\n";
	std::cout << "type in [0] for Roger the orc, [1] for Patrick the gobelin, [2] for Francois the troll ?\n\n";
	Choice2 = IsValid();
}

//function to choose wich action you want to do
void PlayerChoice(int& Choice)
{
	std::cout << "what move do you want to do ?\n\n";
	std::cout <<" type in [0] to attack and deal damage\n";
	std::cout << "type in [1] to pary and to buff your defense stat for one turn\n";
	std::cout << "type in [2] to heal yourself a bit of hp\n";
	Choice = IsValid();
}

//function to make sure the player input is a digit
int IsValid()
{
	bool isValidInput = true;
	int result = -1;

	std::string inputString;
	do
	{
		std::getline(std::cin, inputString);

		isValidInput = true;
		for (char inputChar : inputString)
		{
			if (!isdigit(inputChar))
			{
				// not valid input -----------------
				std::cout << "[" << inputChar << "] is not a number" << std::endl;
				isValidInput = false;
				break;
			}
		}

		if (isValidInput)
		{
			std::string value = inputString.substr(0, 10);

			result = std::stoi(inputString);

			std::cout << "Your answer is: " << result << "\n";
			break;
		}
	} while (!isValidInput);
	return result;
}

//bool that define if you crit or not
bool IsCrit()
{
	srand(time(NULL));
	int Probability = rand() % 16;

	switch (Probability)
	{
	case 0:
		return true;
		break;
	default:
		return false;
		break;
	}
}