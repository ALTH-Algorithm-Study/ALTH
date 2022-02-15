#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 힙을 이용한 중앙값 구하기

/*
	priority queue는 우선순위 큐, 
	데이터들이 우선순위를 가지고 있고 우선순위가 높은 데이터들이 먼저 나간다. 

	최대 힙 : 부모 노드의 키 값이 자식 노드의 키 값보다 크거나 같은 완전 이진 트리
	최소 힙 : 자식 노드	" "		부모 노드의		"		"		"
*/

// 중앙 값을 구하는 메소드
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
			return (maxHeap.top() + minHeap.top()) / 2.0; // 중앙값을 구하여 반환
		if (maxHeap.size() < minHeap.size())
				return minHeap.top(); 

		return maxHeap.top();
	}

};
