// 백준 1764 - 듣보잡

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


int main() {
	ios::sync_with_stdio(false); // c와 c++ 입출력의 synchronization => false
	cin.tie(NULL); // 이 코드를 이용해서 cin, cout 최적화
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