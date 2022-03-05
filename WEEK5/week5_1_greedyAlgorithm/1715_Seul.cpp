#include<iostream>
#include<queue>
using namespace std;

int main()
{
	// �켱 ���� ť ���� ��� => priority_queue<�ڷ���,����ü,�񱳿�����>
	// greater<int>�� �� �����ڿ� �־��ָ� ������������ ����
	priority_queue<int,vector<int>,greater<int>> card;
	int N,num;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		card.push(num);
	}

	int first, second, result=0;
	// ������������ ���ĵ� �켱���� ť���� ���� ���� �� �� �����ؼ� �����ְ� �ٽ� �ִ� ������ �ݺ�
	// ���������� ������������ ���� �ǹǷ� ��� ���� �� ������ ������
	// �� ���� ���������� ������ �ݺ�
	// �ѹ��� �ۿ� �������� ���� �ʿ䰡 ���� ������ 0����
	while(card.size()!=1) 
	{
		first = card.top();
		card.pop();
		second = card.top();
		card.pop();
		result += first + second;
		card.push(first + second);
	}

	cout << result << '\n';

	return 0;
}