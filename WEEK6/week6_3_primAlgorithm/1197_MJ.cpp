// 최소 스패닝 트리(1197)
// 3.18
// 성공

#include <iostream>
#include <queue>
#include <vector>
#define endl "\n"
using namespace std;

int V, E; // 정점의 개수, 간선의 개수
vector<pair<int, int>> node[100001]; // {연결된 컴터, 비용}
bool check[10001] = { false };
int value = 0;

void connect(int a, int b, int c) { //  쌍방향 연결
	node[a].push_back({ b, c });
	node[b].push_back({ a, c });
}

void prim() {
	priority_queue<pair<int, int>> pque;
	for (int i = 0; i < node[1].size(); i++) { // 그래프의 정점 : 1 ~ V
		pque.push({ -node[1][i].second, node[1][i].first }); // {-비용, 컴터} => -로 넣어서 정렬
	}
	check[1] = true; // 정점 방문

	while (!pque.empty()) {
		int val = -pque.top().first;
		int now = pque.top().second;
		pque.pop();

		if (!check[now]) {
			check[now] = true;
			value += val;

			for (int i = 0; i < node[now].size(); i++) {
				int next = node[now][i].first;
				int nval = node[now][i].second;
				if (!check[next]) pque.push({ -nval, next });
			}
		}
	}
	cout << value;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> V >> E;

	int A, B, C;
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		connect(A, B, C);
	}
	prim();

	return 0;
}