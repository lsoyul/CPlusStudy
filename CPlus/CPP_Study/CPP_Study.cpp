#include <iostream>
using namespace std;

// 함수 포인터

int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

class Item
{
public:
	Item() : _itemId(0), _rarity(0), _ownerId(0)
	{

	}

public:
	int _itemId;	// 아이템을 구분하기 위함 ID
	int _rarity;	// 희귀도
	int _ownerId;	// 소지자 ID
};

typedef bool(ITEM_SELECTOR)(Item*, int);

//Item* FindItem(Item items[], int itemCount, bool(*selector)(Item* item))
Item* FindItem(Item items[], int itemCount, ITEM_SELECTOR* selector, int value)
{


	for (int i = 0; i < itemCount; i++)
	{
		Item* item = &items[i];
		
		if (selector(item, value)) return item;
	}

	return nullptr;
}

bool IsRareItem(Item* item, int value)
{
	return (item->_rarity >= value);
}

bool IsOwnerITem(Item* item, int ownerId)
{
	return (item->_ownerId == ownerId);
}

int main()
{
	int a = 10;

	// 바구니 주소
	// pointer[ 주소 ]	->	주소[	]

	typedef int DATA;

	// 1) 포인터			*
	// 2) 변수 이름		pointer
	// 3) 데이터 타입	int
	DATA* pointer = &a;

	// 함수
	//typedef int(FUNC_TYPE)(int a, int b);
	using FUNC_TYPE = int(int a, int b);
	using TEST = void();

	// 1) 포인터			*
	// 2) 변수 이름		fn
	// 3) 데이터 타입	FUNC_TYPE 함수 int(int a, int b)
	FUNC_TYPE* fn;

	fn = Add;

	// 함수의 이름은 함수의 시작 주소 (배열과 유사)
	int result = Add(1, 2);
	cout << result << endl;

	result = fn(1, 2);
	cout << result << endl;

	result = (*fn)(1, 2);	// 함수 포인터는 *(접근 연산자) 가 붙어도 함수 주소!
	cout << result << endl;

	Item items[10] = {};
	items[3]._rarity = 2;	// RARE
	FindItem(items, 10, IsRareItem, 2);

	return 0;
}

