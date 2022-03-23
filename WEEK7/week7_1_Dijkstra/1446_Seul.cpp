#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int dist[10001]; 
vector<pair<int, int>> graph[10001]; // 입력 정보

int main()
{
	int N, D;
	cin >> N >> D;

    for (int i = 0; i < D; i++)
    {
        graph[i].push_back({ i + 1,1 });
    }

    int start, end, distance;
    for (int i = 0; i < N; i++)
    {
        cin >> start >> end >> distance;
        graph[start].push_back({ end,distance });
    }

    fill_n(dist, 10001, 9876543210); // 최댓값 담아주기

    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 오름차순으로 정리
    pq.push({ 0,0 });
    dist[0] = 0; // 시작점 초기화

    while (!pq.empty())
    {
        int end = pq.top().first;
        int distance = pq.top().second;
        pq.pop();

        if (end > dist[distance]) continue; //최소를 찾아야하므로

        for (auto& i : graph[distance])
        {
            int end_now = end + i.second;
            int distance_now = i.first;
            if (end_now < dist[distance_now])
            {
                dist[distance_now] = end_now;
                pq.push({ end_now,distance_now });
            }
        }

    }

    cout << dist[D];
	return 0;
}