// ���� 1764 - �躸��

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


int main() {
	ios::sync_with_stdio(false); // c�� c++ ������� synchronization => false
	cin.tie(NULL); // �� �ڵ带 �̿��ؼ� cin, cout ����ȭ
	cout.tie(NULL);

	int N, M;
	string Mstr;

	cin >> N >> M;

	vector<string> list(N);
	vector<string> result;

	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	sort(list.begin(), list.end());

	for (int k = 0; k < M; k++) {
		cin >> Mstr;
		if (binary_search(list.begin(), list.end(), Mstr)) {
			result.push_back(Mstr);
		}
	}
	
	sort(result.begin(), result.end());
	auto last = result.end() - 1;
	cout << result.size() << endl;
	for (auto n = result.begin(); n < result.end(); n++) {
		cout << *n;
		if (n != last) cout << endl;
	}
}