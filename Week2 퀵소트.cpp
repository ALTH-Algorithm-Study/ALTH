#include <iostream>
using namespace std;

#define endl "\n"
#define swap(type, x, y) do { type  t = x; x = y; y = t;} while(0)

void quick (int a[], int left, int right) {
	int pl = left;
	int pr = right ;
	int x = a[(pl + pr) / 2];
	do {
		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;
		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);

	if (left < pr) quick(a, left, pr);
	if (pl < right) quick(a, pl, right);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	quick(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
}