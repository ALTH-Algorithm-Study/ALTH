#include <iostream>
using namespace std;
#define MAX_ELEMENT 100001

typedef struct {
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

int n; // 연산의 개수
int x; // 자연수 or 0

struct maxHeap {

	HeapType h = { NULL, 0 };

	void sol() {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (x > 0) {
				insert_max_heap(&h, element{ x });
			}
			else {
				if (h.heap_size == 0)
					cout << 0 << endl;
				else {
					cout << h.heap[1].key << endl;
					delete_max_heap(&h);
				}
			}
		}
	}

	void insert_max_heap(HeapType* h, element item) {
		int i;
		i = ++(h->heap_size); // 힙 크기를 하나 증가

		while ((i != 1) && (item.key > h->heap[i / 2].key)) {
			h->heap[i] = h->heap[i / 2];
			i /= 2;
		}
		h->heap[i] = item; // 새로운 노드를 삽입
	}

	element delete_max_heap(HeapType* h) {
		int parent, child;
		element item, temp;

		item = h->heap[1]; // 루트 노드 값을 반환하기 위해 item에 할당
		temp = h->heap[(h->heap_size)--]; // 마지막 노드를 temp에 할당하고 힙 크기를 하나 감소
		parent = 1;
		child = 2;

		while (child <= h->heap_size) {
			if ((child < h->heap_size) && ((h->heap[child].key) < h->heap[child + 1].key)) {
				child++;
			}
			if (temp.key >= h->heap[child].key) {
				break;
			}

			h->heap[parent] = h->heap[child];
			parent = child;
			child *= 2;
		}

		h->heap[parent] = temp;
		return item;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	struct maxHeap heap;
	heap.sol();

	return 0;
}