#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int main() 
{

	int n;
	cin >> n;

	vector<pair<int, int>> xy(n);
	int x[20001] = {0,};
	int y[20001];

	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		xy[i].first = x[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> y[i];
		xy[i].second = y[i];
	}


	stack<int>stack;
	
	int max = 0;

	for (int i = 0; i < n; i++)
	{
		stack.push(y[i]);

		//©Л
		for (int j = i + 1; j < n; j++)
		{

			if (y[j] < y[i])
			{ 
				if (stack.size() != 1) {
					stack.pop();
				}
				stack.push(y[j]);
			}
			else { break; }
			

		}
		max=

		//аб
		for (int k = 0; k < i; k++)
		{
			if (y[k] < y[i])
			{
				if (stack.size() != 1) {
					stack.pop();
				}
				stack.push(y[k]);
			}
			else { break; }

		}




	}

}