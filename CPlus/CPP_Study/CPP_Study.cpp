#include <iostream>
#include <stdlib.h>		// C++ 공식 헤더
using namespace std;
#include "Player.h"		// 우리가 만든 헤더

int main()
{
	// 컴파일러 입장
	// 핵심: Player 는 몇 바이트인가?
	// int 2개 = 2 * 4 = 8바이트

	Player p1;	// 지역 변수 (스택)

	Player* p2 = new Player();	// 동적 할당

	return 0;
}

