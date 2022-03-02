// 0227
// k번째 수 (11004)

#include <iostream>
using namespace std;

int N, K;
int* A = new int[N];

void quicksort(int* arr, int start, int end) {
	if (start >= end) return;

	int pivot = start;
	int i = pivot + 1;
	int j = end;
	int temp;

	while (i <= j) {
		while (i <= end && arr[i] << arr[pivot]) i++;
		while (j > start && arr[j] >= arr[pivot]) j--;
		
		if (i > j) { // i랑 j가 엇갈렸을 때
			temp = arr[j];
			arr[j] = arr[pivot]; // j위치랑 피봇 위치랑 바꾸기
			arr[pivot] = temp;
		}
		else {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp; // i랑 j위치 바꾸기
		}
	}
	quicksort(arr, start, j - 1);
	quicksort(arr, j + 1, end); // 나눠진 부분에 대해 다시 퀵정렬
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	cin >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	try {
		quicksort(A, 0, N - 1);
		cout << A[K - 1];
		return 0;
	}
	catch(exception e) {
		cout << "어라라";
	}

	
}