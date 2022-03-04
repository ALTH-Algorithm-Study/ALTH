#include<iostream>
using namespace std;

int case1[100002]; //���� ����(0�� ����ġ �ȴ�����)
int case2[100002]; //���� ����(0�� ����ġ ������)
int want[100002]; //���ϴ� ����
int N;
int result1=0, result2=0;
// 0�� ����ġ�� ������ �Ͱ� �ȴ����� �� ���� �߱� ������ 0�� ���� ���¸� �ٲ� �� �ִ� ���� 1�� ����ġ �ۿ� ����
// �̿� ���� ������� �Ǵ��ϸ� i��° ���� ���¸� �ٲ� �� �ִ°� i+1��° ����ġ�� �ִٰ� ����
void compare1(int k) // 0�� ����ġ�� �ȴ������ ���ϴ� �Լ�
{
	if (case1[k-1] != want[k-1]) // k-1��° ����ġ���� ������ �Ǵ�
	{
		if (k == N-1)//������ ����ġ�� ��� N,N-1�� �ٲ�
		{
			case1[k - 1]++; case1[k]++;
			case1[k - 1] %= 2; case1[k] %= 2;
			result1++;
		}
		else//������ ����ġ�� �ƴ� ��� k-1,k,k+1��° �� �ٲ�
		{
			case1[k - 1]++; case1[k]++; case1[k + 1]++;
			case1[k - 1] %= 2; case1[k] %= 2; case1[k + 1] %= 2;
			result1++;
		}
	}
}

void compare2(int k) // 0�� ����ġ�� ������� ���ϴ� �Լ�
{
	if (case2[k-1] != want[k-1])
	{
		if (k == N-1)
		{
			case2[k - 1]++; case2[k]++;
			case2[k - 1] %= 2; case2[k] %= 2;
			result2++;
		}
		else
		{
			case2[k - 1]++; case2[k]++; case2[k + 1]++;
			case2[k - 1] %= 2; case2[k] %= 2; case2[k + 1] %= 2;
			result2++;
		}
	}
}


int main()
{
	
	cin >> N;

	char s;;
	for (int i = 0; i < N; i++) // case1�� 0�� ����ġ�� �� ������ case2�� 0�� ����ġ�� ��������
	{
		cin >> s;
		case1[i] = (int)s - 48;
		case2[i] = (int)s-48;
	}

	for (int i = 0; i < N; i++) // ���ϰ��� �ϴ� ���� �Է�
	{
		cin >> s;
		want[i] = (int)s-48;
	}



	case2[0]++; case2[1]++; //0�� ����ġ�� ������ 0,1�� ������ �ٲ�
	case2[0] %= 2; case2[1] %= 2; 
	result2++; // ����ġ ���� Ƚ��
	for (int i = 1; i < N; i++)
	{
		compare1(i); // 0�� ����ġ�� �ȴ�������
		compare2(i); // 0�� ����ġ�� ��������
	}

	bool p1=true, p2=true; // case1,case2�� want�� �������� �Ǻ�

	for (int i = 0; i < N; i++)
	{
		if (case1[i] != want[i] && case2[i] != want[i])
		{
			p1 = false, p2 = false;
		}
		else if (case1[i] != want[i] && case2[i] == want[i])
		{
			p1 = false;
		}
		else if (case1[i] == want[i] && case2[i] != want[i])
		{
			p2 = false;
		}
	}

	int min;
	if (p1==true && p2 == true)//p1,p2�� want�� ��ġ�Ѵٰ� �Ҷ� �ּڰ��� ã����
	{
		if (result1 >= result2) min = result2;
		else min = result1;
		cout << min;
	}
	else if (p1 == false && p2 == true) cout << result2; // p2�� want�� ��ġ �Ҷ� result2�� �ּڰ�
	else if (p1 == true && p2 == false) cout << result1; // p1�� want�� ��ġ �Ҷ� result1�� �ּڰ�
	else cout << "-1"; // �� �ƴ� ��� -1 ���

	return 0;
}