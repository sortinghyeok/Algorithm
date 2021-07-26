#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int size;
	cin >> size; //몇 개의 숫자를 벡터에 받을 것인가

	vector<int > v(size);

	for (int i = 0; i < size; i++)
	{
		cin >> v[i];//벡터에 아이템 입력
	}
	sort(v.begin(), v.end());//오름차순 정렬

	vector<int> goodlist;//good을 저장할 벡터

	for (int i = 0; i < v.size(); i++)
	{
		int templeft = 0;//벡터의 시작 인덱스
		int priorOne = v[0];//벡터의 첫번째 아이템으로 초기화
		
		int tempRight = size - 1; //벡터의 마지막 인덱스
		int laterOne = v[tempRight];//벡터의 마지막 아이템으로 초기화
		int isgood = v[i];//좋은 숫자 인지 판단할 인덱스
		while (priorOne < laterOne)//priorOne과 laterOne이 엇갈려버리면 답이 존재하지 않는다는 것
		{
			if (laterOne + priorOne == isgood)//good 확인
			{
				goodlist.push_back(isgood);
				break;
			}
			else if (laterOne + priorOne < isgood)/*만약 타겟인 숫자가 laterOne + priorOne보다 크다면
												 priorOne의 인덱스를 올려준다.(laterOne은 이미 충분히 큰 수이기 때문)*/
			{
				templeft += 1;
				priorOne = v[templeft];
			}
			else if (laterOne + priorOne > isgood)/*만약 타겟인 숫자가 laterOne + priorOne보다 작다면,
												  laterOne의 인덱스를 낮춰준다. (priorOne은 이미 충분히 작기 때문)*/
			{
				tempRight += -1;
				laterOne = v[tempRight];
			}
		}
		
	}
	cout << goodlist.size();

}