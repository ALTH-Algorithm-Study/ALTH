// 1261 알고스팟
// 3.8
// 성공

// 블로그 참고 5% 했습니다.. (양심 고백) 긴 시간 동안 고민하다 check를 어떻게 해야할 지 몰라서 그 부분 참고했어요

#include <iostream>
#include <queue>
using namespace std;
#define endl "\n"

int M, N; // 가로, 세로 <- 이거 나만 헷갈림?? 여기에 30분 짱구 돌린듯,,,
int map[100][100]; // 최대 100이니까 100으로 널널하게 잡아줬어요 2차원 배열 동적할당으로 만들려면 scanf 써야하거덩요
int turn[4][2] = { {1, 0}, {0, -1}, {0, 1}, {-1, 0} }; // 우, 하, 상, 좌 순
queue<pair<int, int>> que;
int check[100][100]; // 방문했는지 여부 체크 (기본 값 : 999999991)

int counting = 0; // 부신 벽 수

void print(); // 요건 제가 제대로 배열 넣었나 확인할려고 만든 거니까 신경 안써두 됩니다

void BFS() {
	int x = 0; int y = 0; // 제가 전에 낸 maze, island 문제와 유사해유 참고 부탁~
	que.push({ x, y });
	check[x][y] = 0;
	while (!que.empty()) {
		x = que.front().first; // 위치 저장
		y = que.front().second;
		que.pop(); // 해당 위치 저장 후 지우기

		for (int i = 0; i < 4; i++) {
			int nX = x + turn[i][0];
			int nY = y + turn[i][1]; // 방향 설정
			if ((nX >= 0 && nX < M && nY >= 0 && nY < N)) { // 새로운 nx, ny가 범위를 넘지 않고
				if (map[nX][nY] == 0) { // 벽이 없을 때
					if (check[nX][nY] > check[x][y]) { // 한 번도 간 곳이 아니라면
						que.push({ nX, nY }); // 그 위치를 큐에 넣고,
						check[nX][nY] = check[x][y]; // 갔다는 뜻으로 check[x][y] 값을 넣어준다 (벽이 아니기 때문에 1을 더할 필요 X)
					}
				}
				else if (map[nX][nY] == 1) { // 벽일 때
					if (check[nX][nY] > check[x][y] + 1) { // 현재 위치의 check 값보다 1 크다면 (간 곳이 아니라면) (1을 더해주는 이유는 위치에 따라 check 값은 계속 증가하거나 같기 때문)
						que.push({ nX, nY }); // 그 위치를 큐에 넣고
						check[nX][nY] = check[x][y] + 1; // 부신 벽의 수 저장
					}
				}
				
			}
			else continue; // 범위 내에 들지 않으면 방향을 조정
		}
	}
	cout << check[M - 1][N - 1]; // 마지막 도착 지점에 부신 벽의 수가 저장되어 있을 것임
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	string num;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> num;
		for (int j = 0; j < N; j++) {
			// scanf_s("%1d", &map[i][j]); // 문자열 공백 없이 받으려 했지만 백준 이자식은 이걸 못받는다능
			map[i][j] = num[j] - '0';
			check[i][j] = 999999991; // 왕따시 큰 수 넣어주기
		}
	}
	BFS();

	return 0;
}



void print() {
	cout << "------------------" << endl;
	for (int k = 0; k < M; k++) {
		for (int l = 0; l < N; l++) {
			cout << map[l][k] << " ";
		}
		cout << endl;
	}
	cout << "------------------" << endl;
}