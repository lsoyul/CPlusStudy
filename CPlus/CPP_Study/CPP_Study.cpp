#include <iostream>
using namespace std;

// 포인터 정리

// 1) 문자열 길이 반환
int StrLen(const char* str)
{
	// str이라는 문자열의 길이를 반환
	char t = *str;
	int length = 0;

	while (t != '\0')
	{
		t = *(++str);
		length++;
	}

	return length;
}

// 2) 문자열 복사
char* StrCopy(char* dest, const char* source)
{
	int cur = 0;

	while (source[cur] != '\0')
	{
		dest[cur] = source[cur];
		cur++;
	}

	dest[cur] = '\0';

	return dest;
}


int main()
{
	const int BUF_SIZE = 100;

	char a[BUF_SIZE] = "Hello";
	char b[BUF_SIZE] = {};

	//int len = sizeof(a);	// sizeof == a버퍼의 크기 == 100
	//cout << len;

	int len = StrLen(a);	// strlen == 실제 문자열의 크기
	cout << a << endl;

	cout << b << endl;
	StrCopy(b, a);
	cout << b;

	return 0;
}

