//5014 스타트 링크
#include <iostream>
#include <queue>
using namespace std;
int F, S, G, U, D;
int visited[1000001] = { 0, };

void BFS() {
	queue <int> q;
	q.push(S);
	visited[S] = 1; //처음 위치 1

	while (!q.empty()) {
		int floor = q.front();

		if (floor == G) { // 해당 층에 도착
			cout << visited[floor] - 1 << "\n"; //시작이 1이므로
			return;
		}

		int next;

		next = floor + U;
		if (visited[next] == 0 && next <= F) {
			q.push(next); //q에 저장
			visited[next] = visited[floor] + 1; //이전 층으로부터 거리 +1
		}

		next = floor - D;
		if (visited[next] == 0 && next > 0) {
			q.push(next); //q에 저장
			visited[next] = visited[floor] + 1; //이전 층으로부터 거리 +1
		}

		q.pop();
	}

	cout << "use the stairs\n"; //이동할 수 없을 때

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> F >> S >> G >> U >> D;

	BFS();


	return 0;
}