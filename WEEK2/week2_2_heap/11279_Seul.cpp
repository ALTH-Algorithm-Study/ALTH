#include<iostream>
#include<queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int> que;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (num == 0)
		{
			if (que.size() == 0)
			{
				cout << "0" << '\n';
			}
			else
			{
				cout << que.top()<<'\n';
				que.pop();
			}
		}
		else
		{
			que.push(num);
		}
	}

	return 0;
}