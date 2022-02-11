// 9012 wmj

#include <iostream>
#include <stack>
using namespace std;

int main() {
	string PS;
	int num;

	cin >> num;

	while (num--) {
		int temp=0;
		cin >> PS;
		stack<char> ps1;

		for (int i = 0; i < PS.length(); i++) {
			if (PS.at(i) == '(') {
				ps1.push(PS.at(i));
				temp = i;
			}
			else {
				if (ps1.empty()) {
					temp = i;
					break;
				}
				else {
					temp = i;
					ps1.pop();
				}
			}
		}
		if (PS.length() % 2 == 1) cout << "NO" << endl;
		else {
			if (ps1.empty() && (temp < (PS.length() - 1))) {
				cout << "NO" << endl;
			}
			else if (!ps1.empty()) cout << "NO" << endl;
			else if (ps1.empty() && (temp = PS.length() - 1)) {
				cout << "YES" << endl;
			}
		}
	}
	return 0;
}