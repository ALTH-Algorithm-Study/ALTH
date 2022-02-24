#include <vector>
#include <iostream>
using namespace std;

const int mod = 1e5 + 3;

int Mod(long long n) {
    if (n >= 0) return n % mod;
    else return ((-n / mod + 1) * mod + n) % mod;
}

int main() {
    int L; string s;
    cin >> L >> s;
    int l = 0, r = L;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        long long pow = 1;
        int hash = 0;
        vector<int> pos[mod];
        bool found = false;

        for (int i = 0; i + mid < L; i++) {
            // i = 0�϶� ���ڿ��� ���̸�ŭ �ݺ��Ͽ� �ؽ����� ���Ѵ�
            if (i == 0) {
                for (int j = 0; j < mid; j++) {
                    hash = Mod(hash + s[mid - 1 - j] * pow);
                    if (j + 1 < mid) pow = Mod(pow << 1);
                }
            }
            else {
                // ������ �ؽ����� �̿��Ͽ� ���ο� �ؽ����� ���Ѵ�
                hash = Mod(2 * (hash - s[i - 1] * pow) + s[i + mid - 1]);
            }
            //�ؽ� �浹�� �Ͼ�� ���
            if (!pos[hash].empty()) {
                for (int p : pos[hash]) {
                    bool flag = true;
                    // �ؽ� �浹�� �Ͼ �� ���ڿ��� �������� Ȯ��
                    for (int j = 0; j < mid; j++) {
                        if (s[i + j] != s[p + j]) {
                            flag = false;
                            break;
                        }
                    }
                    // �� ���ڿ��� ������ ���
                    if (flag) {
                        found = true;
                        break;
                    }
                }
            }
            if (found) break; // �� ���ڿ��� ������ ��� break
            else pos[hash].push_back(i);
        }
        if (found) l = mid;
        else r = mid;
    }
    cout << l << endl;
}