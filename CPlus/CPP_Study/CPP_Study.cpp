﻿#include <iostream>
using namespace std;


struct StatInfo
{
	int hp;			// +0
	int attack;		// +4
	int defence;	// +8
};

void EnterLobby();
StatInfo CreatePlayer();
void CreateMonster(StatInfo* info);

int main()
{
	EnterLobby();

	return 0;
}

void EnterLobby()
{
	cout << "로비에 입장했습니다." << endl;

	StatInfo player;
	player.hp = 0xbbbbbbbb;
	player.attack = 0xbbbbbbbb;
	player.defence = 0xbbbbbbbb;
	player = CreatePlayer();	
	// 1. CreatePlayer 함수 -> 스택 내 플레이어 정보 생성
	// 2. 리턴형에 맞춘 임시 데이터 복사 저장
	// 3. 임시 데이터를 다시 player에 복사 저장
	// => 성능적 부하가 큼.


	StatInfo monster;
	monster.hp = 0xbbbbbbbb;
	monster.attack = 0xbbbbbbbb;
	monster.defence = 0xbbbbbbbb;
	CreateMonster(&monster);
}

StatInfo CreatePlayer()
{
	StatInfo ret;

	cout << "플레이어 생성" << endl;

	ret.hp = 100;
	ret.attack = 10;
	ret.defence = 2;

	return ret;
}

void CreateMonster(StatInfo* info)
{
	cout << "몬스터 생성" << endl;

	info->hp = 40;
	info->attack = 8;
	info->defence = 1;
}
