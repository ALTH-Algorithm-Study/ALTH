#include <iostream>
using namespace std;

#define MAX_ELEMENT 200

typedef struct {
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

// minHeap�� �̿��� �������� ����
struct minHeap {

	void insertMinHeap (HeapType* h, element item) {
		int i;
		i = ++(h->heap_size); // �� ũ�⸦ �ϳ� ����
		while ((i != 1) && (item.key < h->heap[i / 2].key)) {
			h->heap[i] = h->heap[i / 2];
			i /= 2;
		}
		h->heap[i] = item;
	}  

	// �ּ� ���� ���� �Լ�
	// How ??
	element deleteMinHeap(HeapType* h) {
		int parent, child;
		element item, temp;

		item = h->heap[1]; // ������ ��Ʈ ��� (minHeap�̹Ƿ� ���� ���� ����) 
		temp = h->heap[(h->heap_size)--]; // ���� ũ�⸦ �ϳ� �ٿ���
		parent = 1;  // �θ� ����� ��ġ
		child = 2; // �ڽ� ����� ��ġ

		while (child <= h->heap_size) {
			if ((child < h->heap_size) && ((h->heap[child].key) > h->heap[child + 1].key))
				child++; // ���� �ڽİ� ������ �ڽ��� ����  �������� ū ��� child�� 1�� ���� (3��° �ε����� ����)
 
			if (temp.key <= h->heap[child].key)
				break; // ���� ���� ��尡 child ��庸�� �۰� �Ǹ� Stop

			h->heap[parent] = h->heap[child]; // �θ� ����, ��, ������ ��� �� �� ū �ڽ� ��带 �ٲ�
			parent = child;
			child *= 2;
		}
		h->heap[parent] = temp;
		return item;
	}

	void print(HeapType* h) {
		for (int i = 0; i < h->heap_size; i++) {
			cout << h->heap[i].key << endl;
		}
	}

	void heap_sort(element a[], int n) {
		int i;
		HeapType h;

		for (i = 0; i < n; i++)
			insertMinHeap(&h, a[i]);

		for (i = (n - 1); i >= 0; i--) {
			a[i] = deleteMinHeap(&h);
		}
		print(&h);
	}

};

int n;
element* arr;

void init() {
	cin >> n;
	arr = new element[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].key;
	}
}

int main() {
	init();

	struct minHeap heap;
	heap.heap_sort(arr, n);

	return 0;
}

