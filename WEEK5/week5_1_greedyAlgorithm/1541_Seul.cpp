#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

int main()
{
	int num=0,order=0,result=0; // order은 숫자 자리수 넣어주려는 변수, result는 최종값 , num은 연산자 나오기 전까지 숫자 계산하려는 변수
	stack<int>s; // - 연산을 하려고 모아 놓는 스택
	string formula; // 연산식 입력
	cin >> formula;
	// 뒤에서부터 진행해서 -연산자 나오기 전까지 + 연산자를 미리 계산해줘서 최댓값을 빼야 연산식의 최솟값을 얻을 수 있음
	for (int i = formula.length() - 1; i >= 0; i--) 
	{
		if (formula[i] == '+') order = 0; // +가 나올 경우 이어서 더해주면 되므로 자리수만 초기화 해줌
		else if (formula[i] == '-') // -가 나올 경우 뒤에서 계산된 수를 stack에 넣어주고 num과 order 0으로 초기화
		{
			s.push(num);
			num = 0; order = 0;
		}

		else
		{
			num += ((int)formula[i]-48) * pow(10, order); 
			// formula가 string형이므로 48을 빼줘서 숫자로 만듦 + pow함수로 55=50+5 형태로 연산자 나오기전에 num에 계속 더해줌
			order++; // 자릿수 증가
			if (i == 0) //마지막일 경우 숫자를 result에 저장
			{
				result = num;
			}
		}
	}
	// stack에 쌓인 수들을 하나하나씩 빼주고 삭제해줌
	for (int i = s.size() - 1; i >= 0; i--)
	{
		result -= s.top(); 
		s.pop();
	}

	cout << result << '\n';
	
	return 0;
}