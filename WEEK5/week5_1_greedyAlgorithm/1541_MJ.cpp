// 잃어버린 괄호(1541)
// 03.06
// 성공

#include <iostream>
using namespace std;
#define endl "\n"
#include <vector>
#include <string>

string equation;
vector<string> ope;

// 원래는 sep함수랑 sub함수로 풀려고 했는데 생각해보니 왜 벡터로 나누고 있었나 깨우쳐서
// sub2 함수를 만들었답니다?
// 근데 원래 함수로도 예제는 다 잘 나오는데 왜인지는 모르겠지만 틀렸습니다 가 뜨더라구용

void sep(string equ) { // 숫자, 연산자 벡터로 나눠주는 함수였어요
	string str = "";
	int start = -1;
	int end = 0;
	for (int i = 0; i < equ.length(); i++) {
		if (equ[i] >= 48 && equ[i] <= 57) {
			if (start == -1) {
				start = i;
			}
			else {
				if (equ[i + 1] == 43 || equ[i + 1] == 45 || (i == equ.length() - 1)) {
					end = i;
					ope.push_back(equ.substr(start, end - start + 1));
				}
			}
		}
		else {
			start = -1;
			if (equ[i] == '-') ope.push_back("-");
			else ope.push_back("+");	
		}
	}
}

int sub(string equ) {
	sep(equ);
	int answer = 0;
	int temp = 0;
	bool flag = false;
	for (int i = 0; i < ope.size(); i++) {
		if (ope[i] == "-") {
			flag = true;
			answer -= temp;
			temp = 0;
		}
		else {
			if (ope[i] == "+") continue;
			if (flag) {
				temp += stoi(ope[i]);
			}
			else {
				answer += stoi(ope[i]);
			}
			if (i == ope.size() - 1) answer -= temp;
		}
	}
	return answer;
}

int sub2(string equ) {
	bool flag = false; // -이면 true
	int answer = 0;
	string temp = ""; // -일때 -뒤의 숫자들을 넣어주는 변수
	for (int i = 0; i < equ.length(); i++) {
		if (equ[i] == '-' || equ[i] == '+') {
			if (flag) { // -면
				answer -= stoi(temp); // 모아둔 숫자 다 빼주기
				temp = "";
			}
			else {
				answer += stoi(temp); // 모아둔 숫자 더해주기 (처음 - 나오기 전 숫자)
				temp = "";
			}
		}
		else {
			temp += equ[i];
			if (i == equ.length() - 1) {
				if (flag) answer -= stoi(temp);
				else answer += stoi(temp);
			}
		}

		if (equ[i] == '-') flag = true; // 자리를 바꾼 이유는 이 코드에선 처음 -가 나왔을 때 answer -= stoi(temp)가 되기 때문 
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	cin >> equation;
	cout << sub2(equation);
	
	return 0;
}

// 여기에서 깨달은 점 stoi는 숫자가 아닌 다른 문자가 있으면 오류를 발생한다.
// 내가 모르고 +를 stoi에 넣었는데 예외처리가 안됐다는 오류를 발견할 수 있었다.ㄴ