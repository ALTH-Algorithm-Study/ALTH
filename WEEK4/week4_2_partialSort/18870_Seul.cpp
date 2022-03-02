#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
vector<int> s;

int main()
{
	int N,num;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
		s.push_back(num);
	}

	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());

	for (int i = 0; i < N; i++)
	{
		cout << lower_bound(s.begin(), s.end(), v[i]) - s.begin()<<" ";
	}


	return 0;
}
