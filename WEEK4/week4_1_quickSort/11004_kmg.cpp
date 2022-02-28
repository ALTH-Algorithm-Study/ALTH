#include <iostream>
using namespace std;
#define endl '\n'
#include <algorithm>

int n;
int k;
int* arr;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n >> k; 
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr + n);
	cout << arr[k - 1] << endl;

	return 0;
}