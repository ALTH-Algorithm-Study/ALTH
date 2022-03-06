// 카드 정렬하기(1715)
// 3.6~3.7
// 성공

#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> minheap; // greater => 오름차순, less<int> => 내림차순 ******** 꿀 팁스 나도 pq 함수 찾다가 발견
	
	// 원민재의 실패 작전 : 배열로 받아서 오름차순으로 정렬, 순서대로 더하기
	// 실패이유 ㅠ : 아무리 작은 것부터 더했어도 더한 값이 그 다음 값보다 클 수 있음 ex) 20 30 40 70=> 50 > 40 70 에구머니나!

	// 원민재의 작전 : 넣는대로 오름차순으로 바꿔서 제일 작은 것끼리 더할 수 있도록 한다!
	// 성공이유 : 알아서 오름차순 정렬이 됨.

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		minheap.push(num);
	}

	int answer = 0;
	int min1 = 0; int min2 = 0;
	while (minheap.size()!= 1) {
		min1 = minheap.top(); minheap.pop(); // 제일 작은 거 두 개 꺼내기
		min2 = minheap.top(); minheap.pop();
		minheap.push(min1 + min2); // 최소힙에 넣어주기 (알아서 정렬)
		answer += (min1 + min2); 
	}
	
	cout << answer;
	return 0;
}