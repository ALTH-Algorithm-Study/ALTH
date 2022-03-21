#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> graph[20001]; // �Է� ���� ������
int dist[20001]; 

void Dijkstra(int start) {
    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // ������������ ����
    pq.push({ 0, start }); // {weight,to} �� �����
    dist[start] = 0; // ������ 0���� �ʱ�ȭ

    while (!pq.empty()) {
        int weight = pq.top().first;
        int to = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[to].size(); i++) {
            int weight_now = weight + graph[to][i].second;
            if (weight_now < dist[graph[to][i].first]) 
            {
                dist[graph[to][i].first] = weight_now;
                pq.push({ weight_now, graph[to][i].first });
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    int start;
    cin >> start;
    int from, to, weight;
    for (int i = 0; i < E; i++) { 
        cin >> from >> to >> weight;
        graph[from].push_back({ to, weight });
    }
    fill_n(dist, 20001, 987654321); // �ִ��� ����ֱ�
    Dijkstra(start);

    for (int i = 1; i <= V; i++) 
    {
        if (dist[i] == 987654321) { // �ִ��� �����ɶ� INF�� ���
            cout << "INF" << '\n';
        }
        else {
            cout << dist[i] << '\n'; // �׷��� ������ ������ ���
        }
    }

    return 0;
}