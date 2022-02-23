#include<iostream>
using namespace std;

int arr[301][301];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int num;
			cin >> num;
			arr[i][j] = num;
		}
	}

	int K;
	cin >> K;

	int i, j, x, y;
	for (int m = 0; m < K; m++)
	{
		cin >> i >> j >> x >> y;
		int count = 0;
		for (int k = i - 1; k < x; k++)
		{
			for (int l = j - 1; l < y; l++)
			{
				count += arr[k][l];
			}
		}
		cout << count << '\n';
	}

	return 0;
}