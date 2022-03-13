#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int n; // ������ ����
int m; // ������ ����
int v; // Ž���� ������ ������ ��ȣ
bool visitBFS[1001];
bool visitDFS[1001];
vector<int> graph[1001];

void bfs(int start) {
	queue<int> q;
	q.push(start);  // ���� ��� push
	visitBFS[start] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << " "; // ��ȸ�ϴ� ����� ���� ������. 
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visitBFS[y]) { // �湮���� ���� �����
				q.push(y); // ���� ��带 ť�� �ְ�
				visitBFS[y] = true; // �湮 ó���Ѵ�.
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