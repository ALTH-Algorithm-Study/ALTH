#include <iostream>
using namespace std;

int n; // Pn���� O�� ���� 
int m;
string s;
int cnt = 0;
int ans = 0; // ���ԵǾ��ִ� ��ŭ�� ���� 

void sol() {
	for (int i = 1; i < m -1 ; i++) {
		if (s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I') {
			cnt++;
			if (cnt == n) { // ������ ������ ���
				cnt--; // �ݺ��ؼ� IOI�� ������ ��츦 ����� �߰�
				ans++;
			}
			i++; // �ڷ� ��ĭ �̵��ϱ� ���� �ε��� + 1
		}
		else {
			cnt = 0; 
		}
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> s;

	sol();
	
	return 0;
}