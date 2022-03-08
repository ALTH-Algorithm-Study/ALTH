#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

int main()
{
	int num=0,order=0,result=0; // order�� ���� �ڸ��� �־��ַ��� ����, result�� ������ , num�� ������ ������ ������ ���� ����Ϸ��� ����
	stack<int>s; // - ������ �Ϸ��� ��� ���� ����
	string formula; // ����� �Է�
	cin >> formula;
	// �ڿ������� �����ؼ� -������ ������ ������ + �����ڸ� �̸� ������༭ �ִ��� ���� ������� �ּڰ��� ���� �� ����
	for (int i = formula.length() - 1; i >= 0; i--) 
	{
		if (formula[i] == '+') order = 0; // +�� ���� ��� �̾ �����ָ� �ǹǷ� �ڸ����� �ʱ�ȭ ����
		else if (formula[i] == '-') // -�� ���� ��� �ڿ��� ���� ���� stack�� �־��ְ� num�� order 0���� �ʱ�ȭ
		{
			s.push(num);
			num = 0; order = 0;
		}

		else
		{
			num += ((int)formula[i]-48) * pow(10, order); 
			// formula�� string���̹Ƿ� 48�� ���༭ ���ڷ� ���� + pow�Լ��� 55=50+5 ���·� ������ ���������� num�� ��� ������
			order++; // �ڸ��� ����
			if (i == 0) //�������� ��� ���ڸ� result�� ����
			{
				result = num;
			}
		}
	}
	// stack�� ���� ������ �ϳ��ϳ��� ���ְ� ��������
	for (int i = s.size() - 1; i >= 0; i--)
	{
		result -= s.top(); 
		s.pop();
	}

	cout << result << '\n';
	
	return 0;
}