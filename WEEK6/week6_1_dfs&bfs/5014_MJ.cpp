// 스타트링크(5014)
// 3.14
// 성공

#include <iostream>
#include <queue>
#include <vector>
#define endl "\n"
using namespace std;

int F, S, G, U, D; // F:건물층수, S:현재층, G:스타트링크층, U:up, D:down
int check[1000001] = { 0 };
queue<int> que;
vector<int> updown;
int nextf = -1;


int BFS(int st) {
	que.push(st);
	check[st] = 0; // 0으로 시작하는 이유 => 현재 있는 층을 방문한 건 아니지만 버튼 누른 횟수로 치진 않기 때문
	if (st != G) {
		while (!que.empty()) {
			int f = que.front();
			que.pop();
			if (f == G) {
				return check[G]; // 같으면 스타트링크 층의 check 수를 반환
			}
			// cout << f << " ";
			for (int i = 0; i < 2; i++) {
				nextf = f + updown[i];
				if (nextf == f) continue; // 이거 안넣어줘서 계속 틀렸습니다 뜸 ㅡㅡ => u이나 d이 0이면 의미가 X
				if (0 < nextf && nextf <= F && check[nextf] == 0) {  // up했을 때 최고층을 넘기면 X, down 했을 때 0층이 되면 X
					check[nextf] = check[f] + 1; // 미로찾기 처럼 횟수를 계속 늘려주는 것임
					que.push(nextf); // nextf가지고 BFS를 해라
				}

			}
		}
		return -1; // use the stairs 나오도록
	}
	else return check[G]; // 처음 시작이 G와 같다면 0출력
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> F >> S >> G >> U >> D;

	updown.push_back(U);
	updown.push_back(0 - D); // 그니까 updown vector의 [0] = up, [1] = down 키

	int answer = BFS(S);

	if (answer == -1) {
		cout << "use the stairs";
	}
	else {
		cout << answer;
	}

	return 0;
}