#include <iostream>
using namespace std;

// Comment
// Ctrl+K+C (Comment) Ctrl+K+U (Uncomment)

/*
 multiple 
 line 
 comments
*/

// 변수 선언
// [타입] [이름];
// [타입] [이름] = [초기값];


// 0 이 아닌 초기화 값이 있으면 .data 영역
int hp = 100;


// 초기값이 0 이거나, 초기값이 없는 변수라면 .bss 영역
char a;     // 1byte
short b;    // 2bytes
int c;      // 4bytes
__int64 d;  // 8bytes (long long)

unsigned char ua;     // 1byte
unsigned short ub;    // 2bytes
unsigned int uc;      // 4bytes
unsigned __int64 ud;  // 8bytes (long long)


// 참고) 이론적으로 양수만 존재할 수 있는 데이터? unsigned?
// 무조건 unsigned를 사용할지 의견이 갈림
// - 레벨이 음수라는 것은 말이 안된다 -> 그러면 차라리 그 자리에서 프로그램을 크래시 내서 버그를 찾는게 나을 수 있다.
// - unsigned / signed 사이의 변환!
// => 여러가지 고려가 필요함


// 변수 타입 관리의 필요성
// -> console / mobile => 메모리가 늘 부족함.
// -> 온라인 게임 => 4바이트 * 1만명 같은 대용량 패킷 처리.


int main()
{
    // 정수 overflow
    b = 32767;
    b = b + 1;
    cout << b << endl; // -32768

    // 정수 underflow
    ub = 0;
    ub = ub - 1;
    cout << ub << endl;

    //cout << "체력이 " << hp << " 남았습니다.";
}
