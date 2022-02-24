#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
void merge(int* U, int* V, int* arr, int h, int m);

int n, m; // 배열의 크기
int* a;
int* b;
int* arr;

void mergeSort(int * arr, int n) {
	const int h = n / 2, m = n - h;
	if (n > 1) {
		int* U = new int[h];
		int* V = new int[m];
		for (int i = 0; i < h; i++)
			U[i] = arr[i];
		for (int i = 0; i < m; i++) {
			V[i] = arr[h + i];
		}
		mergeSort(U, h);
		mergeSort(V, m);
		merge(U, V, arr, h, m);
	}

}

int* temp;

void merge(int* U, int* V, int* arr, int h, int m){
	int i = 0, j = 0 , k =0 ; // U, V, arr의 index
	while (i < h && j < m)
	{
		if (U[i] < V[j]) {
			arr[k] = U[i];
			i++; k++; 
		}
		else {
			arr[k] = V[j];
			j++; k++;
		}
	}

	if (i >= h) {
		while (j < m) {
			arr[k] = V[j];
			j++; k++;
		}
	}
	else if (j >= m) {
		while (i < h) {
			arr[k] = U[i];
			i++; k++;
		}
	}
}

void sol() {

	mergeSort(arr, n + m);

	for (int i = 0; i < n + m; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main() {

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n >> m;
	a = new int[n];
	b = new int[m];
	arr = new int[n + m];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		arr[i] = a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		arr[n + i] = b[i];
	}

	sol();
}