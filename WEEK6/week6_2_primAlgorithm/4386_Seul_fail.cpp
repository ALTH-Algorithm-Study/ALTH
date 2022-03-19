#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

vector<pair<double, double>> star;
vector<pair<int, double>> star_distance[101];
int visited[101];
double result=0;

double find_distance(double x1, double x2, double y1, double y2)
{
	double dx = pow(x1 - x2,2);
	double dy = pow(y1 - y2,2);
	
	return sqrt(dx + dy);
}

void prim()
{
	priority_queue<pair<int, double>,vector<pair<int,double>>,greater<pair<int,double>>> pq;
	for (int i = 0; i < star_distance[0].size(); i++)
	{
		int j = star_distance[0][i].first;
		double distance = star_distance[0][i].second;
		pq.push({ j,distance });
	}
	visited[0] = true;
	while (!pq.empty())
	{
		int j_now = pq.top().first;
		double distance_now = pq.top().second;
		pq.pop();
		if (!visited[j_now])
		{
			visited[j_now] = true;
			result += distance_now;
			for (int j = 0; j < star_distance[j_now].size(); j++)
			{
				int k = star_distance[j_now][j].first;
				double distance = star_distance[j_now][j].second;
				if(!visited[k]) pq.push({ k,distance });
			}
		}
	}
}

int main()
{
	int n;
	float x, y;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		star.push_back({ x,y });
	}

	for (int i = 0; i < n; i++)
	{
		double x1 = star[i].first;
		double y1 = star[i].second;
		for (int j = i + 1; j < n; j++)
		{
			double x2 = star[j].first;
			double y2 = star[j].second;
			double distance = find_distance(x1, x2, y1, y2);
			star_distance[i].push_back({ j,distance });
			star_distance[j].push_back({ i,distance });
		}
	}

	prim();
	cout << fixed;
	cout.precision(2);
	cout << result << '\n';

	return 0;
}