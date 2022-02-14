#include<iostream>
using namespace std;

int main() {
	int size;
	cin >> size;
	int* arr = new int[size];

	for (int i = 0; i < size; i++)
		arr[i] = i + 1;
	int K;
	cin >> K;

	cout << "<";
	int now = 0;
	for (int i = 0; i <= size; i++)
	{
		int count = 0;
		for (int j = 0; j <=size*size; j++)
		{
			if (arr[now%size]==(now%size)+1)
			{
				count++;
				if (count == K)
				{
					cout << arr[now % size];
					arr[now % size] = 0;
					break;
				}
			}
			now++;
		}
		if (i <size - 1)
			cout << ", ";
	}
	cout << ">\n";

	return 0;
}