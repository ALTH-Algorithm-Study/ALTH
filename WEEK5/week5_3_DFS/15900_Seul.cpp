#include<iostream>
#include<vector>
using namespace std;

vector<int>tree[500001]; // Ʈ�� �Է�
int result = 0; // ������ ��
bool visited[500001]; // �湮 ����


void dfs(int n, int d)
{
	if (n != 1 && tree[n].size() == 1) // n�� 1�̸� ��Ʈ ����̰� size�� 1�� ��� ���� �����
	{
		result += d; // ��� ���� ���̸� ������
		return;
	}
	for (int i = 0; i < tree[n].size(); i++)
	{
		if (!visited[tree[n][i]])
		{
			visited[tree[n][i]] = true;
			dfs(tree[n][i], d + 1); // �ڽ� ���� �� ��� ���
			visited[tree[n][i]] = false; // ��� �ݺ��ؾ� �ϹǷ� dfs ��Ͱ� ������ �湮 ���ߴٰ� �ٲ���
		}
	}
}

int main()
{
	int N,n1,n2;
	cin >> N;
	for (int i = 0; i < N-1; i++)
	{
		cin >> n1 >> n2;
		tree[n1].push_back(n2); // ���ڿ��� ��尪�� �־���
		tree[n2].push_back(n1);
	}
	visited[1] = true; // ��Ʈ ���� �湮������
	dfs(1, 0);

	if (result % 2 == 1) cout << "Yes"; // �����̰� ���� �����ϹǷ� Ȧ�� �϶� �¸�
	else cout << "No";

	return 0;
}