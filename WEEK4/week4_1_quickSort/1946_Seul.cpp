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
	if (start >= end) return; //member�� ���Ұ� 1�� �϶�
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
		quicksort(0, member.size() - 1); // ���� �ɻ� �������� ���� �����Ƿ� �ؿ��� ���� �������� �Ǵ�

		int temp = member[0].second;//ù���� ���� �������� ����
		for (int j = 0; j < N; j++)
		{
			if (temp >= member[j].second) // temp ���� j��ġ ���� ������ j���� ���� �ɻ簡 �� ���� ����麸�� ���� ������ ������ �ǹ� -> ä��O
			{
				count++;
				temp = member[j].second; // temp ���� ������Ʈ
			}
			// �׷��� �������� ������ ������ ��� �ٸ� �����ں��� ������, ���� ä��X
		}
		cout << count << '\n';
		member.clear();
		vector<pair<int, int>>().swap(member);//member ���� �ʱ�ȭ ���ִ� ����
	}


	return 0;
}