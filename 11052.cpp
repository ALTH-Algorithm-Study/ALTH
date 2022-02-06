#include <iostream>
using namespace std;

int* acc;
int* res;

int Bigger(int a, int b) {
	if (a > b)
		return a;
	return b;
}

void sol(int n) {
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			res[i] = Bigger(res[i], res[i - j] + acc[j]);
		}
	}
	cout << res[n] << endl;
}

int main() {
	int n;
	cin >> n;
	acc = new int[n + 1];
	res = new int[n + 1];
	acc[0] = res[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> acc[i];
	}

	sol(n);

	return 0;
}

/*
K���� �ִ� ī������ �ϳ� �����Ѵٰ� �������� ��, �� ���� N-K���� ī�带 �����ؾ� ��
�� res[N-K] + acc[K]�� res[N]�� ���� �ȴ�. 
*/