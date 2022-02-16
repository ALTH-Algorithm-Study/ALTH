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

int n; // ������ ����
int x; // �ڿ��� or 0

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
		i = ++(h->heap_size); // �� ũ�⸦ �ϳ� ����

		while ((i != 1) && (item.key > h->heap[i / 2].key)) {
			h->heap[i] = h->heap[i / 2];
			i /= 2;
		}
		h->heap[i] = item; // ���ο� ��带 ����
	}

	element delete_max_heap(HeapType* h) {
		int parent, child;
		element item, temp;

		item = h->heap[1]; // ��Ʈ ��� ���� ��ȯ�ϱ� ���� item�� �Ҵ�
		temp = h->heap[(h->heap_size)--]; // ������ ��带 temp�� �Ҵ��ϰ� �� ũ�⸦ �ϳ� ����
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