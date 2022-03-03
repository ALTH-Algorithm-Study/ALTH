#include<iostream>
using namespace std;

int case1[100002]; //현재 상태(0번 스위치 안누를때)
int case2[100002]; //현재 상태(0번 스위치 누를때)
int want[100002]; //원하는 상태
int N;
int result1=0, result2=0;
// 0번 스위치을 누르는 것과 안누르는 것 구분 했기 때문에 0번 전구 상태를 바꿀 수 있는 것은 1번 스위치 밖에 없음
// 이와 같은 방식으로 판단하면 i번째 전구 상태를 바꿀 수 있는건 i+1번째 스위치만 있다고 생각
void compare1(int k) // 0번 스위치를 안누를경우 비교하는 함수
{
	if (case1[k-1] != want[k-1]) // k-1번째 스위치들이 같은지 판단
	{
		if (k == N-1)//마지막 스위치일 경우 N,N-1만 바뀜
		{
			case1[k - 1]++; case1[k]++;
			case1[k - 1] %= 2; case1[k] %= 2;
			result1++;
		}
		else//마지막 스위치가 아닐 경우 k-1,k,k+1번째 가 바뀜
		{
			case1[k - 1]++; case1[k]++; case1[k + 1]++;
			case1[k - 1] %= 2; case1[k] %= 2; case1[k + 1] %= 2;
			result1++;
		}
	}
}

void compare2(int k) // 0번 스위치를 누를경우 비교하는 함수
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
	for (int i = 0; i < N; i++) // case1은 0번 스위치를 안 누를때 case2는 0번 스위치를 눌렀을때
	{
		cin >> s;
		case1[i] = (int)s - 48;
		case2[i] = (int)s-48;
	}

	for (int i = 0; i < N; i++) // 원하고자 하는 상태 입력
	{
		cin >> s;
		want[i] = (int)s-48;
	}



	case2[0]++; case2[1]++; //0번 스위치를 누르면 0,1번 전구가 바뀜
	case2[0] %= 2; case2[1] %= 2; 
	result2++; // 스위치 누른 횟수
	for (int i = 1; i < N; i++)
	{
		compare1(i); // 0번 스위치를 안눌렀을때
		compare2(i); // 0번 스위치를 눌렀을때
	}

	bool p1=true, p2=true; // case1,case2가 want와 같은지를 판별

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
	if (p1==true && p2 == true)//p1,p2로 want와 일치한다고 할때 최솟값을 찾아줌
	{
		if (result1 >= result2) min = result2;
		else min = result1;
		cout << min;
	}
	else if (p1 == false && p2 == true) cout << result2; // p2만 want와 일치 할때 result2가 최솟값
	else if (p1 == true && p2 == false) cout << result1; // p1만 want와 일치 할때 result1이 최솟값
	else cout << "-1"; // 다 아닐 경우 -1 출력

	return 0;
}