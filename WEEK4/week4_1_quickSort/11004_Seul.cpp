#include<iostream>
#include<vector>
using namespace std;

vector<int> number;

void swap(int* x, int* y) // ��ü�ϴ� �Լ�
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void quicksort(int start, int end)
{
	if (start >= end) return; //���Ұ� 1�� �϶�
	int pivot = start; // �ǹ� ����
	int left = start + 1;
	int right = end;

	while (left <= right)
	{
		while (left <= end && number[left] <= number[pivot]) left++; // left ��ġ�� �ǹ� ��ġ���� Ŭ������ left�� ����
		while (right > start && number[right] >= number[pivot]) right--; // right ��ġ�� �ǹ� ��ġ���� ���������� right ����
		if (left > right) //
		{
			swap(&number[pivot], &number[right]);
			swap(&number[pivot], &number[right]);
		}
		else
		{
			swap(&number[left], &number[right]);
			swap(&number[left], &number[right]);
		}
	}
	//������ ������ ����Լ� ����
	quicksort(start, right - 1);
	quicksort(right + 1, end);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N,K,num;

	cin >> N>>K;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		number.push_back(num);
	}

	quicksort(0, number.size() - 1);

	cout << number[K];

	return 0;
}