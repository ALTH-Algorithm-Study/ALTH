// 수 정렬하기 2
// 2751
// 성공

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl "\n"

int N;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	for (int i = 0; i < N; i++) {
		cout << arr[i];
		if (i != N - 1) {
			cout << endl;
		}
	}
	return 0;
}

