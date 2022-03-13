#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int n; // 정점의 개수
int m; // 간선의 개수
int v; // 탐색을 시작한 정점의 번호
bool visitBFS[1001];
bool visitDFS[1001];
vector<int> graph[1001];

void bfs(int start) {
	queue<int> q;
	q.push(start);  // 시작 노드 push
	visitBFS[start] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << " "; // 순회하는 노드의 값을 보여줌. 
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visitBFS[y]) { // 방문하지 않은 노드라면
				q.push(y); // 인접 노드를 큐에 넣고
				visitBFS[y] = true; // 방문 처리한다.
			}
		}
	}
}

void dfs(int start) {
	visitDFS[start] = true;
	cout << start << " ";
	for (int i = 0; i < graph[start].size(); i++) {
		int y = graph[start][i];
		if (!visitDFS[y]) {
			dfs(y);
		}
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
		graph[tmp1].push_back(tmp2);
		graph[tmp2].push_back(tmp1);
	}

	dfs(v);
	cout << endl;
	bfs(v);

	return 0;
}