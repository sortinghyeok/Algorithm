#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int test;
	cin >> test;
	while (test--)
	{
		int n;
		cin >> n;
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			v.push_back(temp);
		}

		int maxheight = 0;
		sort(v.begin(), v.end());
		
		for (int i = 0; i < v.size()-2; i++)
		{
			maxheight = max(maxheight, abs(v[i] - v[i + 2]));
		}
		cout << maxheight << endl;
	}
}