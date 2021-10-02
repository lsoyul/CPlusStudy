#include <iostream>
using namespace std;

// 객체지향 마무리

// 1) struct vs class

// C++에서는 struct나 class나 종이 한 장 차이이다.
// struct는 기본 접근 지정자가 public이고, class는 private 이다.
// 왜 이렇게 했을까? C++은 C언어에서 파생되어 발전했기 때문에? (아마도)
// -> struct는 그냥 구조체 (데이터 묶음)을 표현하는 용도로
// -> class는 객체 지향 프로그래밍의 특징을 나타내는 용도

struct TestStruct
{// public:
	int _a;
	int _b;
};

class TestClass
{// private:
	int _a;
	int _b;
};


// 2) static 변수, static 함수 (static = 정적 = 고정된)

class Marine
{
public:
	// 특정 마린 객체에 종속적
	int _hp;

	void TakeDamage(int damage)
	{
		_hp -= damage;
	}

	static void SetAttack()
	{
		s_attack = 100;
	}

	// 특정 마린 객체와 무관
	// 마린이라는 '클래스' 자체와 연관된 클래스 공통적인 값
	static int s_attack;	// 설계상으로만 존재
};

// static 변수는 어떤 메모리를 사용?
// 초기화를 하면 .data 영역
// 초기화 안하면 .bss 영역
// -> 어쨌든 메모리의 DATA 영역에 올라감

int Marine::s_attack = 0;

int main()
{
	Marine m1;
	m1._hp = 40;
	//m1.s_attack = 6;

	Marine m2;
	m2._hp = 40;
	//m2.s_attack = 6;

	// 마린 공격력 업그레이드 완료! (Academy에서 업그레이드 끝)
	Marine::s_attack = 6;
	Marine::SetAttack();
	//m1.s_attack = 7;
	//m2.s_attack = 7;

	return 0;
}

