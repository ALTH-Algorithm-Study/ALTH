#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int num, val;
	long long result = 0;

	cin >> num;

	// minHeap의 기능을 가진 우선순위 큐를 활용
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < num; i++) {
		cin >> val;
		pq.push(val); // 작은 값이 부모노드에 가게끔 push
	}

	// 카드의 개수가 두 개 이상인 동안 순회를 돌면서 두 개의 카드묶음을 합친다. 
	while (pq.size() > 1) {
		int a = pq.top();
		pq.pop();
		a += pq.top();
		pq.pop();

		// result 변수에 카드의 개수를 더해서 push한다. 
		result += a;
		pq.push(a);
	}
	cout << result << endl;
	return 0;
}