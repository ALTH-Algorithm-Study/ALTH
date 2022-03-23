#include <iostream>
#include <queue>
#include <vector>
using namespace std;


priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq; //cost,pos
vector<pair<int,int>> way[201];

int cost[201];
int path[201];

int main() {
    int n, m;
    int a, b, d;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> d;
        way[a].push_back({ b, d });
        way[b].push_back({ a, d });
    }

    fill_n(cost, 201, -1);
    for (int i = 1; i <= n; i++) {

        cost[i] = 0;
        pq.push({ 0, i });

        while (!pq.empty()) {
            int cost_n = pq.top().first;
            int node_n = pq.top().second;
            pq.pop();

            if (cost_n > cost[node_n])
                continue;

            for (int j = 0; j < way[node_n].size(); j++) {
                int node_now = way[node_n][j].first;
                int cost_now = cost_n + way[node_n][j].second;

                if (cost[node_now] == -1) {
                    path[node_now] = cost_n;
                    cost[node_now] = cost_now;
                    pq.push({ cost_now, node_now });
                }
                else if (cost[node_now] > cost_now) {
                    path[node_now] = node_n;
                    cost[node_now] = cost_now;
                    pq.push({ cost_now, node_now });
                }

            }
        }

        for (int j = 1; j <= n; j++) {
            if (j == i)
                cout<<"- ";
            else
            {
                int index = j;
                while (1)
                {
                    if (path[index] == i)
                    {
                        cout << index<<" ";
                        break;
                    }
                    else
                        index = path[index];
                }
            }
        }
        cout << "\n";
    }

    return 0;
}