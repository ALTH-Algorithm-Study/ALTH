#include<iostream>
#include<utility>
#include<queue>
#include<vector>
using namespace std;

int maze[100][100];
bool visit[100][100];
int move_count[100][100]; // 이동거리 저장 배열
vector<pair<int, int>> xy = { {0,-1},{0,1},{-1,0},{1,0} };

int main()
{
	int N, M;
	cin >> N >> M;

	char num;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> num;
			maze[i][j] = num - '0';
		}
	}

	queue<pair<int, int>> location;
	visit[0][0] = 1;
	location.push({ 0,0 });
	move_count[0][0] = 1;
	while (!location.empty())
	{
		int move_x = location.front().first;
		int move_y = location.front().second;

		location.pop();

		for (int i = 0; i < 4; i++)
		{
			int now_x = move_x + xy[i].first;
			int now_y = move_y + xy[i].second;

			if (now_x >= 0 && now_y >= 0 && now_x < N && now_y < M && !visit[now_x][now_y] && maze[now_x][now_y])
			{
				visit[now_x][now_y] = 1;
				location.push({ now_x,now_y });
				move_count[now_x][now_y] = move_count[move_x][move_y] + 1;
			}
		}
	}

	cout << move_count[N - 1][M - 1] << '\n';


	return 0;
}