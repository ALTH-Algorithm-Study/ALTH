#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int n, m;

vector<pair<int, int>>* map;
int** ans; // �ִܰŸ�
int** waypoint; // A���� B�� �̵��� �� ��ġ�� ����� ��ȣ

void sol(int start) {
	for (int i = 1; i <= n; i++) {
		ans[start][i] = INF;
		waypoint[start][i] = INF;
	}
	ans[start][start] = 0;
	waypoint[start][start] = 0;

	priority_queue<pair<int, int>, vector < pair<int, int>>, greater<pair<int, int>>> pq; // minHeap ���� (first ���� �������� ��������)
	pq.push(make_pair(0, start)); // ó�� ��带 �־��ش�. 
	while (!pq.empty()) {
		int dist = pq.top().first; // �����Ÿ�
		int current = pq.top().second; // �� ��ġ�� ��Ÿ���� �κ�
		pq.pop();
		for (int i = 0; i < map[current].size(); i++) {
			int position = map[current][i].first; // ���� �������� ��ġ
			int distance = map[current][i].second; // ���� ������� ������ ������ ��ġ
			if (ans[start][position] > ans[start][current] + distance) { // ����� �ִܰŸ����� (start,current) ������ �ִܰŸ����� �Ÿ��� ���� �� �� ������ �ִܰŸ� ������ ����
				ans[start][position] = ans[start][position] + distance;
				if (waypoint[start][current] == 0) // (start, current)�� ��ġ�� ����� ������ ���� ��
					waypoint[start][current] = position;
				else
					waypoint[start][position] = waypoint[start][current];
				pq.push(make_pair(ans[start][current], current));
			}
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m; // �������� ����, ������ ���� ���
	map = new vector<pair<int, int>>[n + 1]; // ���� ���� ���� ����
	int start, end, dist;
	for (int i = 0; i < m; i++) {
		cin >> start >> end >> dist;
		map[start].push_back(make_pair(end, dist));
		map[end].push_back(make_pair(start, dist));
	}

	sol(1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				cout << "- ";
			else
				cout << waypoint[i][j] << " ";
		}
	}

	return 0;
}