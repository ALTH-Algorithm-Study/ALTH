#include<iostream>
using namespace std;

int main()
{
	int N, K;
	int min = 0;
	cin >> N >> K;
	int* A = new int[N]; // 동적 할당

	for (int i = 0; i < N; i++)// 동전의 가치를 입력 받음
	{
		cin >> A[i];
	}

	for (int i = N - 1; i >= 0; i--)// 동전의 가치의 내림차순으로 탐색
	{
		if (K / A[i] >= 1) // 가치의 합이 동전의 가치보다 클 경우
		{
			min += K / A[i]; // 가치의 합과 동전의 가치를 나눈 수 만큼 동전 개수 추가
			K -= (K / A[i]) * A[i]; // 가치의 합을 동전의 금액만큼 감소
		}
	}

	cout << min << endl;

	delete A; // 동적 할당 해제
	return 0;
}