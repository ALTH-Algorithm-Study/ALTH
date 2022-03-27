#include <iostream>
#include <vector>
#define endl '\n'
#define INF 987654321
using namespace std;

//1865 ����
// �������� �˰���

int n, m, w; // ���峪���� ����, ����, ��Ȧ�� ����
int t;  // �׽�Ʈ ���̽��� ����
vector<pair<pair<int, int>, int>> map; // ���ο� ��Ȧ�� ���� ����
int* dist; // �� ����� �ּ� ���

void input() {
	cin >> n >> m >> w;

	// Initialize
	dist = new int[n + 1];
	for (int i = 1; i < n + 1; i++) dist[i] = INF;
	map.clear(); // �� �׽�Ʈ ���̽����� ���ο� ��Ȧ�� ������ �����Ѵ�. 

	// input
	for (int j = 0; j < m; j++) { // ������ ����
		int start, end, time;
		cin >> start >> end >> time;
		map.push_back(make_pair(make_pair(start, end), time));
	}

	for (int j = 0; j < w; j++) { // ��Ȧ�� ����
		int start, end, time;
		cin >> start >> end >> time;
		map.push_back(make_pair(make_pair(start, end), -time)); // ��Ȧ�� ��� �ð��� �Ųٷ� �帥��. ������ ���·� �ð��� �����Ѵ�. 
	}

}

// ���� ����Ŭ�� �����ϴ� ��� YES�� ���, �׷��� �ʴٸ� NO�� ���
void sol() {
	dist[1] = 0;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j < map.size(); j++) {
			int from = map[j].first.first;
			int to = map[j].first.second;
			int cost = map[j].second;

			if (dist[from] == INF) continue;
			if (dist[to] > dist[from] + cost) dist[to] = dist[from] + cost;
		}
	}

	for (int i = 0; i <= n - 1; i++) {
		int from = map[i].first.first;
		int to = map[i].first.second;
		int cost = map[i].second;

		if (dist[from] == INF) continue;
		if (dist[to] > dist[from] + cost) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
	return;
}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		input();
		sol();
	}
	return 0;
}