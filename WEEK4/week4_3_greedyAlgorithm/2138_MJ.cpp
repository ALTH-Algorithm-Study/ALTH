// 전구와 스위치
// 03.04
// 

#include <iostream>
using namespace std;

int N;
string now, make, temp;
int cnt = 0;
int answer = 999955555;

void on(int b) { // 스위치 누르는 함수(양옆, 가운데 반대로)
	if (b > 0) { // 0번째면 그 전꺼 안누름
		temp[b - 1] = (temp[b - 1] == '0') ? '1' : '0';
	}
	temp[b] = (temp[b] == '0') ? '1' : '0';
	if (b < N - 1) { // N-1번째면 그 다음꺼 안누름
		temp[b + 1] = (temp[b + 1] == '0') ? '1' : '0';
	}
}

void play(int str) {
	// play 함수를 부를 때마다 temp, cnt는 초기화해야함
	temp = now;
	cnt = 0;
	
	if (str == 0) { // for문에서 temp[0-1]은 접근할 수 없으므로 0일때 만들어주기
		on(0);
		cnt++;
	}
	for (int i = 1; i < N; i++) {
		if (temp[i - 1] != make[i - 1]) {
			on(i);
			cnt++;
		}
	}
	if (temp == make) { // 복사해둔 string과 만들어야할 string이 같으면
		answer = min(answer, cnt); // 최소인 것을 찾아야함
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	cin >> N;
	cin >> now >> make;
	temp = now;

	// 스위치를 어디서부터 눌러야할지가 중요 <- 0번째 or 1번째
	// 이유는 0번째 누르면 0, 1만 눌리고 1번째 누르면 0, 1, 2가 다 눌리기 때문

	play(0); // 즉, 0번째부터 눌렀을 때랑 
	play(1); // 1번째부터 눌렀을 때랑 함수를 돌려서
	// answer = min(answer, cnt)에 더 작은 값이 들어갈 수 있도록 하기!
	if (answer == 999955555) { // 키킼 틀렸습니다 떠서 당황했는데 불가능한 경우를 안넣었군!
		cout << -1; //  꼭 넣어주긔^~^
	}
	else {
		cout << answer;
	}

	return 0;
}