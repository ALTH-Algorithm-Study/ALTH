// 0224
// 좌표 정렬하기
// 성공

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<pair<int, int> > arr;
	arr.reserve(N);

	int one;
	int two;

	for (int i = 0; i < N; i++) {
		cin >> one;
		cin >> two;
		arr.push_back({ one, two });
	}

	sort(arr.begin(), arr.begin() + N);

	for (int j = 0; j < N; j++) {
		cout << arr[j].first << " " << arr[j].second << endl;
	}

	return 0;
}
