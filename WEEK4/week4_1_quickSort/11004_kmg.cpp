#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

int n;
int k;
vector<int> arr;

auto partition(vector<int>::iterator begin, vector<int>::iterator end) { 
	auto pivot = *begin;
	auto left = begin + 1;
	auto right = end;

	while (true) {
		while (*left <= pivot && distance(left, right) > 0) // 오른쪽으로 이동하며 피벗보다 큰 원소를 찾는다. 
			left++;
		while (*right > pivot && distance(left, right) > 0) // 왼쪽으로 이동하며 피벗보다 작은 원소를 찾는다. 
			right--;

		if (left == right)
			break;
		else
			iter_swap(left, right);
	}

	if (pivot > *right)
		iter_swap(begin, right);

	return right; // 분할 연산에 의해 생성되는 오른쪽 부분 배열의 시작 원소를 가리키는 반복자 반환
}

// partiton() 분할 연산을 재귀적으로 수행하는 quickSort 함수
void quickSort(vector<int>::iterator begin,vector<int>::iterator last) { 
	if (distance(begin, last) >= 1) { // 벡터 내에 하나라도 원소가 있으면 
		auto partition_iter = partition(begin, last);
	
		quickSort(begin, partition_iter - 1); 
		quickSort(partition_iter, last);
	}
}

void sol(vector<int> arr) {
	cout << arr[k - 1] << endl;
}

int main() {
	ios::sync_with_stdio();
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n >> k; 
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	quickSort(arr.begin(), arr.end() -1);

	sol(arr);
}