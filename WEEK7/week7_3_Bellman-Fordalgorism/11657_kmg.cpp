#include <iostream>
#include <vector>
#define INF 987654321
#define endl '\n'
using namespace std;

// 벨만포드 알고리즘
/*
* 1. 모든 간선을 탐색하면서, 간선이 잇는 출발 정점이 한번이라도 계산된 정점이라면 거리를 비교해서 업데이트한다.
* 2. 모든 간선들이 정점들을 최단거리로 이을 수 있을만큼 거리를 갱신해나가며 반복한다.
* 참고 : https://yabmoons.tistory.com/365
*/

int n, m; // 도시의 개수, 도시를 경유하는 버스(간선)의 개수
//vector<int>* map ; // map의 Size를 불러올 수 없다는 단점 때문에 위 링크에 나온 자료구조를 이용해서 구현
vector<pair<pair<int, int>, int>> map;
long long* dist; // 노드의 최소 거리를 저장하는 배열

int input() {
	cin >> n >> m;
	dist = new long long[n + 1];
	for (int i = 0; i < n; i++) dist[i] = INF;
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		map.push_back(make_pair(make_pair(start, end), cost));// (start, end), cost 의 형태로 입력 
	}
}

void sol() {
	dist[1] = 0; // 첫번째 노드의 거리는 0으로 초기화한다. 
	for (int i = 1; i <= n - 1; i++) { // 루트 노드를 제외한 노드의 개수만큼 반복하여 탐색
		for (int j = 0; j < map.size(); j++) {
			int from = map[j].first.first;
			int to = map[j].first.second;
			int cost = map[j].second;

			if (dist[from] == INF) continue; // 업데이트 되지 않은 노드인 경우 패스

			if (dist[to] > dist[from] + cost) {
				// 현재 노드에서 to노드로 가는 비용의 합이 루트 노드에서 to노드로 가는 비용보다 작을 때
				// 노드의 최소 거리 정보를 업데이트
				dist[to] = dist[from] + cost;
			}
		}
	}

	for (int i = 0; i < map.size(); i++) { // 한번 더 탐색하며 음의 사이클을 갖는 그래프인지 판단
		int from = map[i].first.first;
		int to = map[i].first.second;
		int cost = map[i].second;

		if (dist[from] == INF) continue; // 업데이트 되지 않은 노드의 경우 패스
		if (dist[to] > dist[from] + cost) { // 최소비용이 업데이트 될 수 있는 노드라면 음의 사이클을 갖는 노드임.
			cout << -1 << endl;
			return;
		}
	}
}

void output() {
	for (int i = 2; i <= n; i++) {
		if (dist[i] == INF) cout << -1 << endl;
		else cout << dist[i] << endl;
	}
}

int  main() {
	input();
	sol();
	output();
}