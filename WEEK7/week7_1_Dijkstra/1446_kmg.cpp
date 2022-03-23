#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define P pair<int, int>
#define INF 10000000 // 무한대
using namespace std;

int n, d; // 지름길의 개수, 고속도로의 길이
vector<P> graph[10001]; // 간선 정보
int* map;


void dijkstra() {
	int temp = -1;
	map[0] = 0;
	for (int i = 1; i <= d; i++) { // 목표지점까지 순회
		if (graph[i].size() == 0) temp = map[i - 1]; // 지름길이 없으면 이전 단계에의 값을 담는다.
		map[i] = min(map[i], temp + 1); // 이전 단계와 현재 거리의 최솟값을 현재 거리에 담는다. 

		for (auto next : graph[i]) {  // 현재 노드에서의 지름길 순회
			if (map[next.first] > map[i] + next.second) // 지름길로 갔을 때의 목적지와, 현재 지점에서 그냥 운전했을 때를 비교해 최솟값을 새로이 저장한다.
				map[next.first] = map[i] + next.second;
		}
	}
	cout << map[d] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n >> d;
	map = new int[d + 1]; // 최단 거리를 저장할 배열
	map[d] = d;

	for (int i = 0; i < n; i++) {
		int start, end, dist;
		cin >> start >> end >> dist;
		if (end - start <= dist) continue;
		if (start > d || end > d) continue;
		graph[start].push_back(make_pair(end, dist));
	}

	dijkstra();

	return 0;
}