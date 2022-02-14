#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> Deque;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		string order;
		cin >> order;
		if (order == "push_front")
		{
			cin >> num;
			Deque.insert(Deque.begin(), num);

		}
		else if (order == "push_back")
		{
			cin >> num;
			Deque.push_back(num);
		}
		else if (order == "pop_front")
		{
			if (Deque.empty()) cout << "-1" << '\n';
			else
			{
				cout << Deque.front() << '\n';
				Deque.erase(Deque.begin());
			}
		}
		else if (order == "pop_back")
		{
			if (Deque.empty()) cout << "-1" << '\n';
			else
			{
				cout << Deque.back() << '\n';
				Deque.pop_back();
			}
		}
		else if (order == "size")
		{
			cout << Deque.size()<<'\n';
		}
		else if (order == "empty")
		{
			if (Deque.empty()) cout << "1" << '\n';
			else cout << "0" << '\n';
		}
		else if (order == "front")
		{
			if (Deque.empty()) cout << "-1" << '\n';
			else
			{
				cout << Deque.front() << '\n';
			}
		}
		else if (order == "back")
		{
			if (Deque.empty()) cout << "-1" << '\n';
			else
			{
				cout << Deque.back() << '\n';
			}
		}
	}


	return 0;
}