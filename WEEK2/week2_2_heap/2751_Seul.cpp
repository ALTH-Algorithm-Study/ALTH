#include<iostream>
using namespace std;

int num[1000000];
int temp[1000000];

void mergesort(int num[], int left, int right)
{
	if (left == right)
		return;

	int center = (left + right) / 2;

	mergesort(num, left, center);
	mergesort(num, center + 1, right);

	int p = 0; int j = 0; int k = left; int i;

	for (i = left; i <= center; i++)
	{
		temp[p++] = num[i]; // 보조 배열에 원소 대입 
	}
	while (i <= right && j < p)
	{
		num[k++] = (temp[j] <= num[i]) ? temp[j++] : num[i++];
	}
	while (j < p)
	{
		num[k++] = temp[j++];
	}

}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	mergesort(num, 0, N - 1);
	for (int i = 0; i < N; i++)
	{
		cout << num[i] << '\n';
	}
	return 0;
}