// 도로검문(2307)
// 03.23
// 성공

#include <iostream>
#include <queue>
#include <vector>
#define endl "\n"
using namespace std;

int N, M; // 지점의 수, 도로의 수
int check[1001];
vector<pair<int, int>> node[5001];
vector<pair<int, int>> visited; // 최단 경로에 쓰인 경로 저장하도록
int origin = 0;

void connect(int aa, int bb, int cc) {
	// 양방향
	node[aa].push_back({ bb, cc });
	node[bb].push_back({ aa, cc });
}

void road() {
	priority_queue<pair<int, int>> pq; // { -시간, 연결 정점 }
	pq.push({ 0, 1 }); // 1번 정점부터 시작
	check[1] = 0; // 1번 정점은 방문

	while (!pq.empty()) {
		int time = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (now == N) return; // 끝 노드에 방문함

		for (int i = 0; i < node[now].size(); i++) {
			int ntime = node[now][i].second;
			int next = node[now][i].first;
			if (check[next] > check[now] + ntime) { // 이 식이 성립 = now에 대한 next 정점을 가지 않음
				visited.push_back({ now, next }); // 방문한 간선 저장해두기 (최단 경로 찾을 때 방문한 간선 중에서 막으면 되니까)
				check[next] = check[now] + ntime;
				pq.push({ -check[next], next});
			}
		}
	}
}

void closingroad(int from, int to) {
	priority_queue<pair<int, int>> cpq;
	cpq.push({ 0, 1 });
	check[1] = 0;
	while (!cpq.empty()) {
		int time = -cpq.top().first;
		int now = cpq.top().second;
		cpq.pop();

		if (now == N) return; // 끝 정점에 도착하면 끝

		for (int i = 0; i < node[now].size(); i++) { // 위 함수랑 거의 동일
			int ntime = node[now][i].second;
			int next = node[now][i].first;
			if (check[next] > check[now] + ntime) {
				if (!(from == now && to == next) && !(from == next && to == from)) {
					check[next] = check[now] + ntime;
					cpq.push({ -check[next], next });
					//cout << now << " -> " << next << endl;
				}
			}
		}
	}
	//cout << "----------------" << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	/////////////// 입력
	cin >> N >> M;
	int a, b, t;
	pair<int, pair<int, int>> here = { 10000, {1, 1} }; // { 시간, 정점from, 정점to } => 시간을 작을수록, 정점은 클수록 here을 업데이트
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> t;
		connect(a, b, t);
	}

	/////////////// 검문 전 최단 시간
	fill_n(check, 1001, 99999999); // check 초기화
	road();
	if (check[N] == 99999999) {
		//cout << "어랍쇼";
		cout << "0";
		return 0; // 갈 수 없을 때 0
	} // 검문 하지 않았을 때 최단시간
	else {
		origin = check[N];
	}

	//////////////// 검문 후 지연시간
	int answer = 0;
	for (int i = 0; i < visited.size(); i++) {
		//cout << endl << visited[i].first << ", " << visited[i].second << " : " << endl;
		fill_n(check, 1001, 99999999);  // check 초기화
		closingroad(visited[i].first, visited[i].second);
		if (check[N] == 99999999) {
			cout << "-1";
			return 0;
		}
		//cout << check[N] << " ";
		answer = max(answer, check[N] - origin); // max인 이유 : 지연시간이 최대여야 하기 때문
	}
	
	cout << answer;

	return 0;
}