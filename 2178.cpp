#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <map>
using namespace std;
#define endl '\n';

int n, m;
bool v[100][100]; // ¹Ì·Î
string a[100]; 
int check[100][100] = { 0, };

void bfs(int i, int j) {
	v[i][j] = true;

	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;

		q.pop();

		for (int k = 0; k < 4; k++) {
			int newX = x + dx`
		}
	}
}


int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	bfs(0, 0);
}