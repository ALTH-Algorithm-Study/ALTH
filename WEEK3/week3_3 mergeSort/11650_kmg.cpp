#include <iostream>
#include <utility> // pair ����� ���� ���
#include <algorithm>
using namespace std;

int  n; // ���� ����
int* x, * y;
pair<int, int> *arr;

void swap(pair<int, int> &a, pair<int, int> &b) {
	pair<int, int> temp = a;
	a = b;
	b = temp;
}

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
	for (int i = 0; i < n; i++) {
		if (!compare(arr[i], arr[i + 1])) {
			swap(arr[i], arr[i + 1]);
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i].first << " " << arr[i].second << endl;
	}
}

int main() {
	input();
	sol();
}
