//  카드팩의 종류 : (1) 카드 1개가 포함, (2) 카드 2개가 포함 ... (N) 카드 N개가 포함
// N개를 구매하려고 한다. 카드 i개 포함된 카드팩의 가격은 Pi

#include <iostream>
#include <vector>
using namespace std;

/*
void function(const vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
} */

int main() {
	int N; // 민규가 구매하려고 하는 카드 개수
	// cout << "카드 개수 N : ";
	cin >> N;

	int real = N + 1; // index 1부터 사용할려고!
	vector<int> Pi(real);
	Pi[0] = 0;

	// cout << "Pi~PN을 순서대로 입력 : ";
	for (int i = 1; i < Pi.size(); i++) {
		cin >> Pi[i];
	}

	vector<int> maxPi(real);

	for (int i = 1; i <= N; i++) {
		for (int k = 1; k <= i; k++) {
			if (i >= k) {
				int temp = i - k;
				maxPi[i] = max(maxPi[i], maxPi[temp] + Pi[k]);
				// cout << "i, k = " << i << ", " << k << " => " << maxPi[i] << endl;
			}

		}
	}

	cout << maxPi[N] << endl;
	return 0;
}