// 물통(2251)
// 3.10
// 실패(어디서 틀렸을까!)

#include <iostream>
using namespace std;
#define endl "\n"
#include <vector>
#include <algorithm>

int initial[3]; // C is full
int now[3];
vector<int> answer;
bool check[201][201][201] = {false}; // 노드 방문 여부
int turn[6][2] = { {0, 1}, {0, 2}, {1, 0}, {1, 2}, {2, 0}, {2, 1} }; // 이건 BFS랑 비슷 ex: {2, 1} = C에서 B로 물 옮기기
int temp[3]; // 잠시 저장해둘 공간

void initialize(string str) {
	if (str == "i") {
		now[0] = 0; now[1] = 0; now[2] = initial[2];
	}
	if (str == "t") {
		now[0] = temp[0]; now[1] = temp[1]; now[2] = temp[2];
	}
}

int act(int depth, int one, int two) { // DFS(재귀 방법으로)
	// one : 물 퍼내는 곳, two : 물 받는 곳

	if (now[one] == 0) return 0; // 물 퍼내는 곳에 물이 없으면 안됨 
	if (now[two] == initial[two]) return 0; // 물 받는 곳이 꽉차 있으면 안됨

	if (now[one] <= initial[two] - now[two]) {
		now[two] += now[one];
		now[one] = 0; // 다 부어~
	}
	else {
		now[one] = now[one] - (initial[two] - now[two]);
		now[two] = initial[two]; // 꽉 채워~
	}

	if (check[now[0]][now[1]][now[2]] == 1) return 0;
	else check[now[0]][now[1]][now[2]] = 1;

	if (now[0] == 0) { // A 물통에 물 없으면 답에 넣기
		answer.push_back(now[2]);
		// cout << "<<" << now[2] << ">> ";
	}

	for (int j = 0; j < 3; j++) {
		temp[j] = now[j];
	}

	for (int i = 0; i < 6; i++) {
		act(depth + 1, turn[i][0], turn[i][1]);
		// initialize(); <- 원민재의 당황 시작 초기화 시키면 안되는가.....
		initialize("t"); // 그렇군 temp로 따로 빼서 초기화 해줘야하는군..!
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 3; i++) {
		cin >> initial[i];
		now[i] = initial[i];
	}

	check[initial[0]][initial[1]][initial[2]] = 1;
	answer.push_back(initial[2]);
	// 여기까진 초기 상태, 정답 저장

	for (int i = 4; i < 6; i++) {
		act(0, turn[i][0], turn[i][1]);
		initialize("i");
	}
	sort(answer.begin(), answer.end());
	auto uni = unique(answer.begin(), answer.end());
	answer.erase(uni, answer.end());
	for (auto j : answer) {
		cout << j << " ";
	}

	return 0;
}