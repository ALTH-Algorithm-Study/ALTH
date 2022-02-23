#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		stack<char> testcase;
		string test;
		cin >> test;
		for (int j = 0; j < test.size(); j++)
		{
			if (test.at(j) == '(')
			{
				testcase.push(test.at(j));
			}
			else
			{
				if(testcase.empty())
				{
					cout << "NO"<<'\n';
					break;
				}
				else if (testcase.top() == '(')
				{
					testcase.pop();
				}
			}
			if (testcase.empty()&&j==test.size()-1) cout << "YES" << '\n';
		}
		if (!testcase.empty()) cout << "NO" << '\n';
	}


	return 0;
}