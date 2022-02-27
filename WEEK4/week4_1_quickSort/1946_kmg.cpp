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
	ans++; // �������� 1���� ������
	sort(arr, arr + n); // arr[i].first(���� ���� ����) ���� �������� ��������

	for (int i = 1; i < n; i++) { // 1���� �����ϰ� �����ɻ� 2����� �õ����
		for (int j = i - 1; j >= 0; j--) { // 2���� 1��� ��, 3���� 1, 2��� ���ϱ� ���� ���� for�� 
			if (arr[i].second > arr[j].second) {
				break; // ������ ���ߵ��� ���� ������
			}
			else {// ���� �������� ����������, ���� ������ �� ���� �����ں��� �� ������ ���ߵ� �� �ִ� �����ڷ� ���� 
				if (j == 0) // ���� ������ ���� ���� �����ڱ��� �Ž��� �ö� ���������� ���� �������� ���� ������ �� ���ٸ� ���ߵ� �� ������ ���������� Ȯ��
					ans++;
			}
		}
	}
	cout << ans << endl;
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
	}
	return 0;
}