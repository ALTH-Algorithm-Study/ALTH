#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int Size[3]; // ���� �뷮
int now[3]; // ���� ����
int Next[3]; // �Լ��� ��ġ�� ���ϴ� ���� ��
vector<int> result;
bool visited[201][201][201]; // �湮�ߴ��� ����

struct bucket // ������ ��
{
	int fi;
	int se;
	int th;
};

void pour(int a, int b) // a���� b�� ���� ��������
{
	if (!Next[a]) return; // �������� �ϴ� ������ ���� ������ �н�
	if (Next[a] + Next[b] > Size[b]) // �������� �ϴ� ���� ���� ���ǰ� �� ������ ���� ���
	{
		Next[a] = Next[a] + Next[b] - Size[b]; // b�� ä��� ������
		Next[b] = Size[b]; // b�� ������ ä��
	}
	else
	{
		Next[b] += Next[a]; // b�� a�� �̵�
		Next[a] = 0; // a�� ����
	}
}

void dfs()
{
	queue<bucket>q;
	q.push({ 0,0,Size[2] }); // �ʱ� ����
	visited[0][0][Size[2]] = true; // �ʱ� ����

	while (!q.empty())
	{
		now[0] = q.front().fi;
		now[1] = q.front().se;
		now[2] = q.front().th;
		q.pop();

		if (!now[0]) result.push_back(now[2]); // ù��°�� ������� ����° ���� ����


		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i != j)//����� ���� �Ǵ������ �ϹǷ� Next�� �־� �Լ��� ����
				{
					Next[0] = now[0];
					Next[1] = now[1];
					Next[2] = now[2];
					pour(i, j);
					if (!visited[Next[0]][Next[1]][Next[2]])
					{
						visited[Next[0]][Next[1]][Next[2]] = true;
						q.push({ Next[0],Next[1],Next[2] });
					}
				}
			}
		}

	}


}

int main()
{
	cin >> Size[0] >> Size[1] >> Size[2];

	dfs();

	sort(result.begin(), result.end());//result ����
	result.erase(unique(result.begin(), result.end()), result.end()); // �ߺ��� ��������

	for (int i = 0; i < result.size(); i++)
	{
		cout<<result[i]<<" ";
	}
}