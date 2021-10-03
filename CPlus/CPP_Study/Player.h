#pragma once
//#include "Monster.h"

// class는 설계도
class Player
{
public:
	void KillMonster();
	

public:
	int _hp;
	int _attack;

	//Monster _target;
	class Monster* _target2;
};

