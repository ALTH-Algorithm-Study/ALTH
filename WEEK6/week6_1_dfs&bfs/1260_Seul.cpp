#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M, V;
priority_queue<int, vector<int>, greater<int>>node_bfs[1001]; // ���� ������ ������ �϶��� �������� ���� �湮�ϴ� �� ����Ͽ� �켱���� ť�� �������� ����
priority_queue<int, vector<int>, greater<int>>node_dfs[1001]; // ���� ������ ������ �϶��� �������� ���� �湮�ϴ� �� ����Ͽ� �켱���� ť�� �������� ����
int visited_bfs[1001]; // bfs �湮 ����
int visited_dfs[1001]; // dfs �湮 ����
vector<int>dfs_answer; // dfs �湮 ����


void bfs(int start)
{
	queue<int> q;
	q.push(start); 
	visited_bfs[start] = true; // ���� ���� �湮
	while (!q.empty())
	{
		int que = q.front();
		q.pop();
		int size = node_bfs[que].size(); // �Ŀ� pop�� ���� �ϹǷ� ���� ũ�⸦ �����ϴ� ���� ����
		cout << que << " ";
		for (int i = 0; i < size; i++)
		{
			int now = node_bfs[que].top(); // Ž���ϴ� ���� ��
			node_bfs[que].pop(); 
			if (!visited_bfs[now]) // �湮 ��������
			{
				q.push(now);
				visited_bfs[now] = true;
			}
		}
	}
}

void dfs(int start)
{
	queue<int> q;
	q.push(start);
	visited_dfs[start] = true;
	while (!q.empty())
	{
		int que = q.front();
		q.pop();
		int size = node_dfs[que].size();
		
		for (int i = 0; i < size; i++)
		{
			int now = node_dfs[que].top();
			node_dfs[que].pop();
			if (!visited_dfs[now])
			{
				dfs_answer.push_back(now); // ������ ���� ���� ���� ����Ͽ� ���Ϳ� ���� �־���
				q.push(now);
				dfs(now); // bfs�� �޸� ��� �Լ� �̿�
				visited_dfs[now] = true;
			}
		}
	}
}

int main()
{
	cin >> N >> M >> V;
	int node1, node2;
	for (int i = 0; i < M; i++)
	{
		cin >> node1 >> node2;
		node_bfs[node1].push(node2);
		node_bfs[node2].push(node1);
		node_dfs[node1].push(node2);
		node_dfs[node2].push(node1);
	}

	dfs_answer.push_back(V); //dfs �Լ��� ó�� �湮 ������ ���� �ʾ� �־���
	dfs(V);
	for (int i = 0; i < dfs_answer.size(); i++) cout << dfs_answer[i] <<" ";
	cout << '\n';
	bfs(V);

	return 0;
}