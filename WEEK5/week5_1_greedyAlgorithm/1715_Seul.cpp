#include<iostream>
#include<queue>
using namespace std;

int main()
{
	// 우선 순위 큐 선언 방식 => priority_queue<자료형,구현체,비교연산자>
	// greater<int>를 비교 연산자에 넣어주면 내림차순으로 정렬
	priority_queue<int,vector<int>,greater<int>> card;
	int N,num;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		card.push(num);
	}

	int first, second, result=0;
	// 내림차순으로 정렬된 우선순위 큐에서 가장 작은 두 수 삭제해서 더해주고 다시 넣는 과정을 반복
	// 넣을때마다 내림차순으로 정렬 되므로 계속 작은 두 수끼리 더해짐
	// 한 개만 남을때까지 과정을 반복
	// 한묶음 밖에 없을때는 섞을 필요가 없기 때문에 0번임
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