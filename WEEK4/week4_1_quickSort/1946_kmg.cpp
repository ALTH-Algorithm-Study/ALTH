#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define endl '\n'
using namespace std;

int t; int n;
pair<int, int> *arr; 
int ans;

void sol() {
	ans++; // �������� 1���� �����ڴ� ������ ä��
	sort(arr, arr + n); // arr[i].first(���� ���� ����) ���� �������� ��������

	int temp = arr[0].second; // ���� �ɻ� 1�� �������� ���� ����
	for (int i = 1; i < n; i++) { // 1���� �����ϰ� �����ɻ� 2����� �õ����
		if (arr[i].second < temp) { // Ž���� �������� ���� ���� �� ���� ���� ������ ���� �� ������ (������ ������) ä�� �������� ����.
			ans++; 
			temp = arr[i].second; // ���� ������ ���� �������� ���� ���� ������ ����
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		arr = new pair<int, int>[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i].first >> arr[i].second;
		}
		ans = 0;
		sol();
		cout << ans << endl;
	}

	return 0;
}