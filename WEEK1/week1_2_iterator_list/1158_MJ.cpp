// 요세푸스 문제
// 1. 7 안에서 3의 배수 찾기
// 2. 마지막으로 끝난 수 다음의 수에서 *3 찾기

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	list<int> people;

	int N, K;
	int temp = 0;

	// cout << "요세푸스\n 모여있는 사람의 수(N)과 제거할 양의 정수의 배수(K)를 적으시오. :";
	cin >> N >> K;

	cout << "<";

	// N만큼 원소 생성
	for (int i = 1; i <= N; i++) {
		people.push_back(i);
	}

	auto it = people.begin();  // 반복자 생성

	for (int i = 0; i < K - 1; i++) it++;

	while (N > 0) {
		if (N == 1) {
			cout << *it << ">";
			break;
		}
		cout << *it << ", ";
		it = people.erase(it); // erase를 할 때는 it로 return 해주기
		if (it == people.end()) it = people.begin(); // circularly
		--N;
		for (int i = 0; i < K-1; i++) {
			it++;
			if (it == people.end()) it = people.begin(); // circularly - for문 안에도 if로 circularly 적용
		}
	}
}
