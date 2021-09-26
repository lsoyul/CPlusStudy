#include <iostream>
using namespace std;

// 포인터 정리

int* TestPointer()
{
	int a = 1;
	return &a;
}

void TestWrong(int* ptr)
{
	int a[100] = {};
	a[99] = 0xAAAAAAAA;
	*ptr = 0x12341234;
}

int main()
{
	// 2차원 배열과 다중포인터가 같다??

	// [1][2][3][4]
	int arr[2][2] = { {1,2},{3,4} };

	// 00000001 [] << 4바이트 => error
	// 주소1 [00000001]
	// pp [주소1]
	int** pp = (int**)arr;	// ?

	//cout << (**pp) << endl;

	// TYPE name[갯수]

	// [1][2] [3][4]
	// [ 주소 ]
	int (*p2)[2] = arr;
	cout << (*p2)[0] << endl;
	cout << (*p2)[1] << endl;
	cout << (*(p2 + 1))[0] << endl;
	cout << (*(p2 + 1))[1] << endl;

	cout << p2[0][0] << endl;
	cout << p2[0][1] << endl;
	cout << p2[1][0] << endl;
	cout << p2[1][1] << endl;


	// [매개변수][RET][지역변수] -TestPointer [매개변수][RET][지역변수]
	// [매개변수][RET][지역변수]
	// TestPointer가 리턴되면 스택 프레임에서 정리된다.
	int* pointer = TestPointer();

	TestWrong(pointer);
	*pointer = 123;

	cout << *pointer << endl;

	// 스택프레임과 관련된 데이터의 주소값을 외부로 넘겨주지 않도록 하자!

	return 0;
}

