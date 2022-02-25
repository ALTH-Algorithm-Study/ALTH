#include <iostream>
#include <utility> // pair 사용을 위한 헤더
#include <algorithm>
using namespace std;
#define endl '\n'

int  n; // 점의 개수
int* x, * y;
pair<int, int> *arr;

bool compare(pair<int, int> a, pair<int, int> b) {
	// x좌표 값이 같으면 y좌표 값을 비교해 뒤에 있는 원소가 더 후순위로 가야하는 지 검사
	if (a.first == b.first) {
		return a.second < b.second;
	} // true가 반환되면 swap할 필요가 없음
	return a.first < b.first;  // true가 반환되면 swap할 필요가 없음
}

void input() {
	cin >> n;
	arr = new pair<int, int>[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
}

void sol() {
	sort(arr, arr + n, compare);

	for (int i = 0; i < n; i++) {
		cout << arr[i].first << " " << arr[i].second << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	input();
	sol();
}
