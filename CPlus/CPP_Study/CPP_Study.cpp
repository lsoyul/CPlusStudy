#include <iostream>
using namespace std;

// bool 은 그냥 정수 데이터지만, 참/거짓을 나타내기 위해 사용됨.
// char도 마찬가지로 그냥 정수지만, '문자'의 의미를 나타내기 위해 사용.

// char : 알파벳 / 숫자 문자를 나타낸다.
// wchar_t : 유니코드 문자를 나타낸다.

// ASCII (American Standard Code for Information Interchange)
// a b c d e 1 2 3 4 5 ...
char ch = 97; // => a
// 문자의 의미로 '' 사용
char ch1 = 'a';
char ch2 = '1';
char ch3 = 'a' + 1;


// Global 시대에서 영어만으로 서비스 할 수 없음.
// 전 세계 모든 문자에 대해 유일코드를 부여한 것이 유니코드 (unicode)
// 참고) 유니코드에서 가장 많은 번호를 차지하는게 한국어/중국어 (뚫쿩웱.. 등 모든 문자를 표현해야하기 때문)


// 유니코드는 표기 방식이 여러가지가 있는데, 대표적으로 UTF8 UTF16
// UTF8
// - 알파벳, 숫자는 1바이트 (ASCII 동일한 번호)
// - 유럽 지역의 문자는 2바이트
// - 한글, 한자 등은 3바이트
// => 유동적임
// UTF16
// - 알파벳, 숫자, 한글, 한자 등 거의 대부분 문자는 2바이트
// - 매~우 예외적인 고대 문자만 4바이트 (사실상 무시해도 됨)

wchar_t wch = L'안';		// 앞에 L을 붙임
wchar_t wch1 = 0xc548;

// Escape Sequence
// 표기하기 애매한 것들을 표현
// \t = 아스키코드 9번 = Tab
// \n = 아스키코드 10번 = LineFeed (한줄 아래로)
// \r = 아스키코드 13번 = CarriageReturn (커서 맨 앞으로)
// => enter 기능은 \r\n 으로 표현가능
// \' = 기호 그 자체를 문자로 표현
// \0 = null

// 문자열
// 문자들이 열을 지어서 모여있는 것 (문자 배열)
// 정수 (1~8 바이트) 고정 길이로
// \00 (null) 이 끝을 나타냄 (아스키코드 0번)

char str[] = { 'h', 'e', 'l', 'l', 'o' };
char str4[] = "Hello World";
wchar_t str5[] = L"Hello World";

int main()
{
	cout << ch << endl;
	cout << ch2 << endl;
	cout << ch3 << endl;

	// cout은 char 전용
	cout << wch << endl; // X

	wcout.imbue(locale("kor"));
	wcout << wch << endl;
	wcout << wch1 << endl;

	// .data 영역에 저장되기 때문에 나머지 메모리영역이 0으로 초기화 되어있어 문제가 안된다.
	cout << str << endl;

	// Stack 영역에 저장이 되기 때문에 o 이후 쓰레기값들이 저장되어 있음.
	char str2[] = { 'h', 'e', 'l', 'l', 'o' };
	cout << str2 << endl;


	char str3[] = { 'h', 'e', 'l', 'l', 'o', '\0'};
	cout << str3 << endl;

	cout << str4 << endl;
	wcout << str5 << endl;

	cout << 'a' << 'b' << 'c' << 'd' << '\n' << '\r' << 'e';
}
