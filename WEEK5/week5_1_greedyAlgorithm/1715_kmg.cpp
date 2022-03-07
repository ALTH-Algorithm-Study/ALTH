#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int num, val;
	long long result = 0;

	cin >> num;

	// minHeap�� ����� ���� �켱���� ť�� Ȱ��
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < num; i++) {
		cin >> val;
		pq.push(val); // ���� ���� �θ��忡 ���Բ� push
	}

	// ī���� ������ �� �� �̻��� ���� ��ȸ�� ���鼭 �� ���� ī�幭���� ��ģ��. 
	while (pq.size() > 1) {
		int a = pq.top();
		pq.pop();
		a += pq.top();
		pq.pop();

		// result ������ ī���� ������ ���ؼ� push�Ѵ�. 
		result += a;
		pq.push(a);
	}
	cout << result << endl;
	return 0;
}