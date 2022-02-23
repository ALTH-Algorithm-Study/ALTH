// ¼öÃ£±â
//1920

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000000
#define endl "\n"
int* A = new int[MAX];
int N, M;

void find(int compare) {
	int l = 0, r = N - 1;
	if (compare > A[r] || compare < A[l]) {
		cout << 0 << endl;
		return;
	}
	while (l <= r) {
		int mid = (l + r) / 2;
		//cout << "mid = " << A[mid] << endl;
		if (compare == A[mid]) {
			cout << 1 << endl;
			return;
		}
		else {
			if (A[mid] < compare) l = mid + 1;
			else if (A[mid] > compare) r = mid - 1;
		}
	}
	cout << 0 << endl;
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int* MA = new int[MAX];
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> MA[i];
		find(MA[i]);
	}

	return 0;
}