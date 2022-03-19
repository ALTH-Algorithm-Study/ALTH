#include <iostream>
#include <vector>
#include <queue>
#define VMAX 10001
using namespace std;

vector<pair<int, int>> a[VMAX];

int solve() {
    int result = 0;;
    int v[VMAX] = { 0 };
    priority_queue<pair<int, int>> pq; // priority_queue를 사용하여 연결된 간선중 가장 작은 가중치를 갖는 값을 우선적으로 탐색
    pq.push({ -0, 1 }); // 어디서 시작하는지 관계없으므로 임의로 1번 정점에서 시작.
    //이때 1번 노드는 방문처리 하지 않음
    while (!pq.empty()) {
        int x = pq.top().second;
        int w = -pq.top().first;
        pq.pop();
        if (v[x] == 1) continue; // 이미 방문한 정점이면 pass

        result += w; // 가중치 증가
        v[x] = 1; // 방문체크
        for (int i = 0; i < a[x].size(); i++) { // 방문한 노드에 연결된 모든 간선을 pq에 추가한다.
            int y = a[x][i].first;
            int wy = a[x][i].second;
            pq.push({ -wy,y });
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, e; cin >> n >> e;
    for (int x, y, w, i = 0; i < e; i++) {
        cin >> x >> y >> w;
        scanf("%d %d %d", &x, &y, &w);
        a[x].push_back({ y,w });
        a[y].push_back({ x,w });
    }
    cout << solve();
    return 0;
}