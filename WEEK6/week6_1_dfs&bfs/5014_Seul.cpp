#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int F, S, G, U, D;
bool visited[1000001]; // 방문 여부
int button[1000001]; // 버튼 누르는 횟수

void bfs()
{
	queue<int>q;
	q.push(S);
	visited[S] = true; // 현재 위치는 방문
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (now == G) break; // 목적 위치에 도착하면 중단
		if (now + U>=1 && now + U<=F) // 1보다 크거나 같고 F보다 작거나 같아야함
		{
			if (!visited[now+U])
			{
				button[now + U] = button[now] + 1; // 현재 위치에서 누른 버튼 횟수 + 1
				q.push(now + U);
				visited[now + U] = true;
			}
		}

		if (now - D>=1 && now - D<=F) // 1보다 크거나 같고 F보다 작거나 같아야함
		{
			if (!visited[now - D])
			{
				button[now - D] = button[now] + 1; // 현재 위치에서 누른 버튼 횟수 + 1
				q.push(now - D);
				visited[now - D] = true;
			}
		}
	}
}

int main()
{
	cin >> F >> S >> G >> U >> D;
	bfs();
	if (S == G) cout << "0"; // 목적 위치가 현재 위치가 같을 경우 0 출력(이걸 몰라서 처음에 틀림ㅠ)
	else if (button[G]==0) cout << "use the stairs"; // 버튼 값이 0일때 계단 이용
	else cout << button[G]; // 버튼 사용 횟수 출력

	return 0;
}