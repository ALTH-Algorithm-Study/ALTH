#include <iostream>
#include <vector>
#include <queue>
#define VMAX 10001
using namespace std;

vector<pair<int, int>> a[VMAX];

int solve() {
    int result = 0;;
    int v[VMAX] = { 0 };
    priority_queue<pair<int, int>> pq; // priority_queue�� ����Ͽ� ����� ������ ���� ���� ����ġ�� ���� ���� �켱������ Ž��
    pq.push({ -0, 1 }); // ��� �����ϴ��� ��������Ƿ� ���Ƿ� 1�� �������� ����.
    //�̶� 1�� ���� �湮ó�� ���� ����
    while (!pq.empty()) {
        int x = pq.top().second;
        int w = -pq.top().first;
        pq.pop();
        if (v[x] == 1) continue; // �̹� �湮�� �����̸� pass

        result += w; // ����ġ ����
        v[x] = 1; // �湮üũ
        for (int i = 0; i < a[x].size(); i++) { // �湮�� ��忡 ����� ��� ������ pq�� �߰��Ѵ�.
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