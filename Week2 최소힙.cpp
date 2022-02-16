#include <iostream>
using namespace std;

#define swap(type, x, y) do {  t = x; x = y; y = t;} while(0)

static void downheap(int a[], int left, int right) { // a[left] 부터 a[right] 까지를 heap에 넣는 함수
	int temp = a[left]; // 루트 노드 
	int child;
	int parent;

	for (parent = left; parent < (right + 1) / 2; parent = child) { // parent는 left에서 중반까지 순회를 돈다. 
		int cl = parent * 2 + 1; // 왼쪽 자식
		int cr = cl + 1; // 오른쪽 자식
		child = (cr <= right && a[cr] > a[cl]) ? cr : cl; // a[cr]과 a[cl]을 비교, 큰 값을 선택한다. 
		// cr <= right를 하는 이유 : right보다 cr이 더 크면 인덱스 오류이기 때문

		if (temp >= a[child])
			break;
		a[parent] = a[child];
	}
	a[parent] = temp;
}

void heapsort(int a[], int n) {
	int i;
	for (i = (n - 1) / 2; i >= 0; i--) {
		downheap(a, i, n - 1);
	}
	for (i = n - 1; i > 0; i--) {
		swap(int, a[0], a[i]);
		downheap(a, 0, i - 1);
	}
}

int main() {
	int n; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	heapsort(arr, n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;

	return 0;
}