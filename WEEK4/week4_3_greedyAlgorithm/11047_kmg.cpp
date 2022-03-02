#include <iostream>
#define endl '\n'
using namespace std;

int n; // 준규가 가지고 있는 동전 종류의 수
int k; // 동전의 합
int* arr; // 동전의 가치
int cnt = 0;

void sol() {
	for (int i = n - 1; i >= 0; i--) {
		cnt = cnt + (k / arr[i]); // 가장 큰 동전부터 나눈다. 
		k = k % arr[i]; // k에서 가장 큰 동전의 수만큼 빼고 남는 값을 담는다. 
	}

	cout << cnt << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	cin >> n >> k;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sol();
}