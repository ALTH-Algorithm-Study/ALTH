#include <iostream>
#include <algorithm>
using namespace std;

int card[1001];
int dp[1002];

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> card[i];
	}

	dp[1] = card[1];

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i], card[j] + dp[i - j]);
		}
	}

	cout << dp[N] << '\n';

	return 0;
}