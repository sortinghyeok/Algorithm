#include <iostream>
#include <string>
using namespace std;

void testcase()
{
	int tnum;
	cin >> tnum;
	
	int caseNum = 1;
	
	while (tnum--)
	{
		long long nowcount = 1;

		long long strlength;
		cin >> strlength;
		
		string str;
		cin >> str;

		cout << "Case #" << caseNum++ << ": ";

		cout << nowcount << " ";
		for (long long i = 1; i < strlength; i++)
		{
			if (str.at(i-1) < str.at(i))
			{
				nowcount++;
				cout << nowcount << " ";	
			}
			else
			{
				nowcount = 1;
				cout << nowcount << " ";
			}
				
		}
		cout << endl;
	}
}

int main()
{
	testcase();
}