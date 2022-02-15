#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>S) {
	for (int i = 0; i < S.size(); i++) {
		cout << S[i] << ' ';
	}
	cout << endl;
}

// start�� U �迭�� ������, end�� V �迭�� ������
void merge(vector <int>& S, vector<int>& U, vector<int>& V) {
	//int i = 0, j = 0, k = 0; // ���� U�� ��ġ, V�� ��ġ, S�� ��ġ�� �ش�
	size_t i = 0;
	size_t j = 0;
	while (i < U.size() && j < V.size()) {
		if (U.at(i) < V.at(j)) {
			S.push_back(U.at(i++));
		}
		else {
			S.push_back(V.at(j++));
		}
	}
	while (i < U.size()) {
		// U ���Ϳ� ���Ұ� ������ ��
		S.push_back(U.at(i++));
	}
	while (j < V.size()) {
		S.push_back(V.at(j++));
	}
}

void mergeSort(vector<int>& S) {

	if (S.size() <= 1)
		return;

	auto iter = S.begin() + S.size() / 2;
	
	vector<int> U(S.begin(), iter);
	vector<int> V(iter, S.end());

	mergeSort(U);
	mergeSort(V);

	S.clear();
	merge(S, U, V);

}




int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	mergeSort(arr);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
	
	return 0;
}