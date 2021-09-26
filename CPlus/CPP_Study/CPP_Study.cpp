#include <iostream>
using namespace std;

// 포인터 연산

// 1) 주소 연산자 (&)
// 2) 산술 연산자
// 3) 간접 연산자
// 4) 간접 멤버 연산자

struct Player
{					// memory offset
	int hp;			// +0
	int damage;		// +4
};

int main()
{
	int number = 1;

	// 1) 주소 연산자 (&)
	// - 해당 변수의 주소를 알려주세요
	// - 정확하게는 
	// 해당 타입의 포인터형으로 변환해주는 과정까지 포함됨 TYPE* 반환

	int* pointer = &number;

	// 2) 산술 연산자 (+ -)
	number += 1;	// 1 증가
	pointer += 1;	// 4 증가 (한번에 TYPE의 크기만큼을 이동함)
					// -> 다음 바구니로 이동해라 의미

	// 3) 간접 연산자 (*)
	// - 해당 주소로 이동
	*pointer = 3;

	Player player;
	player.hp = 100;		
	player.damage = 10;		

	Player* playerPtr = &player;

	(*playerPtr).hp = 200;
	(*playerPtr).damage = 200;

	// 4) 간접 멤버 연산자 (->)
	// * 간접연산자는 포탈을 타고 해당 주소로 직접 이동한다는 의미
	// . 구조체의 특정 멤버를 다룰 때 사용 (어셈블리에서는 단순히 . 사실상 offset을 기준으로 한 덧셈)
	// -> 는 * 와 . 한번에 실행하는 개념
	playerPtr->hp = 200;
	playerPtr->damage = 200;
}