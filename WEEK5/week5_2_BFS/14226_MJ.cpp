// 이모티콘 (14226)
// 3.9
// 성공

// 힌트 : BFS 문제를 어떻게 풀었었는지 생각해보기(방문 체크, queue 사용)

#include <iostream>
using namespace std;
#include <queue>
#define endl "\n"

int S;
// now : 화면의 이모티콘 수, store : 클립보드의 이모티콘 수, times : 연산 시간
bool check[1001][1001]; // 2<=S<=1000, check[now][store]
queue<pair<pair<int, int>, int >> play; // pair<int, int, int>는 안되는 군요! {{now, store}, times}

int BFS() {
	play.push({ {1, 0}, 0 }); // 1, 0, 0 (초기)
	while (!play.empty()) {
		int n = play.front().first.first;
		int s = play.front().first.second;
		int t = play.front().second;
		play.pop();

		if (n == S) {
			return t;
		}

		if (0 < n) {
			// 1. 복사 -> check[now][now]가 없으면
			// 2. 붙여넣기 -> check[now+store][store]가 없으면
			// 3. 삭제 -> check[now-1][store]가 없으면

			if (check[n][n] == 0 && n <= 1000) { 
				play.push({ { n, n }, t + 1 }); // 복사
				check[n][n] = 1;
				//cout << "copy! (now n : "<<n<<" )";
			}
			if (s > 0 && s + n <= 1000 && check[n + s][s] == 0) {
				// 클립보드에 임티가 있다면
				play.push({ {s + n, s}, t + 1 }); // 붙여넣기
				check[s + n][s] = 1;
				//cout << "paste! (now n : " << n << " )";
			}
			if (n<=1000 && check[n - 1][s] == 0) {
				// 하나 삭제 했을 때의 경우가 있지 않았다면
				play.push({ {n - 1, s}, t + 1 }); // 삭제하기
				check[n - 1][s] = 1;
				//cout << "delete! (now n : " << n << " )";
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	cin >> S;
	check[1][0] = 1;
	cout<< BFS();

	return 0;
}
