#include <iostream>
#include "GameDefiner.h"

//place that define the replay function
void Replay()
{
	std::cout << "do you want to play again ? answer [y] for yes or [n] for no\n";
	std::cin >> Play;

	switch (Play)
	{
	case 'y':
		IsPlaying = true;
		break;
	case 'n':
		IsPlaying = false;
		break;
	default:
		std::cout << "you want to do bizarre stuff don't you ... well try again next time\n";
		IsPlaying = true;
	}
}