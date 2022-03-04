#include <iostream>
#define MAX 987654321
#define endl '\n'
using namespace std;

int n;
string arr;  // 처음 전구 상태
string res; // 목표 전구 상태
string temp;
int cnt = 0;
int ans = MAX;

void lightOn(int idx) {
	if (idx > 0)
		temp[idx - 1] = (temp[idx - 1] == '0') ? '1' : '0';
	temp[idx] = (temp[idx] == '0') ? '1' : '0';
	if (idx < n - 1) temp[idx + 1] = (temp[idx + 1] == '0') ? '1' : '0';
}

void sol(int first) {
	//temp = arr; // 처음 상태 저장
	//cnt = 0;

	if (first == 0) { // 처음 스위치부터 누르는 경우
		temp[0] = (temp[0] == '0') ? '1' : '0';
		temp[1] = (temp[1] == '0') ? '1' : '0';
		cnt++;
	}
	else {
		for (int i = 1; i < n; i++) { // 두번째부터 마지막까지 순회
			if (temp[i - 1] != res[i - 1]) { // 앞에 있는 전구의 상태가 다르면
				lightOn(i); // i - 1, i, i + 1 전구를 바꾼다. 
				cnt++;
			}
		}
		if (temp == res) ans = min(ans, cnt);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n >> temp >> res;

	sol(0);
	sol(1);

	if (ans != MAX) cout << ans << endl;
	else cout << -1 << endl;

	return 0;
}