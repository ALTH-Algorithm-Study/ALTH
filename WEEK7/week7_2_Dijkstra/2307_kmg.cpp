#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> a, b;

bool cmp(int a, int b) {
    return a > b;
}

void sol() {
    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);
    if (a[0] < b[0]) {
        puts("-1");
        return 0;
    }
    int ans = 0;
    while (b.size() != 0) {
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                if (a[i] >= b[j]) {
                    b.erase(b.begin() + j);
                    break;
                }
            }
        }
        ans++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;
    a.resize(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    cin >> M;
    b.resize(M);
    for (int i = 0; i < M; i++) cin >> b[i];

    sol();

    return 0;
}
