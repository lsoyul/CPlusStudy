#include <iostream>
using namespace std;

// 포인터 vs 참조

#define OUT

struct StatInfo
{
	int hp;			// +0
	int attack;		// +4
	int defence;	// +8
};


int main()
{
	StatInfo player;
	player.attack = 1;
	player.hp = 2;
	player.defence = 3;


	// 포인터 vs 참조 세기의 대결
	// - 성능 : 똑같음
	// - 편의성 : 참조 승!
	
	// 1) 편의성 관련
	// 편의성이 좋다는게 꼭 장점만이 아니다.
	// 포인터는 주소를 넘기므로 확실하게 원본을 넘긴다는 힌트를 줄 수 있음.
	// 반면, 참조 전달은 자연스럽게 모르고 지나칠 수 있음.
	// ex) ByRefer(player) => 값 전달처럼 보일 수 있다.
	// ex) 마음대로 고친다면? const를 사용해서 고치지 못하도록 제한 가능. (읽기 전용)

	// 참고로 포인터도 const 사용 가능
	// * 기준으로 앞, 뒤 붙이는 위치에 따라 의미가 달라짐.

	// 2) 초기화 여부
	// 참조 타입은 바구니의 2번째 이름 (별칭)
	// -> 참조하는 대상이 없으면 안됨.
	// -> StatInfo& reference;  와 같은 경우 컴파일 에러
	// 반면 포인터는 어떠한 주소 라는 의미
	// -> 대상이 실제 존재하지 않을 수 있음.
	// 포인터에서 '없다'는 의미?  nullptr
	// 
	StatInfo* pointer = nullptr;
	pointer = &player;


	ByRefer(player);
	ByPointer(pointer);


	// 결론은?
	//  정해진 답은 없다.
	// ex) 구글에서 만든 오픈소스들을 보면 거의 무조건 포인터 사용
	// ex) 언리얼 엔진에선 reference도 애용

	// 개인적으로
	// - 없는 경우도 고려해야 한다면 pointer 사용 (null 체크 필수)
	// - 바뀌지 않고 읽는 용도 (readonly)만 사용한다면 const ref&
	// 그 외, 일반적으로 ref (명시적으로 호출 할 때 OUT을 붙인다.) => 가독성 측면 (언리얼 엔진에서 사용하는 방식)
	// -- 단, 다른 사람이 pointer를 만들어 놓은 걸 이어서 만든다면, 계속 pointer 사용 (섞어서 사용하지는 않는다.)

	ChangeInfo(OUT player);


	// BONUS) 포인터로 사용하던걸 참조로 넘겨주려면?
	// pointer[주소(&info)]   info[데이터]
	ByRefer(*pointer);

	// BONUS) 참조로 사용하던걸 포인터로 넘겨주려면?
	// pointer[주소(&info)]   ref, info[데이터]
	StatInfo& ref = player;	
	ByPointer(&ref);

	return 0;
}


void ChangeInfo(OUT StatInfo& info)
{
	info.attack = 3;
}

// * 참조 전달 방식
// 값 전달처럼 편리하게 사용하고
// 주소 전달처럼 주소값내의 데이터를 수정 할 수 있도록 함
// 일석이조의 방식
void ByRefer(const StatInfo& refer)
{
	//refer.attack = 3;
	cout << refer.attack << endl;
}

StatInfo globalInfo;

void ByPointer(const StatInfo* ptr)
{
	//ptr->attack = 3;

	// const를
	// 1. 별 앞에 붙인다면? const StatInfo*
	// ptr이 가리키고 있는 내용물을 바꿀 수 없다.

	// 2. 별 뒤에 붙인다면? StatInfo* const
	// ptr라는 바구니의 내용물(주소)을 바꿀 수 없다.
	// ptr의 주소값은 고정이다!


	ptr = &globalInfo;
	//ptr->attack = 10000;
}