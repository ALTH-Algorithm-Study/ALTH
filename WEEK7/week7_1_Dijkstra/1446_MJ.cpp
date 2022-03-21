// 지름길 (1446)
// 3.20
// 성공

#include <iostream>
#include <queue>
#include <vector>
#define endl "\n"
using namespace std;

int N, D; // 지름길의 개수, 고속도로의 길이
vector<pair<int, int>> node[10001];
int check[10001];

int minLen = 0;
int here = 0;

void connect(int s, int e, int l) {
	// s:시작, e:끝, l:길이
	node[e].push_back({ s, l });
	// node[s].push_back({ e, l }); 쌍방향은 안돼 역주행 안되거든
}

void algo() {
	check[0] = 0; // 정점 방문

	for (int i = 1; i <= D; i++) { // 그동안 진행한 문제와 다른 점은 while을 안써도 된다는 것 => 그냥 비교만 해도 되는 거라서
		if (node[i].size() == 0) {
			check[i] = check[i - 1] + 1; // 지름길 없으면 그냥 더하면 되는 것
			// cout << check[i]<< " ";
		}
		else {
			for (int j = 0; j < node[i].size(); j++) {
				check[i] = min(check[i], check[i - 1] + 1); // (1) 그냥 더한 게 더 작은가
				check[i] = min(check[i], check[node[i][j].first] + node[i][j].second); // (2) 시작지점에 길이 더한게 더 작은가 
				// cout << check[i] << "(" << i << ", " << j << ") ";
			}
		}
	}
	cout << check[D]; // 도착지점까지 쌓인 길이
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	cin >> N >> D;
	fill_n(check, 10001, 9999999);
	int start, end, length;
	for (int i = 0; i < N; i++) {
		cin >> start >> end >> length;
		if (end > D) continue;  // 도착 지점보다 더 멀 때 : 지름길에 해당 X
		connect(start, end, length);
	}
	algo();

	return 0;
}