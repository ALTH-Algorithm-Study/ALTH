#include <iostream>
#include <list>
#include <utility>
using namespace std;

int n;
int* arr;

struct Node {
	struct Node* next;
	int data;
};

void sol() {
	list<pair> a; 
	for (int i = 0; i < n; i++) {
		a.push_back(arr[i]);
	}

	list<int>::iterator iter = a.begin();
	list<int>::iterator temp;
	int value;
	while (!a.empty()){
		int key = 
		int key = *iter;
		cout << 
		if (value >= 0) {
			for (int i = 0; i < value; i++) {
				iter++;
			}
		}
		else {
			for (int i = 0; i > value; i--) {
				iter--;
			}
		}
		cout << *iter << endl;
		temp = iter;
		a.erase(temp);
	}
}



void input() {
	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

int main() {
	input();
	sol();
}