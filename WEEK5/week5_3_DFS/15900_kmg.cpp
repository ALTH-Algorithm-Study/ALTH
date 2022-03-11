#include <iostream>
#include <vector>
#include <utility>
#define MAX 500001
#define endl "\n"
using namespace std;

/*
* 시뮬레이션을 해봤을 때, 성원이가 이기려면 모든 간선들의 합이 홀수가 되어야 한다.
* dfs를 이용해서 depth값을 내고, 홀수이면 Yes, 짝수이면 No를 출력한다.
*/

int n; // 트리의 정점 개수 
vector<int> tree[MAX]; // 트리
int totalDepth = 0; // 각 리프 노드의 depth의 합이 홀수면 Yes, 짝수면 No
bool visit[MAX] = { 0 };

// 리프 노드인지 확인하는 함수.
// x가 1인 경우에는 루트 노드이므로 예외처리
bool isLeaf(int x) {
	return (tree[x].size() == 1 && x != 1);
}

void dfs(int x, int depth) {

	// 리프 노드에 도달했을 경우
	if (isLeaf(x)) {
		// 현재까지의 depth를 totalDepth에 저장
		if (depth % 2) totalDepth += depth;
		return;
	}

	for (int i = 0; i < tree[x].size(); i++) {
		if (!visit[tree[x][i]]) {
			visit[tree[x][i]] = true; // 현재 위치한 노드 방문 체크
			dfs(tree[x][i], depth + 1);
			visit[tree[x][i]] = false; // 필요한 재귀호출이 끝나면 false 처리해서 다음 리프 노드를 찾기 위한 순회를 대비한다. 
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		tree[tmp1].push_back(tmp2);
		tree[tmp2].push_back(tmp1);
	}

	visit[1] = true; // 처음에 이 구문 안 넣어서 테스트했다가 백준 틀렸습니다 뜸...!
	dfs(1, 0);

	if (totalDepth % 2 == 0) cout << "No" << endl; // 짝수이면 No 
	else cout << "Yes" << endl; // 홀수이면 Yes

	return 0;
}