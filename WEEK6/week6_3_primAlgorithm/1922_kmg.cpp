#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[10001];
double result = 0; // ��ǻ�͸� �����ϴ� �� ��� �ּ� ���
vector<pair<int, int>> edge[10001]; // ����ġ�� ������ ������ ���� ���� �����̳�

double prim() {
	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<>>pq; // ������������ ����ġ�� ������ ������ ����
	pq.push(pair<int, int>(0, 1)); //1�� �������� ����       // ����ġ�� ������������ top���� ���Եȴ�. 

	while (!pq.empty()) {
		pair<int, int> cur = pq.top();
		pq.pop();

		if (visited[cur.second]) //�湮 ���� ǥ�� 
			continue;
		visited[cur.second] = 1; // �湮�� ��带 �湮 ó�� ���ش�. 

		result += cur.first; // ���� ����ġ�� �����ش�. 

		for (int i = 0; i < edge[cur.second].size(); i++) { //���� �������� �̵� �� �� �ִ� �湮���� ���� ���� Ǫ�� 
			if (!visited[edge[cur.second][i].second]) {
				pq.push(edge[cur.second][i]);
			}
		}
	}
	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int numberOfComputer, numberOfLine;
	cin >> numberOfComputer >> numberOfLine;

	for (int i = 0; i < numberOfLine; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		edge[A].push_back(pair<int, int>(C, B));
		edge[B].push_back(pair<int, int>(C, A));
	} // ������ ������ �Բ� ����ġ�� ������ ��´�. 

	double result = prim();
	cout << result;
	return 0;
}
