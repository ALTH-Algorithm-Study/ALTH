#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int n; // 좌표의 개수 
pair<int, int>* arr;
int cnt = 0; // push할 압축된 좌표 요소
pair<int, int>* ans; // 압축된 좌표

// first 값을 기준으로 오름차순
bool compare_ans(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first; // first값이 더 작은 수가 앞으로 -> 오름차순
}

// second 값을 기준으로 오름차순 정렬
bool compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

void sol() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	sort(arr, arr + n, compare); // arr.second 값을 기준으로 오름차순으로 정렬

	ans[0].second = 0;
	ans[0].first = arr[0].first;

	for (int i = 1; i < n; i++) {
		ans[i].first = arr[i].first;
		if (arr[i - 1].second == arr[i].second) { // 이전에 나온 좌표와 동일할 경우
			ans[i].second = cnt;
		}
		else { // 이전에 나온 좌표와 다를 경우 (수가 증가함)
			ans[i].second = ++cnt;
		}
	}

	sort(ans, ans + n, compare_ans); // first값을 기준으로 다시 오름차순 정렬

	for (int i = 0; i < n; i++) {
		cout << ans[i].second << " ";
	}
	cout << endl;
}

int main() {
	cin >> n;
	arr = new pair<int, int>[n];
	ans = new pair<int, int>[n];
	for (int i = 0; i < n; i++) {
		arr[i].first = i;
		cin >> arr[i].second;
	}
	sol();

	return 0;
}