#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int rowAndcul;// rowAndcul x rowAndcul
int ground[100][100];
int backup[100][100];
int visit[100][100] = {0};

int x[4] = { 1, -1, 0, 0 };
int y[4] = { 0, 0, 1, -1 };
//(1,0), (-1, 0), (0,1), (0, -1)의 벡터 역할을 할 것. 왜냐하면 공간의 대각선으로는 이동이 안되므로

void DFS(int row, int cul, int depth)
{

	if (visit[row][cul] != 0)
	{
		return;
	}
	else
	{
		visit[row][cul] = 1;
	}

	for (int i = 0; i < 4; i++)
	{
		int movedCul = cul + x[i];
		int movedRow = row + y[i];

		if (movedCul >= 0 && movedRow >= 0 && movedCul < rowAndcul && movedRow < rowAndcul && ground[row][cul]> depth)
		{
			DFS(movedRow, movedCul, depth);
		}
	}
}

void retry()
{
	for (int i = 0; i < rowAndcul; i++)
	{
		for (int k = 0; k < rowAndcul; k++)
		{
			ground[i][k] = backup[i][k];
			visit[i][k] = 0;
		}
	}
}
int main()
{
	int count = 0;
	int result = 1;//물에 안잠기는 최대값의 디폴트값. 비가 0인 경우임
	cin >> rowAndcul;
	

	for (int i = 0; i < rowAndcul; i++)
	{
		for (int k = 0; k < rowAndcul; k++)
		{
			int temp;
			cin >> temp;
			backup[i][k] = temp;
		}
	}
	
	/*for (int i = 0; i < rowAndcul; i++)
	{
		for (int k = 0; k < rowAndcul; k++)
		{
			cout << v[i][k].value << " ";

		}
		cout << endl;
	}*/
	

	//아래 i는 강수량을 의미하므로 중요하다
	for (int i = 0; i < 101; i++)//높이 최소 1, 최대 100이므로 비의 범위를 0에서 100으로 정해줌, 루프를 101까지로 하면 무조건 땅이 잠기므로 의미없음
	{
		retry();//원래 입력받았던 것으로 ground 초기화
		count = 0;

		for (int j = 0; j < rowAndcul; j++)
		{
			for (int k = 0; k < rowAndcul; k++)
			{
				if (visit[j][k] == 0 && ground[j][k] > i)
				{
					DFS(j, k, i);
					count++;
				}
			}
		}

		result = max(count, result);
	}

	cout << result;
}