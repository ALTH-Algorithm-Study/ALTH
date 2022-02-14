#include <iostream>
#include <vector>
using namespace std;

int number = 7; // ����� ����
int visited[7]; // �湮������ �˸��� �迭
vector<int> a[8]; // ��� ��忡 ���� ������ ��带 ���� �� �ֵ��� ����. 

void dfs(int x) {
	if (visited[x]) return; // �̹� �湮�� ���� return
	visited[x] = true; // �湮������ check
	cout << x << ' ';
	for (int i = 0; i < a[x].size(); i++) { 
		int y = a[x][i]; // ���� ��� �湮
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