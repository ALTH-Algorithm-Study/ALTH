#include<iostream>
#include <vector>
#include<utility>
using namespace std;

int main() {

	vector<pair<int, int>> ballon;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{	
		int num;
		cin >> num;
		ballon.push_back(make_pair(num,i+1));
	}
	
	int order=0;

	for (int i = 0; i < N; i++)
	{
		cout << ballon[order].second << " ";

		int first = ballon[order].first;

		ballon.erase(ballon.begin() + order);

		if (ballon.size() == 0)break;

		if (first > 0)
		{
			order = order + first-1;
			order %= ballon.size();
		}
		else {
			order += first;
			while (order < 0)
			{
				order += ballon.size();
			}
		}
	}

	return 0;
}