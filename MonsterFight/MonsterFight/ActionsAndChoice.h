#pragma once
#include <vector>
#include "Monster.h"

//all the variables 
extern int ProbabilityEnnemiMonster;
extern char Play;
extern bool IsPlaying;
extern int ParyRoundsPlayer;
extern int ParyRoundsEnemy;
extern int Choice1;
extern int Choice2;
extern int Choice;
extern bool Alive;
bool IsCrit();

// all the functions
void SpeedTie();
void MonsterChoice(int& Choice1, int& Choice2);
void PlayerChoice(int& Choice);
int IsValid();
void SetProbability();
void RoundOfActions();
void ResetDef();
void DisplayStats();
void Winner();