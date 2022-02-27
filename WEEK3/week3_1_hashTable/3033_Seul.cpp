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
    //�տ� d ���� ��
    if (Group[i] != Group[j])
        return Group[i] < Group[j];
    i += d;
    j += d;
    // �ڿ� d ���� ��
    if (i < length && j < length)
        return Group[i] < Group[j];
    else
        return i > j; // ������ ��� ��� i�� �� ũ�� ���ڿ������� �� �ڿ� �ְ� ª�� suffix �̹Ƿ� �� ������ ���� ����
}

void construct_sa() {
    // ��ó��
    for (int i = 0; i < length; i++) {
        SuffixArray[i] = i;
        Group[i] = s[i]; // ù ���ڷ� �׷���
    }

    for (d = 1;; d *= 2) {// d�� 1���� 
        sort(SuffixArray, SuffixArray + length, cmp); // cmp ���Լ��� ����

        vector<int> tmp(length, 0);
        for (int i = 0; i < length - 1; i++)
            tmp[i + 1] = tmp[i] + cmp(SuffixArray[i], SuffixArray[i + 1]); // SA[i] �ϰ� SA[i + 1] �ϰ� �׷��� �������ֳ� Ȯ���ϴ� ����
        for (int i = 0; i < length; i++)
            Group[SuffixArray[i]] = tmp[i]; // SA�� ������Ʈ�� �� GROUP�� �Űܴ��
        // ��� �׷����� �Ϸ�Ǿ����� ����
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