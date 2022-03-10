#include <iostream>
#include <queue>
#define MAX 201
using namespace std;

int a, b, c;

bool visit[MAX][MAX] = { 0 }; // a, b, c�� �� ���� �̹� Ž���ߴ��� üũ
bool ans[MAX] = { 0 };

void dfs(int aa, int bb, int cc) {
	if (visit[aa][bb])
		return;

	if (aa == 0)
		ans[cc] = true;

	visit[aa][bb] = true;

	// from a to b 
	if (aa + bb > b)  dfs((aa + bb) - b, b, cc);
	else  dfs(0, aa + bb, cc);

	// from b to a
	if (aa + bb > a) dfs(a, (aa + bb) - a, cc);
	else dfs(aa + bb, 0, cc);

	// from c to a
	if (aa + cc > a) dfs(a, bb, (aa + cc) - a);
	else dfs(aa + cc, bb, 0);

	// from c to b
	if (cc + bb > b) dfs(aa, b, (cc + bb) - b);
	else dfs(aa, bb + cc, 0);

	// from b to c
	dfs(aa, 0, bb + cc);

	// from a to c
	dfs(0, bb, aa + cc);

}

int main() {

	// �ʱ� ����
	cin >> a >> b >> c;

	// ����
	dfs(0, 0, c);

	// ���
	for (int i = 0; i < 201; i++) {
		if (ans[i])
			cout << i << " ";
	}

	return 0;
}