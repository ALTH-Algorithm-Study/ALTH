#include <iostream>
using namespace std;
#include <queue>
#include <deque>

struct MaxHeap {
	priority_queue<int> maxheap;
	int count = 0;
	deque<int> deq;

	void insert(int value) {
		try {
			if (value == 0) {
				if (maxheap.size() == 0) {
					// pri.push_back(0);
					// arr[count] = 0;
					deq.push_back(0);
					count++;
				}
				else {
					// pri.push_back(maxheap.top());
					// arr[count] = maxheap.top();
					deq.push_back(maxheap.top());
					count++;
					maxheap.pop();
				}
			}
			else {
				maxheap.push(value);
			}
		}
		catch (exception e) {
			return;
		}
	}

	void print() {
		for (int i = 0; i < count; i++) {
			// cout << deq[i];
			cout << deq.front();
			deq.pop_front();
			if (i != count - 1) cout << endl;
		}
	}
};

int main() {
	int N;
	cin >> N;
	MaxHeap answer;
	int x;

	for (int i = 0; i < N; i++) {
		cin >> x;
		answer.insert(x);
	}
	answer.print();

	return 0;
}