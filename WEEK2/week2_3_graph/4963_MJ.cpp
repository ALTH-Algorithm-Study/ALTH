// 섬의 개수

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int w, h;
int dir[8][2] = { {1, 0} , {0, -1} , {0,1}, {-1, 0}, {1, -1}, {1, 1}, {-1, -1}, {-1, 1} }; // 우하상좌 대각선
int COUNT[50][50]; // 방문 여부
int island[50][50]; // 바다랑 땅 넣을 배열
int numLand = 0;
queue<pair<int, int> > que;

void BFS() {
	while (!que.empty()) {
		int x = que.front().second;
		int y = que.front().first;
		que.pop();

		for (int i = 0; i < 8; i++) {
			int nextX = x + dir[i][0];
			int nextY = y + dir[i][1];
			
			if (nextX < 0 || nextY < 0 || nextX >= w || nextY >= h) continue;
			if (island[nextY][nextX] && !COUNT[nextY][nextX]) {
				que.push({ nextY,nextX });
				COUNT[nextY][nextX] = 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	numLand = 0;

	while (1) {
		cin >> w >> h;
		if ((w == 0) && (h == 0)) break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> island[i][j];
			}
		}

		for (int k = 0; k < h; k++) {
			for (int m = 0; m < w; m++) {
				if ((island[k][m]) && (!COUNT[k][m])) {
					que.push({ k, m });
					COUNT[k][m] = 1;
					BFS();
					numLand++;
				}
			}
		}
		cout << numLand << "\n";

		
		memset(COUNT, 0, sizeof(COUNT));
		memset(island, 0, sizeof(island));
	}
}
