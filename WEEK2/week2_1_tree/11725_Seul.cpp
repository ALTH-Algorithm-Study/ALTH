#include<iostream>
#include<vector>
using namespace std;

bool visit[100001];
int Node[100001];
vector<int> Tree[1000001];

void findNode(int num) {
	visit[num] = true;

	for (int i = 0; i < Tree[num].size(); i++) {
		int next = Tree[num][i];
		if (!visit[next])
		{
			Node[next] = num;
			findNode(next);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	int num1,num2;
	Node[1] = 1;

	for (int i = 1; i < N; i++)
	{
		cin >> num1 >> num2;
		Tree[num1].push_back(num2);
		Tree[num2].push_back(num1);
	}

	findNode(1);

	for (int i = 2; i <= N; i++)
		cout << Node[i] << '\n';

	return 0;
}