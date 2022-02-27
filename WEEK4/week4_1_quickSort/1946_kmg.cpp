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
	ans++; // 서류에서 1등한 지원자는 무조건 채용
	sort(arr, arr + n); // arr[i].first(서류 면접 순위) 값을 기준으로 오름차순

	int temp = arr[0].second; // 서류 심사 1등 지원자의 면접 순위
	for (int i = 1; i < n; i++) { // 1등을 제외하고 서류심사 2등부터 꼴등까지
		if (arr[i].second < temp) { // 탐색한 지원자의 면접 순위 중 가장 높은 순위와 비교해 더 작으면 (순위가 높으면) 채용 직원으로 간주.
			ans++; 
			temp = arr[i].second; // 면접 순위가 높은 지원자의 면접 순위 정보를 갱신
		}
	}
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
		cout << ans << endl;
	}

	return 0;
}