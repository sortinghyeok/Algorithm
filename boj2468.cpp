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
//(1,0), (-1, 0), (0,1), (0, -1)�� ���� ������ �� ��. �ֳ��ϸ� ������ �밢�����δ� �̵��� �ȵǹǷ�

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
	int result = 1;//���� ������ �ִ밪�� ����Ʈ��. �� 0�� �����
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
	

	//�Ʒ� i�� �������� �ǹ��ϹǷ� �߿��ϴ�
	for (int i = 0; i < 101; i++)//���� �ּ� 1, �ִ� 100�̹Ƿ� ���� ������ 0���� 100���� ������, ������ 101������ �ϸ� ������ ���� ���Ƿ� �ǹ̾���
	{
		retry();//���� �Է¹޾Ҵ� ������ ground �ʱ�ȭ
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