// 도시 분활 계획(1647)
// 3.16
// 성공

#include <iostream>
#include <queue>
#include <vector>
#define endl "\n"
using namespace std;

int N, M; // 집의 개수, 길의 개수
vector<pair<int, int>> node[100001];
bool check[100001] = { false };
int fee = 0;
int com = 0;
int last = 1;

void connect(int a, int b, int c) { //  쌍방향 연결
	node[a].push_back({b, c});
	node[b].push_back({ a, c });
}

void prim() {
	// 만약 집 1번에 3개의 집이 연결되어 있다고 할 때, 각 집에 대한 유지비가 4, 2, 3이면 유지비 2인 길만 놔두고 나머지 길 없애기
	priority_queue<pair<int, int>> pque;
	for (int i = 0; i < node[1].size(); i++) { // node[1]인 이유는 여기 문제엔 제대로 설명 안했지마논 1<=A, B<=N이기 때문
		pque.push({ -node[1][i].second, node[1][i].first }); // 유지비, 연결된 집 으로 pque에 넣기
	}
	check[1] = true; // 요긴 갔다~
	while (!pque.empty()) {
		int cost = -pque.top().first;
		int house = pque.top().second;
		pque.pop();

		if (!check[house]) {
			check[house] = true;
			// 마을을 두 개로 만들 때 한 마을에 한 집만 있어도 되니까 가장 유지비가 큰 길을 싹둑
			com = max(com, cost); // 가장 큰 유지비가 저장됨

			fee += cost;
			for (int i = 0; i < node[house].size(); i++) {
				int neighbor = node[house][i].first;
				int ncost = node[house][i].second;
				if (!check[neighbor]) pque.push({ -ncost, neighbor });
			}
		}
	}
	cout << fee - com;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	int A, B, C; // 집, 집, 두 집 연결하는 길의 유지비
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		connect(A, B, C);
	}
	prim();
	return 0;
}