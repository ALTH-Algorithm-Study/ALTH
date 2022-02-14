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
	cin >> n;  // ����� ����
	visited = new bool[n + 1]; // �湮������ �˸��� �迭
	arr = new vector<int>[n + 1];
	ans = new int[n]; // �θ��带 ���� �迭

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
		int next = arr[x][i]; // ���� ��� �湮
		if (visited[next] != true) {
			ans[next] = x; // �湮���� ���� ��� ����
			dfs(next);
		}
		else { // �湮 �Ͽ��� ���
			continue; // �ٽ� arr[1]�� �ι��� ���Һ��� ����
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

