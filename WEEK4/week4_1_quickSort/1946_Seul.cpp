#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> member;

void swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void quicksort(int start,int end)
{
	if (start >= end) return; //member에 원소가 1개 일때
	int pivot=start;
	int left = start + 1;
	int right = end;

	while (left <= right)
	{
		while (left <= end && member[left].first <= member[pivot].first) left++;
		while (right > start&& member[right].first >= member[pivot].first) right--;
		if (left > right)
		{
			swap(&member[pivot].first, &member[right].first);
			swap(&member[pivot].second, &member[right].second);
		}
		else
		{
			swap(&member[left].first, &member[right].first);
			swap(&member[left].second, &member[right].second);
		}
	}
	quicksort(start, right - 1);
	quicksort(right + 1, end);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N;
	int document, interview;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int count = 0;
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			cin >> document >> interview;
			member.push_back(make_pair(document,interview));
		}
		quicksort(0, member.size() - 1); // 서류 심사 기준으로 정렬 했으므로 밑에서 면접 기준으로 판단

		int temp = member[0].second;//첫번재 값을 기준으로 설정
		for (int j = 0; j < N; j++)
		{
			if (temp >= member[j].second) // temp 보다 j위치 값이 작을때 j보다 서류 심사가 더 좋은 사람들보다 면접 점수가 높음을 의미 -> 채용O
			{
				count++;
				temp = member[j].second; // temp 값을 업데이트
			}
			// 그렇지 않을때는 면접과 서류가 모두 다른 지원자보다 떨어짐, 따라서 채용X
		}
		cout << count << '\n';
		member.clear();
		vector<pair<int, int>>().swap(member);//member 벡터 초기화 해주는 과정
	}


	return 0;
}