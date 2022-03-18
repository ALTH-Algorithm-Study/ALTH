// 네트워크 연결(1922)
// 3.18
// 성공

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define endl "\n"

int N, M; //컴퓨터의 수, 선의 수
vector<pair<int, int>> node[100001]; // {연결된 컴터, 비용}
bool check[100001] = { false };
int total = 0;

void connect(int a, int b, int c) { //  쌍방향 연결
	node[a].push_back({ b, c });
	node[b].push_back({ a, c });
}

void prim() {
	priority_queue<pair<int, int>> pque;
	for (int i = 0; i < node[1].size(); i++) { // node[1]인 이유 : 컴터는 1번부터 있음(0번 X)
		pque.push({ -node[1][i].second, node[1][i].first }); // {-비용, 컴터} => -로 넣어서 정렬
		// 더 적은 비용 드는 컴터부터 방문 => 그 컴터의 check는 true가 되어서 다시 방문 X
	}
	check[1] = true; // 이 컴터 사용함
	while (!pque.empty()) {
		int cost = -pque.top().first;
		int com = pque.top().second;
		pque.pop();

		if (!check[com]) {
			check[com] = true;
			total += cost;

			for (int i = 0; i < node[com].size(); i++) {
				int next = node[com][i].first;
				int ncost = node[com][i].second;
				if (!check[next]) pque.push({ -ncost, next });
			}
		}
	}
	cout << total;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> N >> M;

	int aa, bb, cc; // for문으로 받을 컴터, 컴터, 비용
	for (int i = 0; i < M; i++) {
		cin >> aa >> bb >> cc;
		connect(aa, bb, cc);
	}
	prim();

	return 0;
}