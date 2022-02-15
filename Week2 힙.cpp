#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// ���� �̿��� �߾Ӱ� ���ϱ�

/*
	priority queue�� �켱���� ť, 
	�����͵��� �켱������ ������ �ְ� �켱������ ���� �����͵��� ���� ������. 

	�ִ� �� : �θ� ����� Ű ���� �ڽ� ����� Ű ������ ũ�ų� ���� ���� ���� Ʈ��
	�ּ� �� : �ڽ� ���	" "		�θ� �����		"		"		"
*/

// �߾� ���� ���ϴ� �޼ҵ�
struct median {		
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;

	void insert(int data) {
		if (maxHeap.size() == 0) {
			maxHeap.push(data);
			return;
		}
		if (maxHeap.size() == minHeap.size()) {
			if (data <= get())
				maxHeap.push(data);
			else
				minHeap.push(data);

			return;
		}

		if (maxHeap.size() < minHeap.size()) {
			if (data > get()) {
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(data);
			}
			else {
				maxHeap.push(data);
			}
			return;
		}

		if (data < get()) {
			minHeap.push(maxHeap.top());
			maxHeap.pop();
			maxHeap.push(data);
		}
		else {
			minHeap.push(data);
		}
	}

	double get() {
		if (maxHeap.size() == minHeap.size())
			return (maxHeap.top() + minHeap.top()) / 2.0; // �߾Ӱ��� ���Ͽ� ��ȯ
		if (maxHeap.size() < minHeap.size())
				return minHeap.top(); 

		return maxHeap.top();
	}

};
