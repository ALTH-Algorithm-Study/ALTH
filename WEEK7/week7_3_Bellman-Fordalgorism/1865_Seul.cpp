#include <iostream>
#include <string>
#include <vector>

#define MAX 30000000

using namespace std;

int N, M, W;

struct edge {
	int s, e, t;
};

bool time_travel(int n, vector<edge> edges) {
	vector<int> dist(n + 1, MAX);

	int s, e, t;
	dist[1] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < edges.size(); j++) {
			s = edges[j].s;
			e = edges[j].e;
			t = edges[j].t;
			if (dist[e] > dist[s] + t) {
				dist[e] = dist[s] + t;
			}
		}
	}
	for (int j = 0; j < edges.size(); j++) {
		s = edges[j].s;
		e = edges[j].e;
		t = edges[j].t;
		if (dist[e] > dist[s] + t) {
			return true;
		}
	}

	return false;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int TC;
	cin >> TC;

	int s, e, t;
	for (int j = 0; j < TC; j++) { //TC 나누기

		cin >> N >> M >> W;

		vector<edge> edges; // 정의 초기화

		for (int i = 0; i < M; i++) {
			cin >> s >> e >> t;
			edges.push_back({ s,e,t });
			edges.push_back({ e,s,t });
		}
		for (int i = 0; i < W; i++) {
			cin >> s >> e >> t;
			edges.push_back({ s,e,-t });
		}

		if (time_travel(N, edges)) cout << "YES\n"; // true일 경우
		else cout << "NO\n"; // false인 경우
	}

	return 0;
}