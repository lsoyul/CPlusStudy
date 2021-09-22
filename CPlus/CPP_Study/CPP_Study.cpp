#include <iostream>
using namespace std;

unsigned char flag;	// 부호를 없애야 >> 를 하더라도 부호비트가 같아지지 않음

// 한 번 정해지면 절대 바뀌지 않을 값들
// Constant 의 약자인 const 를 붙임
// const는 초기값을 반드시 지정해주어야 함.

// const도 바뀌지 않는 읽기전용이니까 .rodata?
// 사실 C++ 표준에서 꼭 그렇게 하라는 말이 없음.
// => 컴파일러 (VS) 가 결정한다.
// => 해당 예제에서는 메모리에 저장시키지 않음. 대신 컴파일러가 상수(0~3) 그 자체로 바꿔치기하여 사용함.
const int AIR = 0;
const int STUN = 1;
const int POLYMORPH = 2;
const int INVINCIBLE = 3;

// 전역 변수
// [데이터 영역]
// .data (초기값이 있는 데이터)
int a = 2;

// .bss (초기값이 없는 데이터)
int b;

// .rodata (readonly / 읽기 전용 데이터)
const char* msg = "Hello World";

int main()
{
	// [스택 영역]
	int c = 3;

	// 이놈들은 메모리 스택영역에 만들어짐.
	const int AIR_S = 0;
	const int STUN_S = 1;
	const int POLYMORPH_S = 2;
	const int INVINCIBLE_S = 3;
}
