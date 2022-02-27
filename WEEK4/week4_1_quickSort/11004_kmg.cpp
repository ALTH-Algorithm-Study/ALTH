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
		while (*left <= pivot && distance(left, right) > 0) // ���������� �̵��ϸ� �ǹ����� ū ���Ҹ� ã�´�. 
			left++;
		while (*right > pivot && distance(left, right) > 0) // �������� �̵��ϸ� �ǹ����� ���� ���Ҹ� ã�´�. 
			right--;

		if (left == right)
			break;
		else
			iter_swap(left, right);
	}

	if (pivot > *right)
		iter_swap(begin, right);

	return right; // ���� ���꿡 ���� �����Ǵ� ������ �κ� �迭�� ���� ���Ҹ� ����Ű�� �ݺ��� ��ȯ
}

// partiton() ���� ������ ��������� �����ϴ� quickSort �Լ�
void quickSort(vector<int>::iterator begin,vector<int>::iterator last) { 
	if (distance(begin, last) >= 1) { // ���� ���� �ϳ��� ���Ұ� ������ 
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