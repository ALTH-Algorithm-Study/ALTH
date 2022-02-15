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

// minHeap을 이용한 오름차순 정렬
struct minHeap {

	void insertMinHeap (HeapType* h, element item) {
		int i;
		i = ++(h->heap_size); // 힙 크기를 하나 증가
		while ((i != 1) && (item.key < h->heap[i / 2].key)) {
			h->heap[i] = h->heap[i / 2];
			i /= 2;
		}
		h->heap[i] = item;
	}  

	// 최소 힙의 삭제 함수
	// How ??
	element deleteMinHeap(HeapType* h) {
		int parent, child;
		element item, temp;

		item = h->heap[1]; // 삭제할 루트 노드 (minHeap이므로 가장 값이 작음) 
		temp = h->heap[(h->heap_size)--]; // 힙의 크기를 하나 줄여줌
		parent = 1;  // 부모 노드의 위치
		child = 2; // 자식 노드의 위치

		while (child <= h->heap_size) {
			if ((child < h->heap_size) && ((h->heap[child].key) > h->heap[child + 1].key))
				child++; // 왼쪽 자식과 오른쪽 자식을 비교해  오른쪽이 큰 경우 child에 1을 더함 (3번째 인덱스에 접근)
 
			if (temp.key <= h->heap[child].key)
				break; // 제일 끝의 노드가 child 노드보다 작게 되면 Stop

			h->heap[parent] = h->heap[child]; // 부모 노드와, 왼, 오른쪽 노드 중 더 큰 자식 노드를 바꿈
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

