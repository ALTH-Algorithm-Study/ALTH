#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define endl '\n'

int n;
int* arr;
int k;
int* tmp;

void merge(int left, int right) {
	if (right - left > n / k) return;

	int l, r, k, a; // ���� �迭�� �ε���
	int mid = (left + right) / 2;
	l = left; // ���� �迭�� ù �ε���
	r = mid + 1; // ������ �迭�� ù �ε���
	k = left; // tmp��� �ӽ� �迭�� �ε���

	while (l <= mid && r <= right) {
		tmp[k++] = arr[l] <= arr[r] ? arr[l++] : arr[r++];
	}

	while (l <= mid) tmp[k++] = arr[l++];// ������ �迭�� ��Ұ� ������ ���
	while (r <= right) tmp[k++] = arr[r++];// ���� �迭�� ��Ұ� ������ ���

	for (int i = left; i <= right; i++) {
		arr[i] = tmp[i]; // ����� tmp�迭�� arr�迭�� �������ش�. 
	}

}

void mergeSort(int left, int right) {
	if (left == right) return;

	int mid = (left + right) / 2;
	mergeSort(left, mid);
	mergeSort(mid + 1, right);

	merge(left, right);
}

void sol() {
	mergeSort(0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n;
	arr = new int[n];
	tmp = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> k;

	sol();

	return 0;
}