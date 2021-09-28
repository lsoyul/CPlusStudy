#include <iostream>
using namespace std;

// 달팽이 그리기
// 5
// 00 01 02 03 04
// 15 16 17 18 05
// 14 23 24 19 06
// 13 22 21 20 07
// 12 11 10 09 08

// 4 4 4 3 3 2 2 1 1

// 4
// 00 01 02 03
// 11 12 13 04
// 10 15 14 05
// 09 08 07 06

// 3 3 3 2 2 1 1

enum DIRECTION
{
	UP = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3,
};


const int MAX = 100;

int map[MAX][MAX] = {};

void PrintMap(int number)
{
	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < number; j++)
		{
			if (map[i][j] < 10) cout << "0";
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}


void SetMap(int number)
{
	int direction = DIRECTION::RIGHT;

	int curRow = 0;
	int curCol = 0;

	int countNum = number - 1;
	int changeCountNumPivot = 3;

	int targetNum = 0;

	while (countNum > 0)
	{
		switch (direction)
		{
		case DIRECTION::UP:
			for (int i = 0; i < countNum; i++)
			{
				map[--curRow][curCol] = ++targetNum;
			}
			direction = DIRECTION::RIGHT;
			break;
		case DIRECTION::DOWN:
			for (int i = 0; i < countNum; i++)
			{
				map[++curRow][curCol] = ++targetNum;
			}
			direction = DIRECTION::LEFT;
			break;
		case DIRECTION::LEFT:
			for (int i = 0; i < countNum; i++)
			{
				map[curRow][--curCol] = ++targetNum;
			}
			direction = DIRECTION::UP;
			break;
		case DIRECTION::RIGHT:
			for (int i = 0; i < countNum; i++)
			{
				map[curRow][++curCol] = ++targetNum;
			}
			direction = DIRECTION::DOWN;
			break;
		}

		changeCountNumPivot--;
		if (changeCountNumPivot <= 0)
		{
			changeCountNumPivot = 2;
			countNum--;
		}
	}

}

int main()
{
	int num = 0;
	cin >> num;
	cout << endl;

	SetMap(num);
	PrintMap(num);

	return 0;
}

