#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int SuffixArray[200001];
int Group[2000001];
int LCP[2000001];
int d;
int length; string s;

bool cmp(int i, int j) {
    //앞에 d 글자 비교
    if (Group[i] != Group[j])
        return Group[i] < Group[j];
    i += d;
    j += d;
    // 뒤에 d 글자 비교
    if (i < length && j < length)
        return Group[i] < Group[j];
    else
        return i > j; // 범위를 벗어난 경우 i가 더 크면 문자열에서는 더 뒤에 있고 짧은 suffix 이므로 더 앞으로 오게 해줌
}

void construct_sa() {
    // 전처리
    for (int i = 0; i < length; i++) {
        SuffixArray[i] = i;
        Group[i] = s[i]; // 첫 문자로 그루핑
    }

    for (d = 1;; d *= 2) {// d는 1부터 
        sort(SuffixArray, SuffixArray + length, cmp); // cmp 비교함수로 정렬

        vector<int> tmp(length, 0);
        for (int i = 0; i < length - 1; i++)
            tmp[i + 1] = tmp[i] + cmp(SuffixArray[i], SuffixArray[i + 1]); // SA[i] 하고 SA[i + 1] 하고 그룹이 나뉘어있나 확인하는 과정
        for (int i = 0; i < length; i++)
            Group[SuffixArray[i]] = tmp[i]; // SA에 업데이트된 값 GROUP에 옮겨닮기
        // 모든 그루핑이 완료되었으면 종료
        if (tmp[length - 1] == length - 1) break;
    }
}

int main()
{
	cin >> length >> s;

    construct_sa();

    for (int str_idx = 0, m = 0; str_idx < length; m = max(m - 1, 0), str_idx++) {
        int sa_idx = Group[str_idx];
        if (sa_idx == length - 1)continue;

        int j = SuffixArray[sa_idx + 1];
        while (s[str_idx + m] == s[j + m])
            m++;

        LCP[sa_idx] = m;
    }

    int max=LCP[0];

    for (int i = 0; i < length-2; i++)
    {
        if (max < LCP[i + 1]) max = LCP[i + 1];
    }

    cout << max << '\n';

    return 0;
}