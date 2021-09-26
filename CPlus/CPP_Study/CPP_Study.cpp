#include <iostream>
using namespace std;

// 참조 전달

struct StatInfo
{
	int hp;			// +0
	int attack;		// +4
	int defence;	// +8
};

// StatInfo 구조체가 1000Bytes 짜리 대형 구조체라면?
// - (값 전달) StatInfo 로 넘기면 1000 bytes가 복사 됨
// - (주소 전달) StatInfo* 로 넘기는 8 bytes
// - (참조 전달) ?

int main()
{
	StatInfo player;
	player.attack = 1;
	player.hp = 2;
	player.defence = 3;

	int number = 2;
	
	int* pointer = &number;
	*pointer = 3;

	// (참조 전달)
	// 로우레벨(어셈블리) 관점에서 실제 작동방식은 int*와 똑같음
	// 실제로 실행해보면 포인터와 100% 똑같다.
	int& reference = number;

	// C++ 관점에서는 number라는 바구니에 또 다른 이름을 부여한 것
	// number라는 바구니에 reference라는 다른 이름을 지어준다.
	// 앞으로 reference 바구니에 뭘 꺼내거나 넣으면,
	// 실제 number 바구니(진짜) 에 그 값을 꺼내거나 넣게 됨.
	reference = 3;

	// 그러면, 귀찮게 또 다른 이름을 짓는 이유는?
	// 그냥 number = 3과 똑같은데..
	// but, 참조 전달 방식의 표현상 편리함 때문!
	ReferenceByRefer(player);

	return 0;
}

// * 참조 전달 방식
// 값 전달처럼 편리하게 사용하고
// 주소 전달처럼 주소값내의 데이터를 수정 할 수 있도록 함
// 일석이조의 방식
void ReferenceByRefer(StatInfo& refer)
{
	refer.attack = 3;
}