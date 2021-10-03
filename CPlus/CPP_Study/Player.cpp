#include "Player.h"
#include "Monster.h"

void Player::KillMonster()
{
	_target2->_hp = 0;
	(*_target2)._hp = 0;

	_target2->KillMe();
}