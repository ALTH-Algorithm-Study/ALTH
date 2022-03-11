#include <iostream>
#include <vector>
#include <utility>
#define MAX 500001
#define endl "\n"
using namespace std;

/*
* �ùķ��̼��� �غ��� ��, �����̰� �̱���� ��� �������� ���� Ȧ���� �Ǿ�� �Ѵ�.
* dfs�� �̿��ؼ� depth���� ����, Ȧ���̸� Yes, ¦���̸� No�� ����Ѵ�.
*/

int n; // Ʈ���� ���� ���� 
vector<int> tree[MAX]; // Ʈ��
int totalDepth = 0; // �� ���� ����� depth�� ���� Ȧ���� Yes, ¦���� No
bool visit[MAX] = { 0 };

// ���� ������� Ȯ���ϴ� �Լ�.
// x�� 1�� ��쿡�� ��Ʈ ����̹Ƿ� ����ó��
bool isLeaf(int x) {
	return (tree[x].size() == 1 && x != 1);
}

void dfs(int x, int depth) {

	// ���� ��忡 �������� ���
	if (isLeaf(x)) {
		// ��������� depth�� totalDepth�� ����
		if (depth % 2) totalDepth += depth;
		return;
	}

	for (int i = 0; i < tree[x].size(); i++) {
		if (!visit[tree[x][i]]) {
			visit[tree[x][i]] = true; // ���� ��ġ�� ��� �湮 üũ
			dfs(tree[x][i], depth + 1);
			visit[tree[x][i]] = false; // �ʿ��� ���ȣ���� ������ false ó���ؼ� ���� ���� ��带 ã�� ���� ��ȸ�� ����Ѵ�. 
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

	visit[1] = true; // ó���� �� ���� �� �־ �׽�Ʈ�ߴٰ� ���� Ʋ�Ƚ��ϴ� ��...!
	dfs(1, 0);

	if (totalDepth % 2 == 0) cout << "No" << endl; // ¦���̸� No 
	else cout << "Yes" << endl; // Ȧ���̸� Yes

	return 0;
}