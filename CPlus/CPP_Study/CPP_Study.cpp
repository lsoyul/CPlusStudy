#include <iostream>
using namespace std;

// 다중 포인터 (이중 포인터)

void SetNumber(int* a)
{
	*a = 1;
}

void SetMessage(const char* a)
{
	a = "Bye";
}

void SetMessage(const char** a)
{
	*a = "Bye";
}

void SetMessage2(const char*& a)
{
	a = "WOW";
}

int main()
{
	int a = 0;
	SetNumber(&a);
	

	// .rodata Hello주소 - [H][e][l][l]...[\0]
	// .rodata Bye주소 - [B][y][e][\0]
	// 
	// msg - [ 주소 ] << 8바이트
	const char* msg = "Hello World";

	// [매개변수][RET주소][지역변수(msg(Hello주소))] => SetMessage[매개변수(a(Hello주소))][RET주소][지역변수]
	SetMessage(msg);
	//cout << msg << endl;


	// .rodata Hello주소 - [H][e][l][l]...[\0]
	// msg [ Hello주소 ] << 8바이트
	// pp [ &msg ] << 8바이트
	const char** pp = &msg;

	SetMessage(&msg);

	cout << msg << endl;


	// 다중포인터.. 혼동스럽다?
	// 그냥 양파까기라고 생각하자.
	// *을 하나씩 까면서 타고 간다고 생각
	const char** pp2;

	// 참조전달 버전
	SetMessage2(msg);
	cout << msg << endl;


	return 0;
}

