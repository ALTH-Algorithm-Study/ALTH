#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int> computer; // 입력 받는 위치와 가중치의 쌍 computer로 선언
int N,M;
vector<computer>graph[1001]; // 입력 받는 정보
bool visited[1001]; // 방문 여부
long long answer = 0; 

void prim()
{
	priority_queue<computer, vector<computer>, greater<computer>> pq; // 우선 순위 큐로 작은 순대로 정렬되도록 함
	pq.push({ 0,1 }); // 초기값

	while (!pq.empty()) // 비어있지 않는 동안 
	{
		//node와 가중치를 순서를 바꿔주지 않으면 오류가 나는것 같은데 왜 그런지는 모르겠네여
		int node_now = pq.top().second;
		int weight_now = pq.top().first;
		pq.pop();

		if (!visited[node_now])
		{
			visited[node_now] = true;
			answer += weight_now; // 최소 비용
			for (int i = 0; i < graph[node_now].size(); i++) // 현재 노드와 연결되어있는 값들을 큐에 삽입
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
	cin >> N >> M;
	for (int i = 0; i < M; i++) // 입력 받는 정보
	{
		cin >> start >> end >> weight;
		graph[start].push_back({ end ,weight });
		graph[end].push_back({ start,weight });
	}

	prim();

	return 0;
}