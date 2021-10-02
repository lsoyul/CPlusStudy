#include <iostream>
using namespace std;

// 연산자 오버로딩 (Operator Overloading)

// 연산자 vs 함수
// - 연산자는 피연산자의 갯수/타입이 고정되어 있음

// 연산자 오버로딩?
// 일단 [연산자 함수]를 정의해야 함
// 함수도 멤버함수 vs 전역함수가 존재하는 것 처럼, 연산자도 두가지 방식으로 만들 수 있음.

// - 멤버 연산자 함수 version
// -- a op b 형태에서 왼쪽을 기준으로 실행 (a가 특정 클래스여야 가능.)
// -- a를 '기준 피연산자' 라고 함.
// -- 한계) a가 클래스가 아니면 사용하지 못함

// - 전역 연산자 함수 version
// -- a op b 형태라면 a, b 모두를 연산자 함수의 피연산자로 만들어준다.


// 그럼 무엇이 더 좋은건가? 그런거는 없다. 둘 중 하나만 지원하는 버전도 있음.
// - 대표적으로 대입 연산자 (a = b)는 전역 연산자 version으로는 못만든다. (문법적으로 막아놓음)

// 복사 대입 연산자
// - 대입 연산자가 나온 김에 [복사 대입 연산자]에 대해 알아보자.
// 용어가 좀 헷갈린다 [복사 생성자] [대입 연산자] [복사 대입 연산자]
// - 복사 대입 연산자 = 대입 연사자인데 자기 자신의 참조타입을 인자로 받는 것.

class Position
{
public:

	//RET FUNC_NAME(ARG_LIST)
	//{
	//
	//}
	Position operator+(const Position& arg)
	{
		Position pos;
		pos._x = _x + arg._x;
		pos._y = _y + arg._y;

		return pos;
	}

	Position operator+(int arg)
	{
		Position pos;
		pos._x = _x + arg;
		pos._y = _y + arg;

		return pos;
	}

	bool operator==(const Position& arg)
	{
		return _x == arg._x && _y == arg._y;
	}

	Position& operator=(int arg)
	{
		_x = arg;
		_y = arg;

		//Position* this = 내 자신의 주소;
		return *this;
	}

	// 복사 대입 연산자
	// [복사 생성자] [복사 대입 연산자] 등이 특별히 대우를 받는 이유는
	// 말 그래도 객체가 '복사'되길 원하는 특징 때문이다.
	// => 컴파일러가 기본적으로 생성해주는 특징이 있음.
	// TODO ) 동적할당 시간에 더 자세히 알아볼 것.

	// 기타
	// - 모든 연산자를 다 오버로딩 할 수 있는것은 아니다. (:: . .* 이런것은 안됨)
	// - 모든 연산자가 다 2개 항이 있는 것이 아님. ++ -- 가 대표적 (단한 연산자)
	// - 증감 연산자 ++ --
	// -- 전위형 (++a) operator++()
	// -- 후위형 (a++) operator++(int)

	Position& operator=(const Position& arg)
	{
		_x = arg._x;
		_y = arg._y;

		//Position* this = 내 자신의 주소;
		return *this;
	}

	// ++전위형
	Position& operator++()
	{
		_x++;
		_y++;
	}

	// 후위형++
	Position operator++(int)
	{
		Position ret = *this;
		_x++;
		_y++;
		return ret;
	}

public:
	int _x;
	int _y;
};

// - 전역 연산자 버전
Position operator+(int a, const Position& b)
{
	Position ret;
	ret._x = b._x + a;
	ret._y = b._y + a;

	return ret;
}


int main()
{
	int a = 1;
	int b = 2;
	int c = a + b;

	Position pos;
	pos._x = 0;
	pos._y = 0;

	Position pos2;
	pos2._x = 1;
	pos2._y = 1;

	Position pos3 = pos + pos2;
	// pos3 = pos.operator+(pos2);
	Position pos4 = pos3 + 1;
	// pos4 = pos.operator(1);
	// Position pos4 = 1 + pos3; <= 멤버연산자로는 불가능
	Position pos5 = 1 + pos3;

	bool isSame = (pos3 == pos4);

	pos5 = pos3++;

	return 0;
}

