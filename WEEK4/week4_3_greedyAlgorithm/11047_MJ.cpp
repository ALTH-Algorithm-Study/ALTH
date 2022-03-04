// 03.04
// 동전 0
// 성공

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	int total = 0; // 얘는 더해줄 총액
	int count = 0; // 정답

	int* coins = new int[N];
	// 배열 받기
	for (int j = 0; j < N; j++) {
		cin >> coins[j];
	}
	for (int i = N-1; i >= 0; i--) {
		if (coins[i] > K) {
			continue; // 애초에 넣을 금액이 K보다 크면 넘어가기
		}
		else {
			if (total + coins[i] <= K) { // 더한 금액이 넘어가지 않는다면
				total += coins[i]; // 더해주기
				count++; // 카운트 올리고
				i++; // *** 중복으로 더할 수 있기때문에 다시 i부터 돌릴 수 있도록
			}
			else {
				continue; // K를 넘으면 넘어가기
			}
		}
	}

	cout << count;
	return 0;
}