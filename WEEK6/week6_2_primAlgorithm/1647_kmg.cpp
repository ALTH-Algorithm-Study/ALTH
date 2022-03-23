#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;

int n; // ���� ����
int m; // ���� ���� 
vector<pair<int, int>> edge[100001];
bool visited[100001];

// ���� �˰������� ����
int sol() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // ������������ ����
	// pair �ڷ������� ���� �湮�ϰ� �ִ� ����� ���� vector Container �ȿ� �����Ѵ�. 
	int answer = 0; // ���� �������� ���� �ּڰ�
	int maxCost = 0; // �ִ� ��� 
	pq.push({ 0,1 }); // �ʱⰪ

	// �湮�� ��Ҹ� ��ȸ�ϸ� minCost�� ���� �������� ���� ���Ѵ�. 
	for (int i = 1; i <= n; i++) {
		while (!pq.empty() && visited[pq.top().second]) {
			pq.pop();
		}
		int next = pq.top().second; // �������� ������ �������� ����� �����´�. 
		int minCost = pq.top().first; // ���� �ּ� ���
		maxCost = max(maxCost, minCost);
		visited[next] = true;
		answer += minCost; // ������ ������ �ּ� ����� ���Ѵ�. 
		for (auto o : edge[next]) {
			pq.push({ o.second,o.first });
		}
	}
	return answer - maxCost;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	// Ʈ���� ���·� from���� to�� ���� �������� ����ġ cost �Է�
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		edge[from].push_back({ to ,cost });
		edge[to].push_back({ from,cost });
	}

	cout << sol();

	return 0;
}