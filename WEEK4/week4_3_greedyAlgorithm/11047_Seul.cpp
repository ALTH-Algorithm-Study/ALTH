#include<iostream>
using namespace std;

int main()
{
	int N, K;
	int min = 0;
	cin >> N >> K;
	int* A = new int[N]; // ���� �Ҵ�

	for (int i = 0; i < N; i++)// ������ ��ġ�� �Է� ����
	{
		cin >> A[i];
	}

	for (int i = N - 1; i >= 0; i--)// ������ ��ġ�� ������������ Ž��
	{
		if (K / A[i] >= 1) // ��ġ�� ���� ������ ��ġ���� Ŭ ���
		{
			min += K / A[i]; // ��ġ�� �հ� ������ ��ġ�� ���� �� ��ŭ ���� ���� �߰�
			K -= (K / A[i]) * A[i]; // ��ġ�� ���� ������ �ݾ׸�ŭ ����
		}
	}

	cout << min << endl;

	delete A; // ���� �Ҵ� ����
	return 0;
}