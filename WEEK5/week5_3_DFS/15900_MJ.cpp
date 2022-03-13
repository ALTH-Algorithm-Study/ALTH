// 나무 탈출(15900)
// 3.11
// 성공

#include <iostream>
#define endl "\n"
#include <vector>
using namespace std;
int N;
vector<int> node[500001];
int check[500001] = { 0 };
int total = 0;

bool isLeaf(int x) {
	return (node[x].size() == 1 && x != 1); // 감사합니다 민갬님
}

void DFS(int start, int depth) {
	if (isLeaf(start)) {
		if (depth % 2) total += depth;
		return;
	}

	for (int i = 0; i < node[start].size(); i++) {
		int x = node[start][i];
		if (check[x] == 0) {
			check[x] = 1; // 방문
			DFS(x, depth + 1);
			check[x] = 0;
		}
	}
}

void connect(int n1, int n2) { // 간선 연결
	node[n1].push_back(n2);
	node[n2].push_back(n1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> N;
	int num1, num2;
	
	for (int i = 0; i < N-1; i++) {
		cin >> num1 >> num2;
		connect(num1, num2);
	}
	check[1] = 1;

	DFS(1, 0); // root인 1부터 DFS하면 DFS함수에서 leaf까지 인접한 노드를 탐색하며 내려감
	
	if (total % 2 == 0) cout << "No";
	else cout << "Yes";
	// cout << " => " << total;
	return 0;
}