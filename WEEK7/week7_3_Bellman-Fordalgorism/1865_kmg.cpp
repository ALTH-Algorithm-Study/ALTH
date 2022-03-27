#include <iostream>
#include <vector>
#define endl '\n'
#define INF 987654321
using namespace std;

//1865 백준
// 벨만포드 알고리즘

int n, m, w; // 월드나라의 지점, 도로, 웜홀의 개수
int t;  // 테스트 케이스의 개수
vector<pair<pair<int, int>, int>> map; // 도로와 웜홀의 정보 저장
int* dist; // 각 노드의 최소 비용

void input() {
	cin >> n >> m >> w;

	// Initialize
	dist = new int[n + 1];
	for (int i = 1; i < n + 1; i++) dist[i] = INF;
	map.clear(); // 매 테스트 케이스마다 도로와 웜홀의 정보를 저장한다. 

	// input
	for (int j = 0; j < m; j++) { // 도로의 정보
		int start, end, time;
		cin >> start >> end >> time;
		map.push_back(make_pair(make_pair(start, end), time));
	}

	for (int j = 0; j < w; j++) { // 웜홀의 정보
		int start, end, time;
		cin >> start >> end >> time;
		map.push_back(make_pair(make_pair(start, end), -time)); // 웜홀의 경우 시간이 거꾸로 흐른다. 음수의 형태로 시간을 저장한다. 
	}

}

// 음의 사이클이 존재하는 경우 YES를 출력, 그렇지 않다면 NO를 출력
void sol() {
	dist[1] = 0;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j < map.size(); j++) {
			int from = map[j].first.first;
			int to = map[j].first.second;
			int cost = map[j].second;

			if (dist[from] == INF) continue;
			if (dist[to] > dist[from] + cost) dist[to] = dist[from] + cost;
		}
	}

	for (int i = 0; i <= n - 1; i++) {
		int from = map[i].first.first;
		int to = map[i].first.second;
		int cost = map[i].second;

		if (dist[from] == INF) continue;
		if (dist[to] > dist[from] + cost) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
	return;
}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		input();
		sol();
	}
	return 0;
}