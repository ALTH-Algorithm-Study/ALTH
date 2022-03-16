#include<iostream>
#include<vector>
using namespace std;

vector<int>tree[500001]; // 트리 입력
int result = 0; // 깊이의 합
bool visited[500001]; // 방문 여부


void dfs(int n, int d)
{
	if (n != 1 && tree[n].size() == 1) // n이 1이면 루트 노드이고 size가 1일 경우 리프 노드임
	{
		result += d; // 결과 값에 깊이를 더해줌
		return;
	}
	for (int i = 0; i < tree[n].size(); i++)
	{
		if (!visited[tree[n][i]])
		{
			visited[tree[n][i]] = true;
			dfs(tree[n][i], d + 1); // 자식 노드로 들어가 재귀 사용
			visited[tree[n][i]] = false; // 계속 반복해야 하므로 dfs 재귀가 끝나면 방문 안했다고 바꿔줌
		}
	}
}

int main()
{
	int N,n1,n2;
	cin >> N;
	for (int i = 0; i < N-1; i++)
	{
		cin >> n1 >> n2;
		tree[n1].push_back(n2); // 각자에게 노드값을 넣어줌
		tree[n2].push_back(n1);
	}
	visited[1] = true; // 루트 노드는 방문해있음
	dfs(1, 0);

	if (result % 2 == 1) cout << "Yes"; // 성원이가 먼저 시작하므로 홀수 일때 승리
	else cout << "No";

	return 0;
}