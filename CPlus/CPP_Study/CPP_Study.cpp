#include <iostream>
using namespace std;

// 타입 변환 (포인터)

class Knight
{
public:
	int _hp = 0;
};

class Item
{
public:
	Item()
	{
		cout << "Item()" << endl;
	}

	Item(int itemType) : _itemType(itemType)
	{
		cout << "Item(int itemType)" << endl;
	}

	Item(const Item& item)
	{
		cout << "Item(const Item&)" << endl;
	}

	virtual ~Item()
	{
		cout << "~Item()" << endl;
	}

	virtual void Test()
	{
		cout << "Test()" << endl;
	}

public:
	int _itemType = 0;
	int _itemDBId = 0;

	char _dummy[4096] = {};	// 이런 저런 정보들로 인해 비대해진 아이템 클래스 묘사용
};

enum ItemType
{
	IT_WEAPON = 1,
	IT_ARMOR = 2,
};

class Armor : public Item
{
public:
	Armor() : Item(IT_ARMOR) { cout << "Armor()" << endl; }
	~Armor() { cout << "~Armor()" << endl; }

public:
	int _defence = 0;
};

class Weapon : public Item
{
public:
	Weapon() : Item(IT_WEAPON) 
	{ 
		cout << "Weapon()" << endl; 
		_damage = rand() % 100;
	}
	~Weapon() { cout << "~Weapon()" << endl; }

	void Test()
	{
		cout << "Test Weapon()" << endl;
	}

public:
	int _damage = 0;
};

void TestItem(Item item)
{

}

void TestItemPtr(Item* item)
{
	item->Test();
}

int main()
{


	// 연관성이 없는 클래스 사이의 포인터 변환 테스트
	{
		// Stack [ 주소 ] -> Heap [ _hp(4) ]
		Knight* knight = new Knight();

		// 암시적으로는 NO
		// 명시적으로는 OK
		// *** C++의 가장 무섭고 위험한 부분 ***
		
		// Stack [ 주소 ] -> Heap [ [_hp(4) x x x...] ]
		//Item* item = (Item*)knight;
		//item->_itemType = 2;
		//item->_itemDBId = 10;

		//delete item;

	}

	// 부모 -> 자식 변환 테스트
	{
		Item* item = new Item();
		//Weapon* weapon = (Weapon*)item;
		
		delete item;
	}

	// 자식 -> 부모 변환 테스트
	{
		Weapon* weapon = new Weapon();
		Item* item = weapon;

		//TestItemPtr(item);

		delete weapon;
	}

	// 명시적으로 타입 변환 할 때에는 항상 조심해야 한다!
	// 암시적으로 될 때는 안전하다?
	// -> 평생 명시적으로 타입 변환(캐스팅)을 안하면 되는거 아닌가?

	Item* inventory[20] = {};

	srand((unsigned int)time(nullptr));

	for (int i = 0; i < 20; i++)
	{
		int randValue = rand() % 2;	// 0~1;

		switch (randValue)
		{
		case IT_WEAPON:
			inventory[i] = new Weapon();
			break;
		case IT_ARMOR:
			inventory[i] = new Armor();
			break;
		}
	}

	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];

		if (item == nullptr) continue;

		if (item->_itemType == IT_WEAPON)
		{
			Weapon* weapon = (Weapon*)item;
			cout << "Weapon Damage : " << weapon->_damage << endl;
		}
	}


	// ************************ 매우 매우 중요 ******************************
	for (int i = 0; i < 20; i++)
	{
		Item* item = inventory[i];

		if (item == nullptr) continue;
		
		//if (item->_itemType == IT_WEAPON)
		//{
		//	Weapon* weapon = (Weapon*)item;
		//	delete weapon;
		//}
		//else
		//{
		//	Armor* armor = (Armor*)item;
		//	delete armor;
		//}

		// * 부모 소멸자를 virtual로 만들어주자!
		delete item;
	}


	// [결론]
	// - 포인터 vs 일반 타입의 차이점 이해
	// - 포인터 사이의 타입 변환 (캐스팅)을 할 때에는 매우 매우 조심해야 한다.
	// - 부모-자식 관계에서 부모 클래스의 소멸자에는 무조건 virtual을 붙여야 한다.


	return 0;
}

