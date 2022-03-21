#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int> computer; // �Է� �޴� ��ġ�� ����ġ�� �� computer�� ����
int N,M;
vector<computer>graph[1001]; // �Է� �޴� ����
bool visited[1001]; // �湮 ����
long long answer = 0; 

void prim()
{
	priority_queue<computer, vector<computer>, greater<computer>> pq; // �켱 ���� ť�� ���� ����� ���ĵǵ��� ��
	pq.push({ 0,1 }); // �ʱⰪ

	while (!pq.empty()) // ������� �ʴ� ���� 
	{
		//node�� ����ġ�� ������ �ٲ����� ������ ������ ���°� ������ �� �׷����� �𸣰ڳ׿�
		int node_now = pq.top().second;
		int weight_now = pq.top().first;
		pq.pop();

		if (!visited[node_now])
		{
			visited[node_now] = true;
			answer += weight_now; // �ּ� ���
			for (int i = 0; i < graph[node_now].size(); i++) // ���� ���� ����Ǿ��ִ� ������ ť�� ����
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
	for (int i = 0; i < M; i++) // �Է� �޴� ����
	{
		cin >> start >> end >> weight;
		graph[start].push_back({ end ,weight });
		graph[end].push_back({ start,weight });
	}

	prim();

	return 0;
}