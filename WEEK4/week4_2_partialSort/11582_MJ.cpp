// 치킨 TOP N
// 3/2
// 성공

#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	int N, k;
	cin >> N;
	int* arr = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cin >> k;
	int trying = N / k; // 해당 배열을 몇 개씩 나눌지
	// -> 굳이 첨부터 정렬할 게 아니라 받은 k에 따라 결과만 출력하면 됨

	for (int i = 0; i < N; i++) {
		sort(arr + i, arr + i + trying);
		i += trying - 1;
	}

	for (int j = 0; j < N; j++) {
		cout << arr[j] << " ";
	}

	return 0;
}