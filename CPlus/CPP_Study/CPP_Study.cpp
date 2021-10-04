#include <iostream>
using namespace std;
#include <vector>

// STL Vector

int main()
{
	// STL (Standard Template Library)
	// C++ 프로그래밍을 할 때 필요한 자료구조/알고리즘들을
	// 템플릿으로 제공하는 라이브러리

	// 컨테이너(Container) : 데이터를 저장하는 객체 (자료구조 Data Structure)

	// vector (동적 배열)
	// - vector의 동작 원리 (size / capacity)
	// - 중간 삽입/삭제
	// - 처음,끝 삽입/삭제
	// - 임의 접근


	// - 동적 배열
	// 매우 매우 중요한 개념 -> 어떤 마법을 부렸길래 배열을 '유동적으로' 사용한 것인가?

	// 1) (여유분을 두고) 메모리를 할당한다.
	// 2) 여유분까지 꽉 찼으면, 메모리를 증설한다.

	// Q1) 여유분은 얼만큼이 적당할까?
	// Q2) 증설을 얼만큼 해야 할까?
	// Q3) 증설될 때, 기존의 데이터를 어떻게 처리할까?


	// [ 1 2 3 4 5 ][ 마음대로 건들 수 없는 영역 ]
	// [ 1 2 3 4 5                             ]	<= 다른 영역에 새로 할당
	vector<int> v(1000,0);
	vector<int> v2 = v;

	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	// [				]
	v.resize(1000);
	// size (실제 사용 데이터 갯수)
	// 1 2 3 4 5 6 7 ...
	
	//v.reserve(1000);	// <= capacity 할당
	// capacity (여유분을 포함한 용량 갯수)
	// 1 2 3 4 6 9 13 19 28 42 63 ...
	// => 대략 이전 capacity의 1.5배 ~ 2배

	for (int i = 0; i < 1001; i++)
	{
		v.push_back(100);
		cout << v.size() << " " << v.capacity() << endl;
	}


	v.clear();				// <= size는 0으로 capacity는 그대로
	vector<int>().swap(v);	// <= 새로운 깡통벡터와 swap되므로 size,capacity 둘 다 0으로 초기화
	cout << v.size() << " " << v.capacity() << endl;

	return 0;
}

