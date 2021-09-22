﻿#include <iostream>
using namespace std;

unsigned char flag;	// 부호를 없애야 >> 를 하더라도 부호비트가 같아지지 않음

int main()
{
#pragma region 비트 연산
	// 언제 필요한가?
	// 비트 단위의 조작이 필요 할 때,

	// ~ bitwise NOT
	// 단일 숫자의 모든 비트를 뒤집는다

	// & bitwise AND
	// 두 숫자의 모든 비트를 AND 연산 한다

	// | bitwise OR
	// 두 숫자의 모든 비트를 OR 연산 한다

	// ^ bitwise XOR
	// 두 숫자의 모든 비트를 XOR 연산 한다
	// (암호학에서 유용하게 사용)

	// << 비트 좌측 이동
	// 비트열을 N만큼 왼쪽 으로 이동
	// 이동하며 범위가 넘어서는 비트는 버린다. (새로 생성되는 비트는 0)
	// *2를 할 때, 자주 보임 (컴파일러가 자주 사용하는 방식)

	// >> 비트 우측 이동
	// 비트열을 N만큼 오른쪽 으로 이동
	// 이동하며 범위가 넘어서는 비트는 버린다.
	// (*)왼쪽에서 새로 생성되는 비트는 그때그때 다름
	// => 만약 부호 비트가 존재 할 시, 부호비트를 따라감. (부호있는 정수라면 이 부분을 유의)
	// => 부호가 없다면 0이라고 생각하면 됨.

	// EX)
	// 0b0000 [무적][변이][스턴][공중부양]

	// 무적 상태로 만든다.
	flag = (1 << 3);	// 8

	// 변이 상태를 추가한다. (무적 + 변이)
	flag |= (1 << 2);

	// 무적인지 확인하고 싶다.
	// bitmask
	bool invincible = ((flag & (1 << 3)) != 0);

	// 무적이거나 스턴상태인지 확인하고 싶다.
	bool mask = (1 << 3) | (1 << 1);
	bool stunAndInvincible = ((flag & 0b1010) != 0);

#pragma endregion

}
