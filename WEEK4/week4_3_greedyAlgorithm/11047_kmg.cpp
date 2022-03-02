#include <iostream>
#define endl '\n'
using namespace std;

int n; // �ر԰� ������ �ִ� ���� ������ ��
int k; // ������ ��
int* arr; // ������ ��ġ
int cnt = 0;

void sol() {
	for (int i = n - 1; i >= 0; i--) {
		cnt = cnt + (k / arr[i]); // ���� ū �������� ������. 
		k = k % arr[i]; // k���� ���� ū ������ ����ŭ ���� ���� ���� ��´�. 
	}

	cout << cnt << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	cin >> n >> k;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sol();
}