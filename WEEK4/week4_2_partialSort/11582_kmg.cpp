#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define endl '\n'

int n; // 치킨집의 개수
int* arr; // N개의 치킨집의 맛의 수치
int k; // 현재 정렬을 진행 중인 회원들의 수 

/*
* 의사코드
*
* for(i는 0부터 log2K까지 순회)
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
	int pivot = arr[start]; // pivot을 배열의 가장 왼쪽으로 선정
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

	return right; // 오른쪽 부분 배열의 시작 지점을 반환
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
	for (int i = log_2_K(n) - 1; i >= 0; i--) {  // i는 2, 1, 0 이렇게 역순으로 순회한다. 
		int gap = pow(2, log_2_K(n) - i);
		int start = 0;
		int end = gap;
		while (end <= n) { // end가 n을 초과해서 수행해야할 정렬 범위를 넘었을 경우 
			sort(arr + start, arr + end);
			start += gap; // 현재 start지점에서 end를 더해 
			end += gap; // 현재 end 지점에서 i = 2, 1, 0일 때 1, 2, 4를 더한다. 
			if (i == log_2_K(k)) { // 정렬을 진행중인 회원 수가 2의 i승과 일치할 때
				sort(arr + start, arr + end); // break 하기 전 마지막으로 저장된 start, end에 대한 정렬을 수행한다. 
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