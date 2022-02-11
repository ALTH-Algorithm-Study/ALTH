// 10866
// deque

#include <iostream>
#include <deque>
using namespace std;

int main() {
	int N; // ¸í·É ¼ö
	cin >> N;
	deque<int> deq;

	string orderM;
	int element = 0;

	while (N--) {
		cin >> orderM;
		if (orderM == "push_back") {
			cin >> element;
			deq.push_back(element);
		}
		else if (orderM == "push_front") {
			cin >> element;
			deq.push_front(element);
		}
		else if (orderM == "pop_front") {
			if (deq.empty()) cout << "-1" << endl;
			else {
				cout << deq.front() << endl;
				deq.pop_front();
			}
		}
		else if (orderM == "pop_back") {
			if (deq.empty()) cout << "-1" << endl;
			else {
				cout << deq.back() << endl;
				deq.pop_back();
			}
		}
		else if (orderM == "size") cout << deq.size() << endl;
		else if (orderM == "empty") {
			if (deq.empty()) cout << "1" << endl;
			else cout << "0" << endl;
		}
		else if (orderM == "front") {
			if (deq.empty()) cout << "-1" << endl;
			else cout << deq.front() << endl;
		}
		else if (orderM == "back") {
			if (deq.empty()) cout << "-1" << endl;
			else cout << deq.back() << endl;
		}
		else {
			cout << "error : quit" << endl;
			exit(EXIT_FAILURE);
		}
	}
	return 0;
}