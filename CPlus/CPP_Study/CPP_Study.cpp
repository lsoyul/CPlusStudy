#include <iostream>
using namespace std;

// 함수 포인터

class Knight
{
public:

	static void HelloKnight()
	{

	}

	int GetHp(int, int)
	{
		cout << "GetHp()" << endl;
		return _hp;
	}

public:
	int _hp = 100;
};


// typedef의 진실
// typedef 왼쪽 오른쪽 -> 오른쪽 (커스텀 타입 정의)

//typedef int NUMBER;

// 정확히는 왼쪽/오른쪽 기준이 아니라,
// [선언 문법]에서 typedef를 앞에다 붙이는 쪽.

typedef int INTEGER;
typedef int* POINTER;
typedef int FUNC(int, int);
typedef int ARRAY[20];

typedef int (*PFUNC)(int, int);					// 정적/전역 함수 포인터

typedef int (Knight::*PMEMFUNC)(int, int);		// 멤버 함수 포인터

int Test(int a, int b)
{
	cout << "Test" << endl;
	return a + b;
}


int main()
{
	// 함수 포인터
	// 1) 포인터			*
	// 2) 변수의 이름	fn
	// 3) 타입			함수

	//FUNC t;
	//t(1, 2);	// 구현부 없는 함수 호출상황이랑 같음

	//int (*fn)(int, int);
	//FUNC* fn;
	PFUNC fn;

	//typedef int(FUNC_TYPE)(int, int);
	//FUNC_TYPE* fn;

	fn = &Test;
	//fn = Test;	&생략 가능 (C언어 호환성 때문)

	fn(1, 2);

	(*fn)(1, 2);


	// 위 문법으로 [전역(global) 함수 / 정적(static) 함수] 만 담을 수 있다. (호출 규약이 동일한 애들)
	
	Knight k1;
	k1.GetHp(1, 1);

	//fn = &Knight::GetHp;

	PMEMFUNC mfn;
	mfn = &Knight::GetHp;

	(k1.*mfn)(1, 1);

	// => 멤버 함수 포인터는 *, & 구분을 잘 해주어야 한다.

	Knight* k2 = new Knight();

	((*k2).*mfn)(1, 1);
	(k2->*mfn)(1, 1);

	delete k2;

	return 0;
}

