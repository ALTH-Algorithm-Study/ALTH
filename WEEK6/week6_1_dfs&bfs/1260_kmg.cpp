#include <iostream>
#include <queue>
#define endl '\n'
#define MAX 1001
using namespace std;

int n; // ������ ����
int m; // ������ ����
int v; // Ž���� ������ ������ ��ȣ
bool visitBFS[MAX];
bool visitDFS[MAX];
bool graph[MAX][MAX];

void bfs(int start) {
	queue<int> q;
	q.push(start);  // ���� ��� push
	visitBFS[start] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << " "; // ��ȸ�ϴ� ����� ���� ������. 
		for (int i = 1; i <= n; i++) {
			if (visitBFS[i] == 1 || graph[x][i] == 0) // �湮�� ����̰ų� ������ ��尡 �ƴ� ���
				continue; // PASS
			q.push(i);
			visitBFS[i] = true;
		}
	}
}

void dfs(int start) {
	visitDFS[start] = true;
	cout << start << " ";
	for (int i = 1; i <= n; i++) {
		if (visitDFS[i] == 1 || graph[start][i] == 0) // �湮�� ����̰ų� ������ ��尡 �ƴ� ���
			continue;
		dfs(i);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);


	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		graph[tmp1][tmp2] = graph[tmp2][tmp1] = 1;
	}

	dfs(v);
	cout << endl;
	bfs(v);

	return 0;
}