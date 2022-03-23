#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

int n; // 집의 개수
int m; // 길의 개수 
vector<pair<int, int>> edge[100001];
bool visited[100001];

// 프림 알고리즘으로 구현
int sol() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 오름차순으로 정렬
	// pair 자료형으로 현재 방문하고 있는 경로의 값을 vector Container 안에 대입한다. 
	int answer = 0; // 남은 유지비의 합의 최솟값
	int maxCost = 0; // 최대 비용 
	pq.push({ 0,1 }); // 초기값

	// 방문한 장소를 순회하며 minCost를 구해 유지비의 합을 구한다. 
	for (int i = 1; i <= n; i++) {
		while (!pq.empty() && visited[pq.top().second]) {
			pq.pop();
		}
		int next = pq.top().second; // 다음으로 진행할 경유지의 비용을 가져온다. 
		int minCost = pq.top().first; // 현재 최소 비용
		maxCost = max(maxCost, minCost);
		visited[next] = true;
		answer += minCost; // 유지비에 현재의 최소 비용을 더한다. 
		for (auto o : edge[next]) {
			pq.push({ o.second,o.first });
		}
	}
	return answer - maxCost;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	// 트리의 형태로 from에서 to로 가는 경유지의 가중치 cost 입력
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		edge[from].push_back({ to ,cost });
		edge[to].push_back({ from,cost });
	}

	cout << sol();

	return 0;
}