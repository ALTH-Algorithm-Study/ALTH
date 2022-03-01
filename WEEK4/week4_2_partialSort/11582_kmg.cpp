#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define endl '\n'

int n; // ġŲ���� ����
int* arr; // N���� ġŲ���� ���� ��ġ
int k; // ���� ������ ���� ���� ȸ������ �� 

/*
* �ǻ��ڵ�
*
* for(i�� 0���� log2K���� ��ȸ)
*	while(end != n) {
*		int start = 0;
		int end = pow(2, i);
		sort(start, end);
		start += end;
		end += end;
		if(i == log_2_k(k))
			break;
	}
*
*/

int log_2_K(int k) {
	return log(k) / log(2);
}

/*

auto partition(int start, int end) {
	int pivot = arr[start]; // pivot�� �迭�� ���� �������� ����
	int left = start + 1;
	int right = end;

	while (true) {
		while (arr[left] <= pivot && right - left > 0)
			left++;
		while (arr[right] > pivot && right - left > 0)
			right--;

		if (left == right)
			break;
		else
			swap(arr[left], arr[right]);
	}

	if (pivot > arr[right])
		swap(arr[start], arr[right]);

	return right; // ������ �κ� �迭�� ���� ������ ��ȯ
}

void quickSort(int start, int end) {
	if (end - start >= 1) {
		int iter = partition(start, end);

		quickSort(start, iter - 1);
		quickSort(iter, end);
	}

}
*/


void sol() {
	for (int i = log_2_K(n) - 1; i >= 0; i--) {  // i�� 2, 1, 0 �̷��� �������� ��ȸ�Ѵ�. 
		int gap = pow(2, log_2_K(n) - i);
		int start = 0;
		int end = gap;
		while (end <= n) { // end�� n�� �ʰ��ؼ� �����ؾ��� ���� ������ �Ѿ��� ��� 
			sort(arr + start, arr + end);
			start += gap; // ���� start�������� end�� ���� 
			end += gap; // ���� end �������� i = 2, 1, 0�� �� 1, 2, 4�� ���Ѵ�. 
			if (i == log_2_K(k)) { // ������ �������� ȸ�� ���� 2�� i�°� ��ġ�� ��
				sort(arr + start, arr + end); // break �ϱ� �� ���������� ����� start, end�� ���� ������ �����Ѵ�. 
				break;
			}
		}
		if (i == log_2_K(k))
			break;
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false) ;
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> k;

	sol();

	return 0;
}