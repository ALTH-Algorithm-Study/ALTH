#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int> v;

int main()
{

	int N, k;
	cin >> N;

	int chicken;
	for (int i = 0; i < N; i++)
	{
		cin >> chicken;
		v.push_back(chicken);
	}

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		sort(v.begin() + (i*(N/k)), v.begin() + ((i + 1) * (N/k)));
	}

	for (int i = 0; i < N; i++)
	{
		cout << v[i] << " ";
	}

	return 0;
}