// 타임머신(11657)
// 03.25.-26.
// 출력초과가 떠요.... 왜지....? for문 안에서 무한 루프 돌 일이 없는뎅........................?

#include <iostream>
#include <vector>
#define endl "\n"
#define INF 99999999
using namespace std;

int N, M; // 도시 개수, 버스 개수

struct bus {
	int start, end, times; // pair를 사용하지 않고 struct로 하는 방법을 알게 되었어여 좋네요
};
vector<bus> buses;

void timemachine() {
	int dist[501];
	fill_n(dist, 501, INF); // INF로 dist 배열 초기화

	int a, b, c; // 출발, 끝, 이동 시간
	dist[1] = 0; // 1번 도시가 시작

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < buses.size(); j++) {
			a = buses[j].start;
			b = buses[j].end;
			c = buses[j].times;
			if (dist[a] == INF) continue; // 업데이트를 안해도 됨 (INF니깐 = 한 번이라도 계산된 정점(얍문's coding world 벨만포드 설명 글 참고)
			if (dist[b] > dist[a] + c) {
				dist[b] = dist[a] + c; // 업데이트 (웜홀이랑 거의 유사)
			}
		}
	}

	for (int k = 0; k < buses.size(); k++) {
		a = buses[k].start;
		b = buses[k].end;
		c = buses[k].times;
		if (dist[a] == INF) continue; // 업데이트를 안해도 됨 (INF니깐 = 한 번이라도 계산된 정점(얍문's coding world 벨만포드 설명 글 참고)
		if (dist[b] > dist[a] + c) {
			cout << "-1" << endl; // 웜홀 문제가 시간을 돌릴 수 있을 때의 코드 => 타임머신 문제에서는 무한히 오래 전으로 되돌릴 수 있을 때
			return; // -1만 출력하고 종료
		}
	}

	for (int i = 2; i <= N; i++) {
		//  N-1개에 걸쳐 출력, 1 번도시에서 출발해~ 라고 써있기 때문에 2번 도시부터 탐색해주면 됨
		if (dist[i] == INF) {
			cout << "-1" << endl; // 해당 도시로 가는 경로가 없다
		}
		else cout << dist[i] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;

	int A, B, C;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		buses.push_back({ A, B, C });
	}
	
	timemachine();

	return 0;
}