// DFS와 BFS(1260)
// 3.13
// 성공

#include <iostream>
#include <vector>
#include <queue> // BFS
#include <algorithm>
#define endl "\n"
using namespace std;

int N, M, V; // N:정점의 개수, M:간선의 개수, V:시작정점번호
vector<int> node[1001];
int check[1001] = { 0 };
int bnode[1001][1001] = { 0 };
queue<int> que;
int biggest = -1;
int temp = -1;
void connect(int n1, int n2) { // 간선 양방향 연결
	temp = max(n1, n2);
	biggest = max(biggest, temp); // 가장 큰 정점을 찾아서 for문을 좀 더 효율적으로 돌려줄 것임
	
	node[n1].push_back(n2); // DFS를 위한 연결
	node[n2].push_back(n1);
	bnode[n1][n2] = 1; // BFS를 위한 연결
	bnode[n2][n1] = 1;
}

void DFS(int st) { // st는 시작하는 정점
	cout << st << " ";
	check[st] = 1; // 이곳은 한 번 방문했다
	for (int i = 0; i < node[st].size(); i++) {
		int x = node[st][i]; // x는 st와 연결된 정점
		if (check[x] == 0) {
			check[x] = 1; // x곳 방문했고
			DFS(x);
		}
	}
}

void BFS(int st) {
	cout << st << " ";
	que.push(st);
	while (!que.empty()) {
		int f = que.front();
		que.pop();
		for (int i = 1; i <= N; i++) {
			if (check[i] == 0 && bnode[f][i] == 1) {
				// cout << "[" << f << ", " << i << "] ";
				check[f] = 1; // 만약에 f가 3, i가 1 그러면 3정점도 방문했고, 1정점도 방문한것
				check[i] = 1;
				cout << i << " "; // 방문한 곳 출력
				que.push(i);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> N >> M >> V;
	int num1, num2;
	for (int i = 0; i < M; i++) {
		cin >> num1 >> num2;
		connect(num1, num2); // 간선 수만큼 정점 set 받기
	}

	for (int j = 1; j <= biggest; j++) {
		sort(node[j].begin(), node[j].end());
		// 이걸 하는 이유 : 문제에 "방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고" 라고 되어 있기 때문
		// 안하게 되면 1243 으로 나올게 1423으로 나옴
	}

	DFS(V);
	fill_n(check, 1001, 0); // DFS에 썼던 check는 0으로 모두 초기화 => fill_n(배열 이름, 사이즈, 초기화할 수);
	cout << endl;
	BFS(V);
	// cout << "!";
	return 0;
}