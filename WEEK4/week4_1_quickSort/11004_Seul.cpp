#include<iostream>
#include<vector>
using namespace std;

vector<int> number;

void swap(int* x, int* y) // 교체하는 함수
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void quicksort(int start, int end)
{
	if (start >= end) return; //원소가 1개 일때
	int pivot = start; // 피벗 설정
	int left = start + 1;
	int right = end;

	while (left <= right)
	{
		while (left <= end && number[left] <= number[pivot]) left++; // left 위치가 피벗 위치보다 클때까지 left값 증가
		while (right > start && number[right] >= number[pivot]) right--; // right 위치가 피벗 위치보다 작을때까지 right 감소
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
	//반으로 나눠서 재귀함수 적용
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