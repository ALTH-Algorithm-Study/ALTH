#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int F, S, G, U, D;
bool visited[1000001]; // �湮 ����
int button[1000001]; // ��ư ������ Ƚ��

void bfs()
{
	queue<int>q;
	q.push(S);
	visited[S] = true; // ���� ��ġ�� �湮
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (now == G) break; // ���� ��ġ�� �����ϸ� �ߴ�
		if (now + U>=1 && now + U<=F) // 1���� ũ�ų� ���� F���� �۰ų� ���ƾ���
		{
			if (!visited[now+U])
			{
				button[now + U] = button[now] + 1; // ���� ��ġ���� ���� ��ư Ƚ�� + 1
				q.push(now + U);
				visited[now + U] = true;
			}
		}

		if (now - D>=1 && now - D<=F) // 1���� ũ�ų� ���� F���� �۰ų� ���ƾ���
		{
			if (!visited[now - D])
			{
				button[now - D] = button[now] + 1; // ���� ��ġ���� ���� ��ư Ƚ�� + 1
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
	if (S == G) cout << "0"; // ���� ��ġ�� ���� ��ġ�� ���� ��� 0 ���(�̰� ���� ó���� Ʋ����)
	else if (button[G]==0) cout << "use the stairs"; // ��ư ���� 0�϶� ��� �̿�
	else cout << button[G]; // ��ư ��� Ƚ�� ���

	return 0;
}