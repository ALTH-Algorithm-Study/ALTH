// 풍선 터뜨리기 문제

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N; // 풍선수
	cin >> N;

	vector<pair<int, int >> ballon;
	int index = 0;
	int temp;
	int num;

	for (int i=0; i<N; i++) {
		cin >> num;
		ballon.push_back({ num, i + 1 }); // 값이랑 index를 한 쌍으로 저장
	}

	while (ballon.size() > 0) {
		cout << ballon[index].second;
		temp = ballon[index].first;  // 삭제하기 전 위치 저장
		if (temp > 0)  temp -= 1;

		ballon.erase(ballon.begin() + index);
		index += temp;
		N--;

		if (N <= 0) break; // N이 0이 되면 while문 나가기
		if (index < 0) { index = N + index % N; }
		index %= N;
		cout << " ";
	}
	return 0;
}