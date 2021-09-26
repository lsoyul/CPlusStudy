#include <iostream>
using namespace std;

// 배열

struct StatInfo
{
	int hp = 0xAAAAAAAA;
	int attack = 0xBBBBBBBB;
	int defence = 0xDDDDDDDD;
};

int main()
{
	// TYPE 이름[갯수];
	
	// 배열의 크기는 상수여야 한다. (VS 컴파일러 기준)
	const int monsterCount = 10;
	StatInfo monsters[monsterCount];

	// 여태껏 변수들의 [이름]은 바구니의 이름이었음.
	int a = 10;
	a = 3;
	int b = a;

	// 그런데 배열은 [이름]이 조금 다르게 동작한다.
	StatInfo players[10];
	//players = monsters;

	// 그러면 배열의 [이름]이란?
	// 배열의 이름은 곧 배열의 시작 주소이다.
	// 정확하게는 시작 위치를 가리키는 TYPE* 포인터
	auto WhoAmI = monsters;

	// StatInfo[ ] StatInfo[ ] StatInfo[ ] StatInfo[ ] ...
	StatInfo* monster_0 = monsters;
	monster_0->hp = 100;
	monster_0->attack = 10;
	monster_0->defence = 1;

	// 포인터의 덧셈 -> StatInfo 크기만큼 이동해라
	StatInfo* monster_1 = monsters + 1;
	monster_1->hp = 200;
	monster_1->attack = 20;
	monster_1->defence = 2;

	// 포인터와 참조는 자유자재로 변환 가능하다.
	StatInfo& monster_2 = *(monsters + 2);
	monster_2.hp = 300;
	monster_2.attack = 30;
	monster_2.defence = 3;

	// [주의] 이건 완전 다른 의미이다.
	StatInfo temp = *(monsters + 2);	// 내용물의 StatInfo 값 을 temp에 복사
	temp.hp = 300;
	temp.attack = 30;
	temp.defence = 3;

	// 이를 조금 더 자동화 한다.
	for (int i = 0; i < monsterCount; i++)
	{
		StatInfo& monster = *(monsters + i);	
		monster.hp = 100 * (i + 1);
		monster.attack = 10 * (i + 1);
		monster.defence = (i + 1);
	}

	// 근데 *(monsters + i) 너무 불편하고 가독성이 떨어진다..
	// 인덱스!
	// 배열은 0부터 시작, N번째 인덱스에 해당하는 데이터에 접근하려면 배열이름[N]
	// *(monsters + i) ==> monsters[i]

	for (int i = 0; i < monsterCount; i++)
	{
		monsters[i].hp = 100 * (i + 1);
		monsters[i].attack = 10 * (i + 1);
		monsters[i].defence = (i + 1);
	}

	// 배열 초기화 문법 몇가지
	int numbers[5] = {};						// 0으로 초기화 (어셈에서 보면 그냥 모든 값들을 여러번 0으로 복사)
	int numbers1[10] = { 1, 2, 3, 4, 5 };		// 설정한 값 뒤 부터는 0으로 초기화
	int numbers2[] = { 1,2,3,4,5,6,3,1,2 };		// 데이터 갯수만큼의 크기에 해당하는 배열로 만들어 준다.

	char helloStr[] = { 'H', 'e', 'l', 'l', 'o', '\0'};
	cout << helloStr << endl;

	// 배열 요약:
	// 1) 선언한다.
	int arr[10] = {};

	// 2) 인덱스로 접근해서 사용
	arr[1] = 1;
	cout << arr[1] << endl;
	
	return 0;
}

