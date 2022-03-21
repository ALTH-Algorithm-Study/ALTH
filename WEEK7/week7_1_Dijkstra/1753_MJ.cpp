// 최단경로 1753
// 03.20
// 성공

#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"
using namespace std;

int V, E, K; // 정점의 개수, 간선의 개수, 시작 정점의 번호
vector<pair<int, int>> node[300001];
int check[20001] = { 0 };
int length = 0;

void connect(int a, int b, int c) { //  쌍방향 연결이 아니었다. 오맛따쉬 왜 자꾸 값이 요상하게 나오나 했다.
	node[a].push_back({ b, c });
	// node[b].push_back({ a, c }); 
}

void func() { // 요기는 앞에서 한 알고리즘이랑 비슷해서 딱히 설명할 게 없는 거 같아요오,,,,
	priority_queue<pair<int, int>> pque; // { 최종 가중치, 시작점 }
	pque.push({ 0, K }); // K번째 정점부터 시작
	check[K] = 0;

	while (!pque.empty()) {
		int val = - pque.top().first;
		int now = pque.top().second;
		pque.pop();

		for (int i = 0; i < node[now].size(); i++) {
			int nval = node[now][i].second;
			int next = node[now][i].first;
			if (check[next] > nval + val) {
				// 큰 경우 : 들리지 않았을 때
				check[next] = nval + val;
				pque.push({ -nval, next });
			}
		}
	}
}

void print() {
	for (int i = 1; i <= V; i++) {
		if (check[i] == 9699999) cout << "INF" << endl;
		else if (i == K) cout << "0" << endl;
		else {
			cout << check[i] << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> V >> E >> K;

	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		connect(u, v, w);
	}

	fill_n(check, 20001, 9699999); // check 배열 초기화

	func();
	print();

	return 0;
}