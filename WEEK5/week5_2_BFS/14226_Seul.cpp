#include<iostream>
#include<queue>
using namespace std;

int S;
bool visited[1001][1001];//방문했는지 여부 판단
struct icon
{
	int now;//현재 이모티콘 수
	int copy;//클립보드에 있는 이모티콘 개수
	int second;//횟수
};

int bfs()
{
	queue<icon> q;
	q.push({1,0,0});//초기 상태

	visited[1][0] = true;//초기상태는 방문

	while (!q.empty())
	{
		int now_q = q.front().now;
		int copy_q = q.front().copy;
		int second_q = q.front().second;
		q.pop();

		if (now_q == S) return second_q;

		if (now_q > 0 && now_q < 1001)
		{
			//1번
			if (!visited[now_q][now_q])
			{
				visited[now_q][now_q] = true;
				q.push({ now_q,now_q,second_q + 1 });
			}
			if (copy_q > 0 && now_q+copy_q < 1001)
			{
				//2번
				if (!visited[now_q + copy_q][copy_q])
				{
					visited[now_q + copy_q][copy_q] = true;
					q.push({now_q+copy_q,copy_q,second_q+1});
				}
			}
			//3번
			if (!visited[now_q - 1][copy_q])
			{
				visited[now_q - 1][copy_q] = true;
				q.push({now_q-1,copy_q,second_q+1});
			}

		}

	}
}

int main()
{
	cin >> S;
	int time = bfs();
	cout << time;
	return 0;
}