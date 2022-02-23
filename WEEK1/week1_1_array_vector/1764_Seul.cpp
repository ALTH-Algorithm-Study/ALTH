#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int count = 0;
	int N,M;
	cin >> N >> M;

	vector<string>name;
	vector<string>lsname;
	string na;
	for (int i = 0; i < N+M; i++)
	{
		cin >> na;
		name.push_back(na);
	}

	sort(name.begin(), name.end());

	for (int i = 0; i < N+M-1; i++)
	{
		if (name[i] == name[i + 1])
		{
			lsname.push_back(name[i]);
			count++;
		}
	}

	cout << count << '\n';
	for (int i = 0; i < lsname.size(); i++)
	{
		cout << lsname[i] << '\n';
	}
	return 0;
}