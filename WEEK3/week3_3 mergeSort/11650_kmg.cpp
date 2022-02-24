#include <iostream>
#include <utility> // pair ����� ���� ���
#include <algorithm>
using namespace std;
#define endl '\n'

int  n; // ���� ����
int* x, * y;
pair<int, int> *arr;

bool compare(pair<int, int> a, pair<int, int> b) {
	// x��ǥ ���� ������ y��ǥ ���� ���� �ڿ� �ִ� ���Ұ� �� �ļ����� �����ϴ� �� �˻�
	if (a.first == b.first) {
		return a.second < b.second;
	} // true�� ��ȯ�Ǹ� swap�� �ʿ䰡 ����
	return a.first < b.first;  // true�� ��ȯ�Ǹ� swap�� �ʿ䰡 ����
}

void input() {
	cin >> n;
	arr = new pair<int, int>[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
}

void sol() {
	sort(arr, arr + n, compare);

	for (int i = 0; i < n; i++) {
		cout << arr[i].first << " " << arr[i].second << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	input();
	sol();
}
