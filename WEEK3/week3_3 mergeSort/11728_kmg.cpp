#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int n, m; // 배열의 크기
int* a;
int* b;
int* arr;

void sol() {
	sort(arr, arr + n + m);

	for (int i = 0; i < n + m; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main() {

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n >> m;
	a = new int[n];
	b = new int[m];
	arr = new int[n + m];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		arr[i] = a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		arr[n + i] = b[i];
	}

	sol();
}