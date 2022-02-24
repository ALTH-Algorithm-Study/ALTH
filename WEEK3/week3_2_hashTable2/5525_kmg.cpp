#include <iostream>
using namespace std;

int n; // Pn에서 O의 개수 
int m;
string s;
int cnt = 0;
int ans = 0; // 포함되어있는 만큼의 개수 

void sol() {
    for (int i = 1; i < m - 1; i++) { // OOIOIOIOIIOII
        if (s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I') {
            cnt++;
            if (cnt == n) { // 패턴을 만족할 경우
                cnt--; // 반복해서 IOI가 나왔을 경우를 대비해 추가
                ans++;
            }
            i++; // 뒤로 두칸 이동하기 위해 인덱스 + 1
        }
        else {
            cnt = 0;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s;

    sol();

    return 0;
}