#include <iostream>
#include <queue>
#define endl '\n'
#define MAX 1001
using namespace std;

int n; // 정점의 개수
int m; // 간선의 개수
int v; // 탐색을 시작한 정점의 번호
bool visitBFS[MAX];
bool visitDFS[MAX];
bool graph[MAX][MAX];

void bfs(int start) {
	queue<int> q;
	q.push(start);  // 시작 노드 push
	visitBFS[start] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << " "; // 순회하는 노드의 값을 보여줌. 
		for (int i = 1; i <= n; i++) {
			if (visitBFS[i] == 1 || graph[x][i] == 0) // 방문한 노드이거나 인접한 노드가 아닌 경우
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
		if (visitDFS[i] == 1 || graph[start][i] == 0) // 방문한 노드이거나 인접한 노드가 아닌 경우
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