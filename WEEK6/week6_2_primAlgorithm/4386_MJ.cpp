// 별자리 만들기 (4386)
// 03.16
// 성공 (BFS랑 비슷해서 설명 많이 안달았어요)

#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#define endl "\n"
using namespace std;

int n; // 별 개수
vector<pair<double, double>> pos; // 위치(좌표)

bool check[101] = { false }; // 방문 했는가
vector<pair<int, double>> node[101]; // 연결된 정점, 그 정점과의 거리 로 넣어줄 예정
double total = 0;

double distanceCal(double n, double n2, double m, double m2) { // 거리 계산해주는 함수
	double x = n - m;
	double y = n2 - m2;
	double x2py2 = x * x + y * y;
	return sqrt(x2py2);
}

void connect() {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double dist = distanceCal(pos[i].first, pos[i].second, pos[j].first, pos[j].second);
			node[i].push_back({ j, dist });
			node[j].push_back({ i, dist }); // 쌍방향 연결
		}
	}
}

void prim() {
	priority_queue<pair<double, int>> pque; // greater로 하려고 했으나 계산이 요상하게 돼서 - 로 정렬하도록 함
	for (int i = 0; i < node[0].size(); i++) {
		// 시작 정점을 0으로 잡는다
		int next = node[0][i].first;
		double dist = node[0][i].second;
		pque.push({ -dist, next }); // 거리가 더 가까운 순으로 넣어주기;
	}

	check[0] = true; // 첫번째꺼부터 탐색
	while (!pque.empty()) {
		double dist = -pque.top().first;
		int now = pque.top().second;
		pque.pop();
		
		if (check[now] == false) {
			check[now] = true; // 방문
			total += dist;
			// cout << "now(dist), total : " << now << "(" << dist << "), " << total << endl;

			for (int i = 0; i < node[now].size(); i++) {
				int next = node[now][i].first;
				double ndist = node[now][i].second;
				if (!check[next]) {
					pque.push({ -ndist, next });
				}
			}
		}
	}
	printf("%0.2f", round(total * 100) / 100.0);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		pos.push_back({ x, y });
	}
	connect(); // 연결
	prim();

	return 0;
}