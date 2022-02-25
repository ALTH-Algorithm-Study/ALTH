// 배열 합치기
// 11728
// 성공

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl "\n"

int N, M;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	vector<int> Narr(N+M);

	for (int i = 0; i < N + M; i++) {
		cin >> Narr[i];
	}

	sort(Narr.begin(), Narr.end());
	for (int i = 0; i < Narr.size(); i++) {
		cout << Narr[i] << " ";
	}
	return 0;

}