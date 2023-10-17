#include <iostream>
#include "ActionsAndChoice.h"
#include "GameDefiner.h"
//main
int main()
{
	int RoundNumber = 1;

	//do while work if you play
	do
	{
		std::cout << "hello player, welcome to this new fighting game\n\n";

		//chose your Monster
		MonsterChoice(Choice1, Choice2);

		//clear the console for the gameplay
		system("cls");

		do
		{
			//setup probability for ennemy monster choices
			SetProbability();

			std::cout << "round number " << RoundNumber << "\n";

			//show stats of monsters
			DisplayStats();

			//system to compare speed and setupp game order
			SpeedTie();

			//in case pary, reset def so it's not unplayable
			ResetDef();

			RoundNumber++;

			//setupp to show who win + prize
			Winner();

		} while (Alive != false);

		//you want to replay?
		Replay();

	} while (IsPlaying == true);
}
