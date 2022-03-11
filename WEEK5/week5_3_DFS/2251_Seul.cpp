#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int Size[3]; // 물통 용량
int now[3]; // 현재 물양
int Next[3]; // 함수를 거치며 변하는 물의 양
vector<int> result;
bool visited[201][201][201]; // 방문했는지 여부

struct bucket // 물통의 양
{
	int fi;
	int se;
	int th;
};

void pour(int a, int b) // a에서 b로 물을 부을거임
{
	if (!Next[a]) return; // 부으려고 하는 물통의 물이 없으면 패스
	if (Next[a] + Next[b] > Size[b]) // 부으려고 하는 곳의 통의 부피가 총 물보다 작을 경우
	{
		Next[a] = Next[a] + Next[b] - Size[b]; // b를 채우고 나머지
		Next[b] = Size[b]; // b에 끝까지 채움
	}
	else
	{
		Next[b] += Next[a]; // b에 a를 이동
		Next[a] = 0; // a는 없음
	}
}

void dfs()
{
	queue<bucket>q;
	q.push({ 0,0,Size[2] }); // 초기 상태
	visited[0][0][Size[2]] = true; // 초기 상태

	while (!q.empty())
	{
		now[0] = q.front().fi;
		now[1] = q.front().se;
		now[2] = q.front().th;
		q.pop();

		if (!now[0]) result.push_back(now[2]); // 첫번째가 비었을때 세번째 상태 넣음


		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i != j)//경우의 수를 판단해줘야 하므로 Next에 넣어 함수를 돌림
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

	sort(result.begin(), result.end());//result 정렬
	result.erase(unique(result.begin(), result.end()), result.end()); // 중복값 삭제해줌

	for (int i = 0; i < result.size(); i++)
	{
		cout<<result[i]<<" ";
	}
}