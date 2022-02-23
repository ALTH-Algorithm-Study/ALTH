// 미로탐색

#include <iostream>
#include <queue>
#include <string>

using namespace std;
#define MAX 100

queue<pair<int, int>> que; // maze
int dir[4][2] = { {1, 0} , {0, -1} , {0,1}, {-1, 0} }; // 우하상좌
int COUNT[100][100]; // 이동거리 수이자 visited했었는지 체크
int maze[100][100]; // 001011
int N = 2; int M = 2;

void BFS() {
	int x = 0;
	int y = 0;
	que.push({ x, y });
	COUNT[x][y] = 1; // 시작 지점도 +1
	while (!que.empty()) {
		x = que.front().first;
		y = que.front().second;
		que.pop(); // 전 위치 없애기
		for (int i = 0; i < 4; i++) {
			int nextX = x + dir[i][0];
			int nextY = y + dir[i][1];
			if ((nextX >= 0) && (nextX < N) && (nextY >= 0) && (nextY < M) && (maze[nextX][nextY] == 1) && (COUNT[nextX][nextY] == 0)) {
				que.push({ nextX, nextY });
				COUNT[nextX][nextY] = COUNT[x][y] + 1;
			}
			else continue;
		}
	}
	cout << COUNT[N - 1][M - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	string num;
	
	for (int i = 0; i < N; i++) {  // ex) 001011
		cin >> num;
		for (int j = 0; j < M; j++) {
			maze[i][j] = num[j]-'0';
		}
	}
	
	BFS();
	return 0;
}

