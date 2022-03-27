// 택배(1719)
// 03.22
// 성공

#include <iostream>
#define endl "\n"
using namespace std;

int n, m; // 집하장의 개수, 집하장간의 경로 개수
int map[201][201] = { 0 }; // 간선 크기 넣는 배열
int check[201][201]; // 첫번째 정점 저장 배열

void connect(int a, int b, int c) { //  쌍방향 연결
	map[a][b] = c;
	map[b][a] = c;

	check[a][b] = b; // a->b 갈 때 첫번째 정점을 b라고 친다 (둘 사이 다른 정점이 없다면)
	check[b][a] = a; // b->a 갈 때 첫번째 정점을 a라고 친다
}

void parcel() {
	for (int i = 1; i <= n; i++) { // 정점 연결이 k->i->j 일 때 
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (map[j][k] > map[i][k] + map[j][i]) {  //  즉, k->j로 가는 간선 크기보다, i를 거쳐서 갈 때 간선크기가 작으면
					check[j][k] = check[j][i];  //  시작점은 i
					map[j][k] = map[i][k] + map[j][i];
				}
			}
		}
	}
}
void print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) cout << "- ";
			else cout << check[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) map[i][j] = 0; // 같은 정점에서 오가는 건 의미 X
			else map[i][j] = 99999999; // connect로 이어주지 않은 정점들은 간선 크기를 최대로
		}
	}

	int A, B, C;  // 집하장, 집하장, 걸리는 시간
	for (int i = 0; i < m; i++) {
		cin >> A >> B >> C;
		connect(A, B, C);
	}
	parcel();
	print();

	return 0;
}