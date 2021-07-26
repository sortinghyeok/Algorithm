#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int size;
	cin >> size; //�� ���� ���ڸ� ���Ϳ� ���� ���ΰ�

	vector<int > v(size);

	for (int i = 0; i < size; i++)
	{
		cin >> v[i];//���Ϳ� ������ �Է�
	}
	sort(v.begin(), v.end());//�������� ����

	vector<int> goodlist;//good�� ������ ����

	for (int i = 0; i < v.size(); i++)
	{
		int templeft = 0;//������ ���� �ε���
		int priorOne = v[0];//������ ù��° ���������� �ʱ�ȭ
		
		int tempRight = size - 1; //������ ������ �ε���
		int laterOne = v[tempRight];//������ ������ ���������� �ʱ�ȭ
		int isgood = v[i];//���� ���� ���� �Ǵ��� �ε���
		while (priorOne < laterOne)//priorOne�� laterOne�� ������������ ���� �������� �ʴ´ٴ� ��
		{
			if (laterOne + priorOne == isgood)//good Ȯ��
			{
				goodlist.push_back(isgood);
				break;
			}
			else if (laterOne + priorOne < isgood)/*���� Ÿ���� ���ڰ� laterOne + priorOne���� ũ�ٸ�
												 priorOne�� �ε����� �÷��ش�.(laterOne�� �̹� ����� ū ���̱� ����)*/
			{
				templeft += 1;
				priorOne = v[templeft];
			}
			else if (laterOne + priorOne > isgood)/*���� Ÿ���� ���ڰ� laterOne + priorOne���� �۴ٸ�,
												  laterOne�� �ε����� �����ش�. (priorOne�� �̹� ����� �۱� ����)*/
			{
				tempRight += -1;
				laterOne = v[tempRight];
			}
		}
		
	}
	cout << goodlist.size();

}