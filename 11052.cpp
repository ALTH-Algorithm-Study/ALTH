#include <iostream>
#include <vector>
using namespace std;

int globalSum = 0;
int N;
int* account; // ī������ ������ ���� �迭 (1���� ����)
int* result; // �� ���̽��� ���Ͽ� ���� ����� ���� �迭 
int index = 1; // result�� ��ȸ�� �� �ε���
int* a;
int** Cases;

int partition(int n, int k) {
	if (n < k) return 0;
	
	if (n == k) return globalSum += 1;
	else if (k == 1) return globalSum += 1;

	partition(n - 1, k - 1) + partition(n - k, k);
	
	return globalSum;
}

int computePartitions(int N) {
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		globalSum = 0;
		sum += partition(N, i);
	}
	return sum;
}

int** returnCases(int* a, int s, int n, int idx) {
	int i;
	static int j = 0;
	if (s == 0) {
		for (i = 0; i < idx; i++) {
			Cases[j][i] = a[i];
		}
		j++;
		return Cases;
	}

	for (int i = 1; i < n; i++) {
		if (s - i >= 0) {
			a[idx] = i;
			returnCases(a, s - i, n, idx + 1);
		}
	}
}


void sol(int N) {
	int pay = 0; 
	a = new int[N + 1]();
	int** cardPacks = returnCases(a, N, N, 0);
	int i = 0;
	for (int j = 0; j < sizeof(cardPacks)/sizeof(cardPacks[0]); j++) {
		while (cardPacks[j][i] != 0) {
			pay += account[cardPacks[j][i]];
			i++;
		}
		result[index++] = pay;
	}
}

int findMax(int* result) {
	int max = result[0];
	for (int i = 0; i < sizeof(result) / sizeof(int); i++) {
		if (max < result[i])
			max = result[i];
	}
	return max;
}


int main() {
	cin >> N;
	account = new int[N + 1]();
	for (int i = 1; i <= N; i++) {
		cin >> account[i];
	}
	int count = computePartitions(N); // ī������ ������ ���̽��� ����
	result = new int[count + 1]();

	// ī������ �̴� ����� ���� ���� ������ �迭
	Cases = new int* [count](); // ����
	for (int i = 0; i < count;  i++) { // ����
		Cases[i] = new int[N]();
	}

	sol(N); 
	cout << findMax(result) << endl;

	return 0;
}


