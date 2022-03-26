#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define P pair<int, int>
#define INF 10000000 // ���Ѵ�
using namespace std;

int n, d; // �������� ����, ��ӵ����� ����
vector<P> graph[10001]; // ���� ����
int* map;


void dijkstra() {
	int temp = -1;
	map[0] = 0;
	for (int i = 1; i <= d; i++) { // ��ǥ�������� ��ȸ
		if (graph[i].size() == 0) temp = map[i - 1]; // �������� ������ ���� �ܰ迡�� ���� ��´�.
		map[i] = min(map[i], temp + 1); // ���� �ܰ�� ���� �Ÿ��� �ּڰ��� ���� �Ÿ��� ��´�. 

		for (auto next : graph[i]) {  // ���� ��忡���� ������ ��ȸ
			if (map[next.first] > map[i] + next.second) // ������� ���� ���� ��������, ���� �������� �׳� �������� ���� ���� �ּڰ��� ������ �����Ѵ�.
				map[next.first] = map[i] + next.second;
		}
	}
	cout << map[d] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n >> d;
	map = new int[d + 1]; // �ִ� �Ÿ��� ������ �迭
	map[d] = d;

	for (int i = 0; i < n; i++) {
		int start, end, dist;
		cin >> start >> end >> dist;
		if (end - start <= dist) continue;
		if (start > d || end > d) continue;
		graph[start].push_back(make_pair(end, dist));
	}

	dijkstra();

	return 0;
}