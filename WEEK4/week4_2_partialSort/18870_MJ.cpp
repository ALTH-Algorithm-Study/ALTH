// 좌표 압축
// 3.2
// 성공

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	pair<int, int>* XN = new pair<int, int> [N]; // first = 배열에 들어가는 값, second = index 값
	int* answer = new int[N];

	for (int i = 0; i < N; i++) {
		XN[i].second = i;
		cin >> XN[i].first;
	}

	sort(XN, XN + N);

	int plus = 0; // 이거는 앞에 몇 개 있는지 count하는 수
	for (int j = 0; j < N; j++) {
		if (j != 0 && XN[j].first == XN[j - 1].first) {
		}
		else if (j != 0 && XN[j].first != XN[j - 1].first) {
			plus++; // 전이랑 같지 않으면 plus++ (대신 j=0이면 앞에 암것도 없으니까 제외)
		}
		answer[XN[j].second] = plus;
	}

	for (int k = 0; k < N; k++) {
		cout << answer[k] << " ";
	}

	return 0;
}