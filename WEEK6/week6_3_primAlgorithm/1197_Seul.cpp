#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int> node; //pair로 선언
int V, E;
vector<node>graph[10001];
bool visited[10001];
long long answer = 0;

void prim()
{
	priority_queue<node, vector<node>, greater<node>> pq; // 우선 순위 큐로 오름차순으로 정렬하기 위해 greater 사용
	pq.push({ 0,1 }); // 초기값

	while (!pq.empty())
	{
		int node_now = pq.top().second;
		int weight_now = pq.top().first;
		pq.pop();

		if (!visited[node_now]) // 현재 노드를 방문하지 않았을때
		{
			visited[node_now] = true;
			answer += weight_now;
			for (int i = 0; i < graph[node_now].size(); i++)
			{
				int node_t = graph[node_now][i].first;
				int weight_t = graph[node_now][i].second;
				pq.push({ weight_t,node_t });
			}
		}
	}
	cout << answer;
}

	
int main()
{
	int start, end, weight;
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		cin >> start >> end >> weight;
		graph[start].push_back({ end ,weight});
		graph[end].push_back({ start,weight });
	}

	prim();

	return 0;
}