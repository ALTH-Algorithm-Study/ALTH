#include <iostream>
using namespace std;
#include <queue>

priority_queue<int> maxheap;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N=0;

	cin >> N;
	int x=0;

	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == 0) {
			if (maxheap.size() == 0) {
				cout << 0 << '\n';
			}
			else {
				cout << maxheap.top() << '\n';
				maxheap.pop();
			}
		}
		else {
			maxheap.push(x);
		}
	}
	
	return 0;
}