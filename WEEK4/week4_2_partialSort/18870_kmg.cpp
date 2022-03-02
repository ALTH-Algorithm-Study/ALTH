#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int n; // ��ǥ�� ���� 
pair<int, int>* arr;
int cnt = 0; // push�� ����� ��ǥ ���
pair<int, int>* ans; // ����� ��ǥ

// first ���� �������� ��������
bool compare_ans(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first; // first���� �� ���� ���� ������ -> ��������
}

// second ���� �������� �������� ����
bool compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

void sol() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	sort(arr, arr + n, compare); // arr.second ���� �������� ������������ ����

	ans[0].second = 0;
	ans[0].first = arr[0].first;

	for (int i = 1; i < n; i++) {
		ans[i].first = arr[i].first;
		if (arr[i - 1].second == arr[i].second) { // ������ ���� ��ǥ�� ������ ���
			ans[i].second = cnt;
		}
		else { // ������ ���� ��ǥ�� �ٸ� ��� (���� ������)
			ans[i].second = ++cnt;
		}
	}

	sort(ans, ans + n, compare_ans); // first���� �������� �ٽ� �������� ����

	for (int i = 0; i < n; i++) {
		cout << ans[i].second << " ";
	}
	cout << endl;
}

int main() {
	cin >> n;
	arr = new pair<int, int>[n];
	ans = new pair<int, int>[n];
	for (int i = 0; i < n; i++) {
		arr[i].first = i;
		cin >> arr[i].second;
	}
	sol();

	return 0;
}