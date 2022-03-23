#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int n, m;

vector<pair<int, int>>* map;
int** ans; // 최단거리
int** waypoint; // A에서 B로 이동할 때 거치는 노드의 번호

void sol(int start) {
	for (int i = 1; i <= n; i++) {
		ans[start][i] = INF;
		waypoint[start][i] = INF;
	}
	ans[start][start] = 0;
	waypoint[start][start] = 0;

	priority_queue<pair<int, int>, vector < pair<int, int>>, greater<pair<int, int>>> pq; // minHeap 선언 (first 값을 기준으로 오름차순)
	pq.push(make_pair(0, start)); // 처음 노드를 넣어준다. 
	while (!pq.empty()) {
		int dist = pq.top().first; // 누적거리
		int current = pq.top().second; // 현 위치를 나타내는 부분
		pq.pop();
		for (int i = 0; i < map[current].size(); i++) {
			int position = map[current][i].first; // 현재 집하장의 위치
			int distance = map[current][i].second; // 현재 집하장과 인접한 노드들의 위치
			if (ans[start][position] > ans[start][current] + distance) { // 저장된 최단거리보다 (start,current) 까지의 최단거리에서 거리를 더한 게 더 작으면 최단거리 정보를 갱신
				ans[start][position] = ans[start][position] + distance;
				if (waypoint[start][current] == 0) // (start, current)를 거치는 노드의 정보가 없을 때
					waypoint[start][current] = position;
				else
					waypoint[start][position] = waypoint[start][current];
				pq.push(make_pair(ans[start][current], current));
			}
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m; // 집하장의 개수, 집하장 간의 경로
	map = new vector<pair<int, int>>[n + 1]; // 노드와 간선 정보 저장
	int start, end, dist;
	for (int i = 0; i < m; i++) {
		cin >> start >> end >> dist;
		map[start].push_back(make_pair(end, dist));
		map[end].push_back(make_pair(start, dist));
	}

	sol(1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				cout << "- ";
			else
				cout << waypoint[i][j] << " ";
		}
	}

	return 0;
}