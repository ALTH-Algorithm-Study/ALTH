#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[10001];
double result = 0; // 컴퓨터를 연결하는 데 드는 최소 비용
vector<pair<int, int>> edge[10001]; // 가중치와 정점의 정보를 담은 벡터 컨테이너

double prim() {
	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<>>pq; // 오름차순으로 가중치와 정점의 정보를 담음
	pq.push(pair<int, int>(0, 1)); //1번 정점부터 시작       // 가중치가 가장작은것이 top으로 가게된다. 

	while (!pq.empty()) {
		pair<int, int> cur = pq.top();
		pq.pop();

		if (visited[cur.second]) //방문 정점 표시 
			continue;
		visited[cur.second] = 1; // 방문한 노드를 방문 처리 해준다. 

		result += cur.first; // 현재 가중치를 더해준다. 

		for (int i = 0; i < edge[cur.second].size(); i++) { //현재 정점에서 이동 할 수 있는 방문하지 않은 정점 푸쉬 
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
	} // 정점의 정보와 함께 가중치의 정보를 담는다. 

	double result = prim();
	cout << result;
	return 0;
}
