#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define endl '\n'
using namespace std;

int t; int n;
pair<int, int> *arr; 
int ans;

void sol() {
	ans++; // 서류에서 1등한 지원자
	sort(arr, arr + n); // arr[i].first(서류 면접 순위) 값을 기준으로 오름차순

	for (int i = 1; i < n; i++) { // 1등을 제외하고 서류심사 2등부터 꼴등까지
		for (int j = i - 1; j >= 0; j--) { // 2등은 1등과 비교, 3등은 1, 2등과 비교하기 위한 이중 for문 
			if (arr[i].second > arr[j].second) {
				break; // 무조건 선발되지 않을 지원자
			}
			else {// 현재 지원자의 면접순위가, 서류 순위가 더 높은 지원자보다 더 높으면 선발될 수 있는 지원자로 간주 
				if (j == 0) // 서류 순위가 제일 높은 지원자까지 거슬러 올라가 비교했음에도 현재 지원자의 면접 점수가 더 높다면 선발될 수 있음을 최종적으로 확인
					ans++;
			}
		}
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		arr = new pair<int, int>[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i].first >> arr[i].second;
		}
		ans = 0;
		sol();
	}
	return 0;
}