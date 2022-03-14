#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M, V;
priority_queue<int, vector<int>, greater<int>>node_bfs[1001]; // 정점 개수가 여러개 일때는 작은것을 먼저 방문하는 걸 고려하여 우선순위 큐로 오름차순 정렬
priority_queue<int, vector<int>, greater<int>>node_dfs[1001]; // 정점 개수가 여러개 일때는 작은것을 먼저 방문하는 걸 고려하여 우선순위 큐로 오름차순 정렬
int visited_bfs[1001]; // bfs 방문 여부
int visited_dfs[1001]; // dfs 방문 여부
vector<int>dfs_answer; // dfs 방문 순서


void bfs(int start)
{
	queue<int> q;
	q.push(start); 
	visited_bfs[start] = true; // 시작 지점 방문
	while (!q.empty())
	{
		int que = q.front();
		q.pop();
		int size = node_bfs[que].size(); // 후에 pop을 진행 하므로 본래 크기를 저장하는 변수 선언
		cout << que << " ";
		for (int i = 0; i < size; i++)
		{
			int now = node_bfs[que].top(); // 탐색하는 현재 값
			node_bfs[que].pop(); 
			if (!visited_bfs[now]) // 방문 안했을때
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
				dfs_answer.push_back(now); // 쓰레기 값이 들어가는 것을 대비하여 벡터에 값을 넣어줌
				q.push(now);
				dfs(now); // bfs와 달리 재귀 함수 이용
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

	dfs_answer.push_back(V); //dfs 함수로 처음 방문 지점은 들어가지 않아 넣어줌
	dfs(V);
	for (int i = 0; i < dfs_answer.size(); i++) cout << dfs_answer[i] <<" ";
	cout << '\n';
	bfs(V);

	return 0;
}