#include <iostream>

using namespace std;

// 절차(procedural)지향 프로그래밍
// - procedure = 함수


// 객체지향 프로그래밍

// 데이터 + 가공(로직, 동작)

// class는 일종의 설계도
class Knight
{
public:
	void Move(int y, int x);
	void Attack();

	void Die()
	{
		hp = 0;
		cout << "Die" << endl;
	}

public:
	int hp;
	int attack;
	int posY;
	int posX;
};

void Knight::Move(int y, int x)
{
	posY = y;
	posX = x;
	cout << "Move" << endl;
}

void Move(Knight* knight, int y, int x)
{
	knight->posY = y;
	knight->posX = x;
}

void Knight::Attack()
{
	cout << "Attack : " << attack << endl;
}

struct A {
	int a;
};

int main()
{

	Knight k1;
	k1.hp = 100;
	k1.attack = 10;
	k1.posY = 0;
	k1.posX = 0;

	Knight k2;
	k2.hp = 80;
	k2.attack = 5;
	k2.posY = 1;
	k2.posX = 1;

	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	return 0;
}

