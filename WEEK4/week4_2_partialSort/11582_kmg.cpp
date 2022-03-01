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

	int l, r, k, a; // 왼쪽 배열의 인덱스
	int mid = (left + right) / 2;
	l = left; // 왼쪽 배열의 첫 인덱스
	r = mid + 1; // 오른쪽 배열의 첫 인덱스
	k = left; // tmp라는 임시 배열의 인덱스

	while (l <= mid && r <= right) {
		tmp[k++] = arr[l] <= arr[r] ? arr[l++] : arr[r++];
	}

	while (l <= mid) tmp[k++] = arr[l++];// 오른쪽 배열의 요소가 남았을 경우
	while (r <= right) tmp[k++] = arr[r++];// 왼쪽 배열의 요소가 남았을 경우

	for (int i = left; i <= right; i++) {
		arr[i] = tmp[i]; // 변경된 tmp배열을 arr배열에 복사해준다. 
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