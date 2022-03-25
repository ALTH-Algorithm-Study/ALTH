#include <iostream>
#include <vector>
#define INF 987654321
#define endl '\n'
using namespace std;

// �������� �˰���
/*
* 1. ��� ������ Ž���ϸ鼭, ������ �մ� ��� ������ �ѹ��̶� ���� �����̶�� �Ÿ��� ���ؼ� ������Ʈ�Ѵ�.
* 2. ��� �������� �������� �ִܰŸ��� ���� �� ������ŭ �Ÿ��� �����س����� �ݺ��Ѵ�.
* ���� : https://yabmoons.tistory.com/365
*/

int n, m; // ������ ����, ���ø� �����ϴ� ����(����)�� ����
//vector<int>* map ; // map�� Size�� �ҷ��� �� ���ٴ� ���� ������ �� ��ũ�� ���� �ڷᱸ���� �̿��ؼ� ����
vector<pair<pair<int, int>, int>> map;
long long* dist; // ����� �ּ� �Ÿ��� �����ϴ� �迭

int input() {
	cin >> n >> m;
	dist = new long long[n + 1];
	for (int i = 0; i < n; i++) dist[i] = INF;
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		map.push_back(make_pair(make_pair(start, end), cost));// (start, end), cost �� ���·� �Է� 
	}
}

void sol() {
	dist[1] = 0; // ù��° ����� �Ÿ��� 0���� �ʱ�ȭ�Ѵ�. 
	for (int i = 1; i <= n - 1; i++) { // ��Ʈ ��带 ������ ����� ������ŭ �ݺ��Ͽ� Ž��
		for (int j = 0; j < map.size(); j++) {
			int from = map[j].first.first;
			int to = map[j].first.second;
			int cost = map[j].second;

			if (dist[from] == INF) continue; // ������Ʈ ���� ���� ����� ��� �н�

			if (dist[to] > dist[from] + cost) {
				// ���� ��忡�� to���� ���� ����� ���� ��Ʈ ��忡�� to���� ���� ��뺸�� ���� ��
				// ����� �ּ� �Ÿ� ������ ������Ʈ
				dist[to] = dist[from] + cost;
			}
		}
	}

	for (int i = 0; i < map.size(); i++) { // �ѹ� �� Ž���ϸ� ���� ����Ŭ�� ���� �׷������� �Ǵ�
		int from = map[i].first.first;
		int to = map[i].first.second;
		int cost = map[i].second;

		if (dist[from] == INF) continue; // ������Ʈ ���� ���� ����� ��� �н�
		if (dist[to] > dist[from] + cost) { // �ּҺ���� ������Ʈ �� �� �ִ� ����� ���� ����Ŭ�� ���� �����.
			cout << -1 << endl;
			return;
		}
	}
}

void output() {
	for (int i = 2; i <= n; i++) {
		if (dist[i] == INF) cout << -1 << endl;
		else cout << dist[i] << endl;
	}
}

int  main() {
	input();
	sol();
	output();
}