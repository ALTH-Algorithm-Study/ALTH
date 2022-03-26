// 웜홀(1865)
// 03.24-03.25.
// 성공이라 하긴 찝찝한..

#include <iostream>
#include <vector>
#define endl "\n"
#define INF 99999999
using namespace std;

// ㅋㅋㅋ... 틀린 이유 : cout에 endl 안써서...

int TC, N, M, W; // 테스트 케이스 개수, 지점 수, 도로 수, 웜홀 수
//int dist[501];
//vector<bool> answer;

/*
void connect(int a, int b, int c) {
	node[a].push_back({ b, c });
	node[b].push_back({ a, c });
} */

bool travel(vector<pair<int, pair<int, int>>> nodes) {
	int dist[501];
	fill_n(dist, 501, INF);
	dist[1] = 0; // 시작 정점(1번 정점)은 방문했다. (무한대 -> 0)
	int s, e, t;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < nodes.size(); j++) {
			s = nodes[j].first;
			e = nodes[j].second.first;
			t = nodes[j].second.second;
			if (dist[e] > dist[s] + t) {
				// 업데이트
				dist[e] = dist[s] + t;
			}
		}
	}
	// 모든 업데이트 후 시간이 줄어든지 확인
	for (int k = 0; k < nodes.size(); k++) {
		s = nodes[k].first;
		e = nodes[k].second.first;
		t = nodes[k].second.second;
		if (dist[e] > dist[s] + t) {
			return true;
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> TC;
	int S, E, T;
	
	while (TC--) {
		//fill_n(dist, 501, INF); // 무한대로 저장해두기 (TC)만큼 반복해야 하기 때문에 while안에 넣음
		vector<pair<int, pair<int, int>>> node; // 위잉 얘도 초기화 해줘야 해서 지역으로 정의했시봉

		cin >> N >> M >> W;
		//cout << "===========================" << endl;
		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T; // 도로 : 연결된 지점, 연결된 지점, 이동 시간
			node.push_back({ S, { E, T } });
			node.push_back({ E, { S, T } });
		}
		//cout << "===========================" << endl;
		for (int j = 0; j < W; j++) {
			cin >> S >> E >> T; // 웜홀 : 시작, 도착, 줄어드는 시간
			node.push_back({ S, { E, -T } }); // 웜홀 적용
		}

		if (travel(node)) cout << "YES" << endl;
		else cout << "NO" << endl;
		//cout << "===========================" << endl;
	}

	/*for (int i = 0; i < TC; i++) {
		cout << "i = " << i << " ";
		if (answer[i]) cout << "YES";
		else cout << "NO";
	}*/

	return 0;
}