#include <iostream>
#include <utility>
#include <vector>
using namespace std;
#define endl "\n"

int n;
bool* visited;
vector<int>* arr;
int* ans;

void input() {
	cin >> n;  // 노드의 개수
	visited = new bool[n + 1]; // 방문했음을 알리는 배열
	arr = new vector<int>[n + 1];
	ans = new int[n]; // 부모노드를 담을 배열

	for (int i = 0; i < n - 1; i++) {
		int p, q;
		cin >> q >> p;
		 arr[q].push_back(p);
		 arr[p].push_back(q);
	}
}

void dfs(int x) {
 	visited[x] = true;
	for (int i = 0; i < arr[x].size(); i++) {
		int next = arr[x][i]; // 인접 노드 방문
		if (ans[next] == 0) {
			ans[next] = x; // 방문하지 않은 노드 저장
			dfs(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	dfs(1);

	for (int i = 2; i <= n; i++) {
		cout << ans[i] << endl;
	}

	return 0;
}

