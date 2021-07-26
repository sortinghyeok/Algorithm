#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void testcase()
{
	string a, b;
	int maxNum = 0;
	int sizeA, sizeB;
	cin >> a >> b;
	sizeA = a.size();
	sizeB = b.size();
	
	vector<vector<int>> v(sizeA+1, vector<int>(sizeB+1, 0));

	for (int i = 1; i < sizeA + 1; i++)
	{
		for (int j = 1; j < sizeB + 1; j++)
		{
			if (a.at(i - 1) == b.at(j - 1))
			{
				v[i][j] = v[i - 1][j - 1] + 1;
				maxNum = max(maxNum, v[i][j]);
			}
		}
	}

	cout << maxNum;
}

int main()
{
	testcase();
}