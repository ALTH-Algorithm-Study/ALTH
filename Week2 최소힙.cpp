#include <iostream>
using namespace std;

#define swap(type, x, y) do {  t = x; x = y; y = t;} while(0)

static void downheap(int a[], int left, int right) { // a[left] ���� a[right] ������ heap�� �ִ� �Լ�
	int temp = a[left]; // ��Ʈ ��� 
	int child;
	int parent;

	for (parent = left; parent < (right + 1) / 2; parent = child) { // parent�� left���� �߹ݱ��� ��ȸ�� ����. 
		int cl = parent * 2 + 1; // ���� �ڽ�
		int cr = cl + 1; // ������ �ڽ�
		child = (cr <= right && a[cr] > a[cl]) ? cr : cl; // a[cr]�� a[cl]�� ��, ū ���� �����Ѵ�. 
		// cr <= right�� �ϴ� ���� : right���� cr�� �� ũ�� �ε��� �����̱� ����

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