#include<iostream>
using namespace std;

char Tree[27][2];

void preorder(char data) //전위 순회
{
	if (data == '.')
		return;
	cout << data;
	preorder(Tree[data][0]);
	preorder(Tree[data][1]);
}
void inorder(char data) //중위 순회
{
	if (data == '.')
		return;
	inorder(Tree[data][0]);
	cout << data;
	inorder(Tree[data][1]);
}
void postorder(char data) //후위 순회
{
	if (data == '.')
		return;
	postorder(Tree[data][0]);
	postorder(Tree[data][1]);
	cout << data;
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char data,left, right;
		cin >>data>> left >> right;
		Tree[data][0] = left;
		Tree[data][1] = right;
	}

	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
	cout << '\n';
	return 0;
}

