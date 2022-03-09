//백준1541 잃어버린 괄호

#include <iostream>
#include <string>
using namespace std;

int main() {
    string input; 
    cin >> input;

    int result = 0;
    string num;
    bool isMinus = false;

    for (int i = 0; i <= input.size(); i++) {

        // 문자가 입력되면
        if (input[i] == '-' || input[i] == '+' || i == input.size()) {
            if (isMinus) {
                // stl stoi를 사용해서 문자열을 정수로 변환
                result -= stoi(num);
                num = "";
            }
            else {
                result += stoi(num);
                num = "";
            }
        }
        else { // 숫자가 입력되면
            num += input[i];
        }

        // 입력된 문자가 마이너스 부호면 true로 변환
        if (input[i] == '-') {
            isMinus = true;
        }
    }

    cout << result;
}