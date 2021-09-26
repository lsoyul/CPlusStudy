#include <iostream>
using namespace std;

// 포인터 vs 배열

void Test(int a)
{
	a++;
}

// 배열은 함수 인자로 넘기면, 컴파일러가 알아서 포인터로 치환한다. (char[] -> char*)
// 즉 배열의 내용 전체를 넘긴게 아니라, 시작 주소(포인터)만 넘긴 것.
void Test(char a[])
{
	a[0] = 'X';
	cout << sizeof(a) << endl;
}

int main()
{
	// .data 영역 주소[H][e][l]...
	// test1 [주소] << 8바이트
	const char* test1 = "Hello World";

	// .data 영역 주소[H][e][l]...
	// // => 4바이트씩 순차적으로 복사
	// [][][][]...
	// test2라는 바구니가 만들어진것이 아니지만, test2는 바구니 모음의 첫 주소를 가리킨다.
	char test2[] = "Hello World";

	// 포인터는 [주소를 담는 바구니]
	// 배열은 그 자체로 같은 데이터끼리 붙어있는 '바구니들의 모음'
	// - 다만 [배열 이름]은 '바구니 모음'의 '시작 주소'를 가리키고 있다.

	cout << test1[0] << endl;
	cout << test2[0] << endl;

	cout << sizeof(test1) << endl;
	cout << sizeof(test2) << endl;

	// 배열을 함수의 인자로 넘겨주게 되면?

	int a = 0;
	// [매개변수][RET주소][지역변수][매개변수][RET주소][지역변수]
	Test(a);
	cout << a << endl;
	
	// test2가 바뀔까? 안바뀔까? -> 바뀐다!
	Test(test2);	// 배열의 시작주소를 넘긴다.
	cout << test2 << endl;


	return 0;
}

