#include <iostream>
using namespace std;

// 캐스팅 (타입 변환)

// 1) static_cast
// 2) dynamic_cast
// 3) const_cast
// 4) reinterpret_cast

class Player
{
public:
	virtual ~Player() { }
};

class Knight : public Player
{
public:

};

class Archer : public Player
{
public:

};

class Dog
{

};

void PrintName(char* str)
{
	cout << str << endl;
}

void PrintName2(const char* str)
{
	cout << str << endl;
}

int main()
{
	// (int) <= 고전 C 스타일

	// * static_cast : 타입 원칙에 비춰 볼 때, 상식적인 캐스팅만 허용해준다.
	// 1) int <-> float
	// 2) Player* -> Knight*	(부모->자식) 다운캐스팅 << 단, 안전성은 보장 못함!
	// => 사용빈도 가장 높음

	int hp = 100;
	int maxHp = 200;
	float ratio = static_cast<float>(hp) / maxHp;
	cout << ratio << endl;

	// 부모->자식 / 자식->부모
	Player* p = new Archer();
	Knight* k1 = static_cast<Knight*>(p);


	// * dynamic_cast : 상속 관계에서의 안전한 형 변환
	// RTTI (RunTime Type Information) 활용	(런타임에 VF 테이블을 보며 내가 어떤 타입인지? 판단)
	// -> 다형성을 활용하는 방식 (virtual 함수가 최소 한 개는 있어야한다)
	// - virtual 함수를 최소 하나라도 만들면, 객체의 메모리에 가상 함수 테이블 (vftable) 주소가 기입된다.
	// - 만약 잘못된 타입으로 캐스팅을 했으면, nullptr 를 반환한다. 
	// -> 이를 이용해서 맞는 타입으로 캐스팅을 했는지 확인 할 수 있어서 유용하다.
	Knight* k2 = dynamic_cast<Knight*>(p);	// 런타임 에러


	// * const_cast : const를 붙이거나 떼거나~
	PrintName((char*)"Rookiss");	// char*를 받는 함수인데, const를 떼줘야 하는 상황..!
	PrintName(const_cast<char*>("Rookiss"));

	char t[] = "Hello";
	PrintName2(const_cast<const char*>(t));


	// * reinterpret_cast
	// 가장 위험하고 강력한 형태의 캐스팅
	// 're-interpret' : 다시-간주하다/생각하다
	// - 포인터랑 전혀 관계없는 다른 타입으로 변환하고 싶을 때.
	// - 보통 void* 포인터를 캐스팅 해 줄 때 알맞다.
	
	//__int64 address = (__int64)k2;
	__int64 address = reinterpret_cast<__int64>(k2);

	Dog* dog1 = reinterpret_cast<Dog*>(k2);

	void* p = malloc(1000);
	//Dog* dog2 = p;
	Dog* dog = reinterpret_cast<Dog*>(p);


	return 0;
}

