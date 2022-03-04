#include <iostream>
#define MAX 987654321
#define endl '\n'
using namespace std;

int n;
string arr;  // ó�� ���� ����
string res; // ��ǥ ���� ����
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
	temp = arr; // ó�� ���� ����
	cnt = 0;

	if (first == 0) { // ó�� ����ġ���� ������ ���
		temp[0] = (temp[0] == '0') ? '1' : '0';
		temp[1] = (temp[1] == '0') ? '1' : '0';
		cnt++;
	}
	for (int i = 1; i < n; i++) { // �ι�°���� ���������� ��ȸ
		if (temp[i - 1] != res[i - 1]) { // �տ� �ִ� ������ ���°� �ٸ���
			lightOn(i); // i - 1, i, i + 1 ������ �ٲ۴�. 
			cnt++;
		}
	}
	if (temp == res) ans = min(ans, cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n >> arr >> res;

	sol(0);
	sol(1);

	if (ans != MAX) cout << ans << endl;
	else cout << -1 << endl;

	return 0;
}