#include<iostream>
#include<queue>
using namespace std;

int S;
bool visited[1001][1001];//�湮�ߴ��� ���� �Ǵ�
struct icon
{
	int now;//���� �̸�Ƽ�� ��
	int copy;//Ŭ�����忡 �ִ� �̸�Ƽ�� ����
	int second;//Ƚ��
};

int bfs()
{
	queue<icon> q;
	q.push({1,0,0});//�ʱ� ����

	visited[1][0] = true;//�ʱ���´� �湮

	while (!q.empty())
	{
		int now_q = q.front().now;
		int copy_q = q.front().copy;
		int second_q = q.front().second;
		q.pop();

		if (now_q == S) return second_q;

		if (now_q > 0 && now_q < 1001)
		{
			//1��
			if (!visited[now_q][now_q])
			{
				visited[now_q][now_q] = true;
				q.push({ now_q,now_q,second_q + 1 });
			}
			if (copy_q > 0 && now_q+copy_q < 1001)
			{
				//2��
				if (!visited[now_q + copy_q][copy_q])
				{
					visited[now_q + copy_q][copy_q] = true;
					q.push({now_q+copy_q,copy_q,second_q+1});
				}
			}
			//3��
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