//����1541 �Ҿ���� ��ȣ

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

        // ���ڰ� �ԷµǸ�
        if (input[i] == '-' || input[i] == '+' || i == input.size()) {
            if (isMinus) {
                // stl stoi�� ����ؼ� ���ڿ��� ������ ��ȯ
                result -= stoi(num);
                num = "";
            }
            else {
                result += stoi(num);
                num = "";
            }
        }
        else { // ���ڰ� �ԷµǸ�
            num += input[i];
        }

        // �Էµ� ���ڰ� ���̳ʽ� ��ȣ�� true�� ��ȯ
        if (input[i] == '-') {
            isMinus = true;
        }
    }

    cout << result;
}