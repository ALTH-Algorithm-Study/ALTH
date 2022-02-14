#include <iostream>
#include <vector>
using namespace std;

int number = 7; // 노드의 개수
int visited[7]; // 방문했음을 알리는 배열
vector<int> a[8]; // 모든 노드에 대해 인접한 노드를 가질 수 있도록 설정. 

void dfs(int x) {
	if (visited[x]) return; // 이미 방문한 노드면 return
	visited[x] = true; // 방문했음을 check
	cout << x << ' ';
	for (int i = 0; i < a[x].size(); i++) { 
		int y = a[x][i]; // 인접 노드 방문
		dfs(y);
	}
}

int main() {
	a[1].push_back(2);
	a[2].push_back(1);

	a[1].push_back(3);
	a[3].push_back(1);

	dfs(1);
	return 0;
}